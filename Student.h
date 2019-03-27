#pragma once
#include "Person.h"
#include "Cours_Enum.h"
#include "Assignment.h"
#include "File.h"
#include "Post.h"
#include "Text_File.h"
class Student :
	public Person, public Text_File
{
public:
	Student();
	Student(string); 
	Student(string, string, string, string, string, string, string, string, string, string, string);
	void see_assignment(string, string, string, string);
	int view_assignment(int,int,Assignment *);
	void solve_ass(Question *);
//	bool search_student(string);//implement this function from interface
	void ask_question(Post);
	void database_add ();
	int login(string name, string password);
	~Student();
};

