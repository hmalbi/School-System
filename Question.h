#pragma once
#include "Answer.h"
using namespace std;
class Question
{
private:
	string question;
	int question_code;
public:
	Answer answer;
	Question();
	Question(string, string);//for assignment question
	Question(string);//for post question
	void setquestion(string);
	string getquestion();
	void set_question_code(string);
	int get_question_code();
	~Question();
};
