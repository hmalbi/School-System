#include "School.h"


School::School()
{
}

School::School(string f, string l){
	fname = f;
	lname = l;
}

string School::getfname(){
	return fname;
}

string School::getlname(){
	return lname;
}

/*int School::check_user(int key)
{
	if (key==11)
		return 1;


	else if (key==22)
		return 2;

	else if (key == 33)
		return 3;
	else
		return -1;
}*/



int School::check_student(string type){
	int t = atoi(type.c_str());
	return t;
}

int School::check_teacher(string type){
	int t = atoi(type.c_str());
	int p = t % 10;
	for (int i = 0; i < 6; i++){
		if (p == i)
			return i;
	}
}

/*int School::login(string username,string password,int secur){
		int i = 0;
			if (check_user(secur) == 1 && Getnameindex(password, username) == 1){
				return 1;
			}
			else if (check_user(secur) == 2 && Getnameindex(password, username) == 1){
				return 2;
			}
			else if (check_user(secur) == 3 && Getnameindex(password, username) == 1){
				return 3;
			}
			return -1;

	}*/

School::~School()
{
}
