#pragma once
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include <fstream>
#include <iostream>
#include "Employee.h"
#include "File.h"
#include "Text_File.h"
using namespace std;
class Admin :
	public Employee
{
private:
public:
	static int number_of_student;
	static int number_of_teacher;
	Admin();
	~Admin();
};

