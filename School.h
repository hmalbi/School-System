#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include"Admin.h"
#include "Student.h"
#include"Teacher.h"
using namespace std;
#define SIZE 100

class School
{
private:
	string fname;
	string lname;
public:
	Admin *admin = new Admin();
	Student *student = new Student();
	Teacher *teacher = new Teacher();
	School();
	School(string, string);
	string getfname();
	string getlname();
	//int check_user(int);
	int check_student(string);
	int check_teacher(string);
	//int login(string,string,int);//compare id and password then open the file
	~School();
};

