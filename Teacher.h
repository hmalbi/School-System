#pragma once
#include "Person.h"
#include "Cours_Enum.h"
#include "Assignment.h"
#include <fstream>
#include <string>
#include "Employee.h"
#include "Grade.h"
#include "File.h"
#include "Post.h"
#include "Text_File.h"
class Teacher :
	public Employee, public Text_File
{
public:
	Cours cours;
	static int num;
	Teacher();
	Teacher(string, string, string, string, string, string, string, string, string, string, string, string,string);
	void database_add();
	int login(string name, string password);
	void answer_post(Post *p,Answer answer);
	~Teacher();
};

