#pragma once
#include "Resours.h"
class Person : public Resours
{
protected:
	string fname;
	string mname;
	string lname;
	string password;
	string adress;
	string Email;
	string phone;
	int dbirthday;
	int mbirthday;
	int ybirthday;
public:
	Person();
	Person(string, string, string, string, string,string, int, int, int, string);
	string getfname();
	string getmname();
	string getlname();
	void setname(string ,string,string);
	void setpassword(string);
	string getpassword();
	void setphone(string);
	string getphone();
	void setemail(string);
	string getemail();
	void setadress(string);
	string getadress();
	void setbirthday(string,string,string);
	int getdbirthday();
	int getmbirthday();
	int getybirthday();
	void changepassword();
	bool check(string, string);
	int login(string, string);
	/*
	virtual void addperson();//add student in the class of student , add teacher in the class of teacher , add admin too
	virtual void deletperson();
	*/
	~Person();
};

