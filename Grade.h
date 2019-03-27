#pragma once
#include "Resours.h"
#include "File.h"
#include "Student.h"
#include "Cours_Enum.h"
class Grade : public Resours
{
private:
	int work_grad;
	int midterm_grade;
	int final_grade;
	int total_grade;
	Cours cours_code;
public:
	Student student;
	Grade();
	Grade(string, string, string,string);
	Grade(string, string, string, string,Student);
	void setworkgrad(string);
	int getworkgrad();
	void setmidterm(string);
	int getmidterm();
	void setfinal(string);
	int getfinal();
	void set_cours_code(string);
	int get_cours_code();
	int get_total_grade();
	int computtotal();
	char t2der_grad(int);//A or B or C and so on
	int see_grade(int, int, Grade *);
	Grade operator+ (Grade);
	void operator= (Grade);
	Grade& operator +=(Grade);
	~Grade();
};


