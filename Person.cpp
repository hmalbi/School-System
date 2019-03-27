#include "Person.h"

Person::Person()
{
	fname = "";
	mname = "";
	lname = "";
	Email = "";
	phone = "111111111";
	password = "12345";
	dbirthday = 1;
	mbirthday = 1;
	ybirthday = 2000;
}

Person::Person(string fname, string mname, string lname,string adress, string email, string phone, int day, int month, int year, string password){
	this->fname = fname;
	this->mname = mname;
	this->lname = lname;
	this->adress = adress;
	Email = email;
	this->phone = phone;
	dbirthday = day;
	mbirthday = month;
	ybirthday = year;
	this->password = password;
}

string Person::getfname(){
	return fname;
}

string Person::getmname(){
	return mname;
}

string Person::getlname(){
	return lname;
}

void Person::setname(string fname,string mname,string lname){
	this->fname = fname;
	this->mname = mname;
	this->lname = lname;
}


void Person::setpassword(string pass){
	password = pass;
}

string Person::getpassword(){
	return password;
}

void Person::setphone(string phone){
	this->phone = phone;
}

string Person::getphone(){
	return phone;
}

void Person::setemail(string email){
	Email = email;
}

string Person::getemail(){
	return Email;
}

void Person::setadress(string adress){//attention adress is array of string
	this->adress = adress;
}

string Person::getadress(){
	return adress;
}

void Person::setbirthday(string day,string month,string year){
	dbirthday = atoi(day.c_str());
	mbirthday = atoi(month.c_str());
	ybirthday = atoi(year.c_str());
}

int Person::getdbirthday(){
	return dbirthday;
}
int Person::getmbirthday(){
	return mbirthday;
}

int Person::getybirthday(){
	return ybirthday;
}

void Person::changepassword(){

}

bool Person::check(string p, string p1){
	if (sizeof(p) != sizeof(p1))
		return false;
	for (int i = 0; i < sizeof(p); i++){
		if (p[i] != p1[i])
			return false;
	}
	return true;
}

int Person::login(string password, string username){
	Person p;
	string line;
	string a[3];
	ifstream myfile("database.txt");
	int result = 0;
	int i = 0;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			int pos = line.find(username);
			int pospass = line.find(password);
			p.SplitMyWord(line, '/', a);
			if (pos >= 0 && pospass >= 0 && a[1] == "admin"){
				return 1;
			}
			if (pos >= 0 && pospass >= 0 && a[1] == "teacher"){
				//	*type = a[2];
				return 2;
			}
			if (pos >= 0 && pospass >= 0 && a[1] == "student"){
				//*type = a[2];
				return 3;
			}
			i++;
		}
		myfile.close();
	}
	return false;
}

Person::~Person()
{
}
