#include "Assignment.h"

Assignment::Assignment()
{
	this->name = "assi";
	this->number = 1;
	this->day = 1;
	this->month = 1;
	this->year = 2015;
	this->cours = Math;
	for (int i = 0; i < Max; i++){
	int j = i;
	string result;
	ostringstream convert;
	convert << j;
	result = convert.str();
	questions[i].set_question_code(result);
	questions[i].setquestion(" ");
	}
}

Assignment::Assignment(string name, string num, string day, string month, string year,string cours_code, Question *q){
	this->name = name;
	number = atoi(num.c_str());
	this->day = atoi(day.c_str());
	this->month = atoi(month.c_str());
	this->year = atoi(year.c_str());
	this->cours = (Cours)atoi(cours_code.c_str());
	for (int i = 0; i < Max; i++){
		questions[i].setquestion(q[i].getquestion());
		string result;
		ostringstream convert;
		convert << q[i].getquestion();
		result = convert.str();
		questions[i].set_question_code(result);
	}
}

void Assignment::set_cours_code(string cours_code){
	this->cours = (Cours) atoi(cours_code.c_str());
}

int Assignment::get_cours_code(){
	return cours;
}

/*void Assignment::check_answer(string answer){

}

/*void Assignment::split_assignment(Assignment *a){
ifstream assi;
string line;
string date[3];
string answer[2];
string question[2];
int i,j=3;
string myline[100];
Question q;
assi.open("Assignment.txt", ios::in);
getline(assi, line);
SplitMyWord(line, '|', myline);
a->setnumber(myline[0]);
//a->cours.setnumber(myline[1]);
SplitMyWord(myline[2], '/', date);
a->setday(date[0]);
a->setmonth(date[1]);
a->setyear(date[2]);
a->set_total_number(myline[3]);
for (i = 0; i < atoi(myline[3].c_str()); i++){
SplitMyWord(myline[++j], '-', question);
q.setquestion(question[0]);
SplitMyWord(question[1], '*', answer);
q.set_right_answer(answer[0]);
q.set_wrong_answer(answer[1]);
a->questions.push_back(q);
}
}*/

bool Assignment::deadline(){
	Person p;
	string date;
	string dat[3];
	int thisday, thismonth, thisyear;
	int m, d, y;
	d = this->getday();
	m = this->getmonth();
	y = this->getyear();
	camputedateoftoday(&thisday, &thismonth, &thisyear);
	if (thismonth<m && thisyear == y){
		return true;
	}
	else if (thismonth == m && thisyear == y){
		if (thisday <= d)
			return true;
		else if (thisyear < y){
			return true;
		}
		else
			return false;
	}
}

/*void Assignment::add(){
	ofstream assi("Assignment.bin", ios::binary | ios::app);
	if (assi.is_open()){
		assi.write((char *)(this), sizeof(Assignment));
		assi.close();
	}
}

void Assignment::delet(string num){
	Assignment *ass = new Assignment;
	Assignment a;
	int i = 0;
	ifstream assi("Assignment.bin", ios::binary | ios::app);
	while (!assi.eof()){
		assi.read((char *)(ass), sizeof(Assignment));
		i++;
	}
	assi.close();
	ofstream assig("Assignment.bin", ios::binary | ios::app);
	if (assig.is_open()){
		for (int j = 0; j < i-1; j++){
			if (ass[j].getnumber() != atoi(num.c_str())){
				assig.write((char *)(&ass[j]), sizeof(Assignment));
			}
		}
		assig.close();
	}*/


Assignment::~Assignment()
{
}