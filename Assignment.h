#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include"Cours_Enum.h"
#include "Date.h"
#include "Answer.h"
#include "Question.h"
#include "File.h"
#define Max 5
using namespace std;

class Assignment : public Date//, public File
{
private:
	Cours cours;
public:
	
	Question questions[Max];
	Answer answer[Max];
	Assignment();
	Assignment(string, string, string, string, string,string, Question *);
	void set_cours_code(string);
	int get_cours_code();
	//void check_answer(string);//Answer of student and compare it with the true answer
	//void split_assignment(Assignment *);//assosiation with person
	bool deadline();
	~Assignment();
};

