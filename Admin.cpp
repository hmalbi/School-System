#include "Admin.h"
int Admin::number_of_student = 0;
int Admin::number_of_teacher = 0;
Admin::Admin()
{
	salary = 1000;
}

/*void Admin::deletestudent(int num){
Student s[5];
ifstream student;
string line[10];
string z[2];
int i;
student.open("students.txt", ios::in|ios::out);
if (student.is_open()){
i = 0;
while (!student.eof()){
getline(student, line[0]);
s[i].setid(line[0]);
getline(student, line[1]);
SplitMyWord(line[1], ' ', z);
s[i].setname(z[0], z[1], z[3]);
cout << s[i].getfname() << " " << s[i].getmname() << " " << s[i].getlname() << endl;
getline(student, line[2]);
SplitMyWord(line[2], '/', z);
s[i].setbirthday(z[0], z[1], z[3]);
getline(student, line[3]);
s[i].setadress(line[3]);
getline(student, line[4]);
s[i].setemail(line[4]);
getline(student, line[5]);
s[i].setphone(line[5]);
getline(student, line[6]);
i++;
}
student.close();
}
//delete s[num];
for (int j = num; j < i; j++){
s[j] = s[j - 1];
}
ofstream file;
file.open("students.txt", ios::out);
for (int j = 0; j < i - 1; j++){
file << s[j].getid() << "\n" << s[j].getfname() << " " << s[j].getlname() << " " << s[j].getmname() << "\n" << s[j].getdbirthday() << "/" << s[j].getmbirthday() << "/" << s[j].getybirthday() << "\n" << s[j].getadress() << "\n" << s[j].getemail() << "\n" << s[j].getphone() << "\n" << "**" << endl;
file.close();
}
}

void Admin::deleteteacher(int num){
Teacher t[5];
ifstream teacher;
Admin a;
string line[10];
string z[2];
int i;
teacher.open("teacher.txt", ios::in | ios::out);
if (teacher.is_open()){
for (i = 0; i < number_of_teacher;){
getline(teacher, line[0]);
t[i].num = atoi(line[0].c_str());
getline(teacher, line[1]);
a.SplitMyWord(line[1], ' ', z);
t[i].setname(z[0], z[1], z[3]);
cout << t[i].getfname() << " " << t[i].getmname() << " " << t[i].getlname() << endl;
getline(teacher, line[2]);
t[i].setadress(line[2]);
getline(teacher, line[3]);
t[i].setphone(line[3]);
getline(teacher, line[4]);
t[i].setsalary(line[4]);
getline(teacher, line[5]);
a.SplitMyWord(line[5], '/', z);
t[i].setbirthday(z[0], z[1], z[2]);
getline(teacher, line[6]);
t[i].setemail(line[6]);
getline(teacher, line[7]);
t[i].setssn(line[7]);
getline(teacher, line[8]);
i++;
}
teacher.close();
}
//delete s[num];
for (i = num + 1; i < number_of_teacher; i++){
t[i] = t[i - 1];
}
ofstream file;
file.open("teacher.txt", ios::out);
for (i = 0; i < number_of_teacher - 1; i++){
file << t[i].num << "\n" << t[i].getfname() << " " << t[i].getmname() << " " << t[i].getlname() << "\n" << t[i].getadress() << "\n" << t[i].getphone() << "\n" << t[i].getsalary() << "\n" << t[i].getdbirthday() << "/" << t[i].getmbirthday() << "/" << t[i].getybirthday() << "\n" << t[i].getemail() << "\n" << t[i].getssn() << endl << "**\n";
file.close();
}
number_of_teacher--;
}
*/
Admin::~Admin()
{
}