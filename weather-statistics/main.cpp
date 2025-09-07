//
// Jose Garcia
// 9/7/25
// Weather Statistics Programming Project
// COSC 2030
//

#include <iostream>
using namespace std;

// Declare the WeatherData structure
struct WeatherData 
{
    double rain;  // Total rainfall
    double high; // High temperature
    double low; // low temperature
    double averageTemp; // Average Temprature 
};

// Function prototypes
void getMonthData(WeatherData &);
double totalRain(WeatherData[],int);
double averageMonthlyRainfall(WeatherData[], int);
double averageAverageTemp (WeatherData[], int);
double highestTemp(WeatherData[], int, int &);
double lowestTemp(WeatherData[], int, int &);

int main()

{
    // Constant for the number of months
    const int NUM_MONTHS = 12;

    // Create array of WeatherData structures.
    WeatherData year[NUM_MONTHS];

    int highestMonth; // Month with highest temp
    int lowestMonth; // Month with lowest temp

    // Get the weather data for each month
    cout << "Enter the Following information:\n";
    for (int index = 0; index < NUM_MONTHS; index++)
    {
        // Get the rainfall.
        cout << "Month " << (index + 1) << endl;
        getMonthData (year[index]);
    }

    

    // Display total rainfall
    cout << "\nTotal Rainfall: "
         << totalRain (year, NUM_MONTHS) << endl;
    
    // Display average monthly rain
    cout << "Average Monthly Rainfall: "
         << averageMonthlyRainfall(year, NUM_MONTHS)
         << endl;

    // Display average of monthly average temps
    cout << "Average Monthly Average Temperature: "
         << averageAverageTemp(year, NUM_MONTHS)
         << endl;

    // Display highest temp and month it occured in
    double highest = highestTemp(year, NUM_MONTHS, highestMonth);
    cout << "Highest Temperature: " << highest;
    cout << " (Month " << highestMonth << ")\n";

    // Display lowest temp and the month it occured in
    double lowest = lowestTemp(year, NUM_MONTHS, lowestMonth);
    cout << "Lowest Temperature: " << lowest;
    cout << " (Month " << lowestMonth << ")\n\n";
    
    return 0;
}  

/* getMonthData function accepts a weatherData
variable by reference. Prompts user for weather
data and stores input in the argument. */

void getMonthData (WeatherData &data)
{
    // Get total rainfall for month
    cout << "\tTotal Rainfall: ";
    cin  >> data.rain;

    // Get highest temp
    cout << "\tHigh Temperature: ";
    cin  >> data.high;

    // Validate the high temp
    while (data.high < -100 || data.high > 140)
    {
        cout << "ERROR: Temperature must be in the range "
             << "of -100 through 140.\n";
        cout << "\tHigh Temperature: ";
        cin  >> data.high;
    }

    //Get low temperature
    cout << "\tLow Temperature: ";
    cin  >> data.low;

    // Validate the low temp
    while (data.low < -100 || data.low > 140)
    {
        cout << "ERROR: Temperature must be in the range "
             << "of -100 through 140.\n";
        cout << "\tLow Temperature: ";
        cin >> data.low;
    }

    // Calc average temp
    data.averageTemp = (data.high + data.low) / 2.0;
}

/* The totalRain function accepts an array of WeatherData
structures and returns the total of all elements
rain members */

double totalRain (WeatherData data[], int size)
{
    double totalRain = 0; // Accumulator

    // Get the total of the rain members
    for (int index = 0; index < size; index++)
        totalRain += data[index].rain;

    // Retunr the total
    return totalRain;
}

/* The averageMonthlyRainfall function accepts an array
of WeatherData structures and returns the average monthly rainfall */

double averageMonthlyRainfall (WeatherData data[], int size)
{
    /* The average is the total amount of rain divided
    by the number of months */
    return totalRain(data, size) / size;
}

/* The averageAverageTemp fucntion accepts an array of
weatherdata structures and returns the average of all
the monthly average temps */

double averageAverageTemp (WeatherData data[], int size)
{
    /* calc the average monthly average temp */
    double aveTotal = 0; // Accumulator for average temps
    double aveAve; // Average of the averages

    // Get the total of the average temps
    for (int index = 0; index < size; index++)
    aveTotal += data[index].averageTemp;

    // Calc the average of the average temp
    aveAve = aveTotal / size;

    // Return the average of the averages
    return aveAve;
}

// The highestemp fucntion accepts:
// (1) a WeatherData array 
// (2) an int indicating the size of the array
// (3) an int by reference to hold the month with the highest temp

double highestTemp (WeatherData data[], int size, int &month)
{
    // set the highest to the first month
    double highest = data[0].high;
    month = 1;

    // step through the array looking for the highest
    for (int index=1; index < size; index++)
    {
        if (data[index].high > highest)
        {
            // Save this value. it is the highest so far
            highest = data[index].high;

            // Save this months number. (1 = Janurary, etc.) 
            month = index + 1;      
        }
    }

    // return the highest temp
    return highest;
}

// the lowest fucntion accepts 
// (1) a WeatherData array
// (2) an int indicating the size of the array
// (3) an int by reference to hold the month with
// lowest temp
// the function returns the lowest temp and sets the 
// month oarameter to the number of the month with the lowest temp

double lowestTemp (WeatherData data[], int size, int &month)
{
    // Set the lowest to the first month
    double lowest = data[0].low;
    month = 1;

    // Step through the array looking for the lowest
    for (int index = 1; index < size; index++)
    {
        if (data[index].low < lowest)
        {
            // save this value. it is the lowest so far
            lowest = data[index].low;
            
            //save this months number (1 = Janurary, etc.)
            month = index + 1;
        }
    }

    //Return the lowest temp
    return lowest;
}