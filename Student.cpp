#include "Student.h"

Student::Student()
{
	this->fname = " " ;
	this->mname = " ";
	this->lname = " ";
	this->adress = " ";
	this->Email = " ";
	this->phone = " ";
	this->password = password;
	dbirthday = 1;
	mbirthday = 1;
	ybirthday = 2000;
	number = 1;
}

Student::Student(string ID){
	this->number = atoi(ID.c_str());
}

Student::Student(string fname, string mname, string lname, string adress, string mail, string phone, string password, string d, string m, string y, string id){
	this->fname = fname;
	this->mname = mname;
	this->lname = lname;
	this->adress = adress;
	this->Email = mail;
	this->phone = phone;
	this->password = password;
	dbirthday = atoi(d.c_str());
	mbirthday = atoi(m.c_str());
	ybirthday = atoi(y.c_str());
	this->number = atoi(id.c_str());
}

int Student::view_assignment(int num,int cors_cod,Assignment *a) {
	string result;
	ostringstream convert;
	convert << num;
	result = convert.str();
	//Cours cours;
	File <Assignment> ff;
	ff.see("Assignment.bin", result, a);
	if (a->get_cours_code() == cors_cod){
		if (a->getnumber() == num){
			if (a->deadline() == 1){
				return 1;
			}
			else{
				return 2;
			}
		}
	}
	return -1;
}

void Student::solve_ass(Question *q){
	File<Question> f;
	for (int i = 0; i < 5; i++){
		f.add("assi_answer.bin", q[i]);
	}
}

void Student::ask_question(Post p){
	File <Post> f;
	f.add("Post.bin", p);
}

void Student::database_add(){
	ofstream file;
	file.open("database.txt", ios::app);
	if (file.is_open()){
		file << this->getfname() << " " << this->getpassword() << "/" << "student" << "\n";
		file.close();
	}
}

int Student::login(string name, string password){
	return login(name, password);
}

Student::~Student()
{
}
