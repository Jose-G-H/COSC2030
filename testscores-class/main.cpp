//
// Jose Garcia
// 10/19/25
// TestScores Class Programming Project
// COSC 2030
//

#include <iostream>
using namespace std;

class TestScores
{
private:
    double *scores;
    int numScores;

    // member function validates scores
    void checkScores()
    {
        for (int i = 0; i < numScores; i++)
        {
            if (scores[i] < 0 || scores[i] > 100)
                throw InvalidScore();
        }
    }
public:
    // exception class
    class InvalidScore
    {};

    // constructor
    TestScores(double s[], int n)
    {
        numScores = n;
        scores = new double[numScores];
        for (int i = 0; i < numScores; i++)
            scores[i] = s[i];

            checkScores();
    }

    // destructor
    ~TestScores()
    {
        delete [] scores;
    }

    // function calculates and returns average 
    double getAverage() const
    {
        double total = 0.0;
        for (int i = 0; i < numScores; i++)
            total += scores[i];
        return total/numScores;
    }
};

// function prototype
void testArray(double[], int);

int main()
{
    const int SIZE1 = 5;
    double goodScores[SIZE1] = {85, 90, 78, 92, 88};

    const int SIZE2 = 5;
    double badScores[SIZE2] = {85, -5, 78, 101, 90};

    cout << "Testing Valid scores...\n";
    testArray(goodScores, SIZE1);

    cout << "\nTesting invalid scores...\n";
    testArray(badScores, SIZE2);

    return 0;
}

void testArray(double s[], int n)
{
    try
    {
        TestScores test(s, n);
        cout << "Average score: " << test.getAverage() << endl;
    }
    catch (TestScores::InvalidScore)
    {
        cout << "Error: Invalid test score detected.\n";
    }
}