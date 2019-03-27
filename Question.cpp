#include "Question.h"


Question::Question()
{
	question = " ";
	question_code = 1;
}

Question::Question(string question, string qnum){
	this->question = question;
	this->question_code = atoi(qnum.c_str());
}

Question::Question(string question){
	this->question = question;
}


void Question::setquestion(string question){
	this->question = question;
}

string Question::getquestion(){
	return question;
}

void Question::set_question_code(string qnum){
	this->question_code = atoi(qnum.c_str());
}

int Question::get_question_code(){
	return question_code;
}

Question::~Question()
{
}
