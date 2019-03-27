#include "Teacher.h"

int Teacher::num = 0;
Teacher::Teacher()
{
	salary = 1000;
	ssn = 111111;
}

Teacher::Teacher(string fname, string mname, string lname, string adress, string mail, string phone, string password, string d, string m, string y, string ssn, string salary,string cours_code){
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
	this->ssn = atoi(ssn.c_str());
	this->salary = atoi(salary.c_str());
	this->cours = (Cours)atoi(cours_code.c_str());
	this->number = atoi(ssn.c_str());
}

/*void Teacher::add(){
	ofstream teacher("Teacher.bin", ios::binary | ios::app);
	if (teacher.is_open()){
		teacher.write((char *)(this), sizeof(Teacher));
		teacher.close();
	}
	ofstream teach;
	teach.open("database.txt", ios::app);
	if (teach.is_open())
	{
		teach << this->getfname() << " " << this->getpassword() << "/" << "teacher" << endl;
		teach.close();
	}
}

void Teacher::delet(){

}

void Teacher::update(){
	ifstream teacher("Teacher.bin", ios::binary | ios::in);
	if (teacher.is_open()){
		while (!teacher.eof()){
			Teacher *teach = new Teacher;
			teacher.read((char *)(teach), sizeof(Teacher));
			//cout << teach->getlname()<<"\t"<<teach->getfname() << endl;
		}
	}
}

void Teacher::search_user(){

}

void Teacher::see(){

}*/

void Teacher::database_add(){
	ofstream teach;
	teach.open("database.txt", ios::app);
	if (teach.is_open())
	{
		teach << this->getfname() << " " << this->getpassword() << "/" << "teacher" << "\n";
		teach.close();
	}
}

int Teacher::login(string name, string password){
	 return login(name, password);
}

void Teacher::answer_post(Post *p, Answer answer){
	File <Post> f;
	int num;
	//f.see_all("Post.bin", p,&num);
	File <Answer> ff;
	ff.add("Post_answer.bin", answer);
}

Teacher::~Teacher()
{
}
