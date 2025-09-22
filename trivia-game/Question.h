#ifndef QUESTION_H
#define QUESTION_H

#include <string>
using namespace std;

class Question
{
    private:
        string questionText;
        string answer1;
        string answer2;
        string answer3;
        string answer4;
        int correctAnswer; // 1-4

    public:
        // constructors
        Question(string q, string a1, string a2, string a3, string a4, int correct);
        Question(); // defualt

        // Mutators
        void setQuestion(string q);
        void setAnswers(string a1, string a2, string a3, string a4);
        void setCorrectAnswer(int correct);

        // Accesors
        string getQuestion() const;
        string getAnswer1() const;
        string getAnswer2() const;
        string getAnswer3() const;
        string getAnswer4() const;
        int getCorrectAnswer() const;
};

#endif