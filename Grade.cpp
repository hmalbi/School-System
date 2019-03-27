#include "Grade.h"


Grade::Grade()
{
	work_grad = 0;
	midterm_grade = 0;
	final_grade = 0;
	total_grade = 0;
}

Grade::Grade(string w, string m, string f,string code)
{
	work_grad = atoi(w.c_str());
	midterm_grade = atoi(m.c_str());
	final_grade = atoi(f.c_str());
	cours_code = (Cours)atoi(code.c_str());
}

Grade::Grade(string w, string m, string f, string code,Student s)
{
	work_grad = atoi(w.c_str());
	midterm_grade = atoi(m.c_str());
	final_grade = atoi(f.c_str());
	cours_code = (Cours)atoi(code.c_str());
	this->student = s;
}

void Grade::setworkgrad(string workgrad){
	this->work_grad = atoi(workgrad.c_str());
}

int Grade::getworkgrad(){
	return work_grad;
}

void Grade::setmidterm(string midterm){
	this->midterm_grade = atoi(midterm.c_str());
}

int Grade::getmidterm(){
	return midterm_grade;
}

void Grade::setfinal(string final){
	this->final_grade = atoi(final.c_str());
}

int Grade::getfinal(){
	return final_grade;
}

int Grade::computtotal(){
	//result = workGrade + midtermGrade + QuizGrade;
	total_grade = work_grad + midterm_grade + final_grade;
	return total_grade;
}

char Grade::t2der_grad(int total){
	if (total >= 90 && total <= 100)
		return 'A';
	else if (total >= 70 && total < 90)
		return 'B';
	else if (total >= 50 && total < 70)
		return 'c';
	else
		return 'F';
		
}

int Grade::get_total_grade(){
	return total_grade;
}

void Grade::set_cours_code(string code){
	this->cours_code = (Cours)atoi(code.c_str());
}
int Grade::get_cours_code(){
	return cours_code;
}

int Grade::see_grade(int student_id, int cours_code, Grade *g){
	File <Grade> f;
	string result,id;
	ostringstream convert;
	convert << cours_code;
	result = convert.str();
	ostringstream conver;
	conver << student_id;
	id = conver.str();
	return f.see_grad("Grade.bin", result,id,g);
}
Grade Grade::operator+ (Grade g){
	Grade result;
	result.total_grade = this->total_grade + g.total_grade;
	return result;
}

void Grade::operator= (Grade g){
	this->total_grade = g.total_grade;
}

Grade& Grade::operator+= (Grade g){
	this->total_grade += g.total_grade;
	return *this;
}

Grade::~Grade()
{
}
