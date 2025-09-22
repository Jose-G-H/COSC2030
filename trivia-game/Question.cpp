#include "Question.h"

// Constructor with arguments
Question::Question(string q, string a1, string a2, string a3, string a4, int correct)
{
    questionText = q;
    answer1 = a1;
    answer2 = a2;
    answer3 = a3;
    answer4 = a4;
    correctAnswer = correct;
}

// Default constructor 
Question::Question()
{
    questionText = "";
    answer1 = "";
    answer2 = "";
    answer3 = "";
    answer4 = "";
    correctAnswer = 0;
}

// Mutators
void Question::setQuestion(string q) { questionText = q; }
void Question::setAnswers(string a1, string a2, string a3, string a4)
{
    answer1 = a1;
    answer2 = a2;
    answer3 = a3;
    answer4 = a4;
}
void Question::setCorrectAnswer(int correct) { correctAnswer = correct; }

// Accesors
string Question::getQuestion() const { return questionText; }
string Question::getAnswer1() const { return answer1; }
string Question::getAnswer2() const { return answer2; }
string Question::getAnswer3() const { return answer3; }
string Question::getAnswer4() const { return answer4; }
int Question::getCorrectAnswer() const { return correctAnswer; }