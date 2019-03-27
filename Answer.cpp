#include "Answer.h"


Answer::Answer()
{
	answer = " ";
}

Answer::Answer(string d){
	answer = d;
}

string Answer::get_answer(){
	return this->answer;
}

void Answer::set_answer(string answer){
	this->answer = answer;
}

Answer::~Answer()
{

}

