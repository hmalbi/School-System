#include <iostream>
#include <string>
#include "Student.h"
#include "Date.h"
#include "Admin.h"
#include "School.h"
#include "Teacher.h"
#include "Answer.h"
#include "Question.h"
using namespace std;

void main1();

Text_File *poly;

void addstudentfun(Admin A){
	string fname, mname, lname, adress, mail, phone, password,level;
	string day, month, year, ID;
	cout << "Student name : ";
	cin >> fname >> mname >> lname;
	cout << "Student password : ";
	cin >> password;
	cout << "Student ID : ";
	cin >> ID;
	cout << "Student adress : ";
	cin >> adress;
	cout << "Student mail : ";
	cin >> mail;
	cout << "Student phone : ";
	cin >> phone;
	cout << "Student birthday : ";
	cin >> day >> month >> year;
	Student s(fname, mname, lname, adress, mail, phone, password, day, month, year, ID);
	poly = &s;
	File <Student> f;
	f.add("student.bin",s);
	poly->database_add();
	A.number_of_student++;
}

void addteacherfun(Admin A){
	string fname, mname, lname, adress, mail, phone, password, cours_code;
	string day, month, year, ssn, salary;
	cout << "Teacher name : ";
	cin >> fname >> mname >> lname;
	cout << "Teacher password : ";
	cin >> password; 
	cout << "Teacher ssn : ";
	cin >> ssn;
	cout << "Teache adress : ";
	cin >> adress;
	cout << "Teacher mail : ";
	cin >> mail;
	cout << "Teacher phone : ";
	cin >> phone;
	cout << "Teacher salary : ";
	cin >> salary;
	cout << "Teacher birthday : ";
	cin >> day >> month >> year;
	cout << "Teaching : \nMath 100 \nArabic 101\nEnglish 102\nFrench 103\nScince 104\nSocial Studies 105\n";
	cin >> cours_code;
	Teacher t(fname, mname, lname, adress, mail, phone, password, day, month, year, ssn, salary,cours_code);
	A.number_of_teacher++;
	poly = &t;
	File <Teacher> f;
	f.add("teacher.bin",t);
	poly->database_add();
}

void mainfun(int res,string nam){
	if (res == 3){
		Date d;
		int ch1 = 0;
		while (ch1 != 5){
			Student stu;
			Question *q=new Question[5];
			string *answe=new string[100];
			string answer;
			Assignment *ass = new Assignment;
			cout << "                            Welcome "<<nam<<" as a student\n";
			cout << "                                 ****************\n";
			cout << "      .--._  _.--._                                         _.--._  _.--.\n";
			cout << ",-=.-':;:;:;\\':;:;:;'-._                               _.-';:;:;:'/;:;:;:'-.=-,\n";
			cout << "\\\\\\:;:;:;:;:;\\:;:;:;:;:;\\         1->solve ass        /:;:;:;:;:;/:;:;:;:;:;///\n";
			cout << " \\\\\\:;:;:;:;:;\\:;:;:;:;:;\\        2->See deadline    /:;:;:;:;:;/:;:;:;:;:;///\n";
			cout << "  \\\\\\:;:;:;:;:;\\:;:;:;:;:;\\       3->Post           /:;:;:;:;:;/:;:;:;:;:;///\n";
			cout << "   \\\\\\:;:;:;:;:;\\:;::;:;:;:\\      4->See grade     /:;:;:;:;:;/:;:;:;:;:;///\n";
			cout << "    \\\\\\;:;::;:;:;\\:;:;:;::;:\\      ********       /:;:;:;:;:;/:;:;:;:;:;///\n";
			cout << "     \\\\\\;;:;:_:--:\\:_:--:_;:;\\    5->Logout      /;:;_:--:_:/:--:_:;:;;/// \n";
			cout << "      \\\\\\_.-'      :      '-._\\                 /_.-'      :      '-._/// \n";
			cout << "       \\`_..--''--.;.--''--.._=>               <=_..--''--.;.--''--.._`/\n\n\n\n\n\n";

			cin >> ch1;
			if (ch1 == 1){
				string number, code;
					cout << "The cours of the Assignment that you want to solve it : \n";
					cout << "Enter :\n \tMath 100 \n \tArabic 101\n \tEnglish 102\n \tFrench 103\n \tScince 104\n \tSocial Studies 105\n";
					cin >> code;
					cout << "The number of Assignment that you want to solve : ";
					cin >> number;
					File <Assignment> f;
					while (f.search_user("Assignment.bin", number) == 0){
						cout << "Not found this assignment ... please enter the correct number\n\n";
						cout << "The number of Assignment that you want to solve : ";
						cin >> number;
					}
					stu.view_assignment(atoi(number.c_str()), atoi(code.c_str()), ass);
					for (int i = 0; i < 5; i++){
						cout << i + 1 << " : " << ass->questions[i].getquestion() << endl;
					}
					string num_question;
					for (int i = 0; i < 5; i++){
						cout << "Enter the number of question that you want to solve : ";
						cin >> num_question;
						cout << "Enter the Answers : ";
						cin >> answer;
						q[atoi(num_question.c_str())].answer.set_answer(answer);
					}
					stu.solve_ass(q);
			}
			if (ch1 == 2){
				string number,code;
				cout << "The number of Assignment that you want to see deadline of it : ";
				cin >> number;
				File <Assignment> f;
				while (f.search_user("Assignment.bin", number) == 0){
					cout << "Not found this assignment ... please enter the correct number\n\n";
					cout << "The number of Assignment that you want to solve : ";
					cin >> number;
				}
				cout << "The cours of the Assignment that you want to see deadline for it : \n";
				cout << "Enter :\n \tMath 100 \n \tArabic 101\n \tEnglish 102\n \tFrench 103\n \tScince 104\n \tSocial Studies 105\n";
				cin >> code;
				Assignment *a=new Assignment;
				f.see("Assignment.bin", number, a);
				if (a->deadline()){
					cout << "Avilable assignment\n";
					cout << "The deadline is : " << a->getday() << "/" << a->getmonth() << "/" << a->getyear() << endl << endl;
				}
				else{
					cout << "Over time\n";
					cout << "The deadline is : " << a->getday() << "/" << a->getmonth() << "/" << a->getyear() << endl << endl;
				}
			}
			else if (ch1 == 3){
				int ch2 = 0;
				while (ch2 != 3){
					cout << "1 -> Ask question\n2 -> See Teacher Answers\n3 -> Exit\n";
					cin >> ch2;
					if (ch2 == 1){
						Post p;
						Student S;
						File <Post> f;
						string question, num;
						cout << "Enter number of Post : ";
						cin >> num;
						cout << "Enter your question : ";
						cin >> question;
						//getline(cin, question);
						p.question.setquestion(question);
						p.setnumber(num);
						S.ask_question(p);
					}
					else if (ch2 == 2){
						File <Answer> ff;
						Answer *a = new Answer[100];
						int i;
						ff.see_all("Post_answer.bin", a, &i);
						for (int j = 0; j < i - 1; j++){
							cout <<j+1<<" "<<a[j].get_answer()<<endl;
						}
					}
				}
			}
			else if (ch1 == 4){
				File <Student> ff; 
				//search student before see grade
				string ID, code;
				Grade *g = new Grade;
				Grade pp;
				cout << "Enter your ID : ";
				cin >> ID;
				while (ff.search_user("student.bin", ID)==0){
					cout << "  This Student is not exist ... Please reenter the ID number of the student .\n";
					cout << "Enter your ID : ";
					cin >> ID;
				}
				cout << "Enter cours code : ";
				cout << "Enter :\n \tMath 100 \n \tArabic 101\n \tEnglish 102\n \tFrench 103\n \tScince 104\n \tSocial Studies 105\n";
				cin >> code;
				while (code != "100" && code != "101" && code != "102" && code != "103" && code != "104" && code != "105"){
					cout << "This cours code is not exist ... Please reenter cours code .\n";
					cin >> code;
				}
				g->see_grade(atoi(ID.c_str()), atoi(code.c_str()), g);
				cout << "  Your work grade is : " << g->getworkgrad() << endl;
				cout << "  Your midterm gerde is : " << g->getmidterm() << endl;
				cout << "  Your final gerde is : " << g->getfinal() << endl;
				cout << "  Your total gerde is : " << g->computtotal() << endl;
				cout << "  Your Evaluation is : " << g->t2der_grad(g->computtotal()) << endl;
			}
			else main1();
		}
	}
	else if (res == 2){
		Teacher t;
		int ch1 = 0;
		while (ch1 != 4){
			cout << "                  _,-._                                _.-,_\n";
			cout << "                 / \\_/ \\                              / \\_/ \\\n";
			cout << "                 >-(_)-<  Welcome "<<nam<<" as a teacher  >-(_)-< \n";
			cout << "                 \\_/ \\_/                              \\_/ \\_/\n";
			cout << "                   `-'                                  '-`\n";
			cout << "                             1 -> Assignment\n";
			cout << "                             2 -> Post\n";
			cout << "                             3 -> Grade\n";
			cout << "                             4 ->Log out\n";
			//cout << "To add assignment for students : 1\nTo delete present assignment : 2\nTo update presedent assignment : 4\nAdd grade : 4\nExite : 5\n";
			cin >> ch1;
			if (ch1 == 1){
				File <Assignment> f;
				int ch2 = 0;
				while (ch2 != 6){
					cout << "1 -> Add Assignment\n2 -> Delete Assignment\n3 -> Update Assignment\n4 -> Search Assignment\n5 -> See Students's Answers\n6->Exit\n\n";
					cin >> ch2;
					if (ch2 == 1){
						Question question[15];
						string assinum;
						string  day, month, year, wrong, right, code;
						string temp, num;
						cout << "Cours code : ";
						cout << "Enter :\n \tMath 100 \n \tArabic 101\n \tEnglish 102\n \tFrench 103\n \tScince 104\n \tSocial Studies 105\n";
						cin >> code;
						while (code != "100" && code != "101" && code != "102" && code != "103" && code != "104" && code != "105"){
							cout << "This cours code is not exist ... Please reenter cours code .\n";
							cin >> code;
						}
						cout << "Assignment number : ";
						cin >> assinum;
						cout << "Deadline day : ";
						cin >> day;
						cout << "Deadline month : ";
						cin >> month;
						cout << "Deadline year : ";
						cin >> year;

						for (int i = 0; i < 5; i++){
							cout << "Question num : ";
							cin >> num;
							question[i].set_question_code(num);
							cout << "Question : ";
							cin >> temp;
							//getline(cin, temp);
							question[i].setquestion(temp);
						}

						Assignment a(" ", assinum, day, month, year, code, question);

						f.add("Assignment.bin", a);
					}
					else if (ch2 == 2){
						Assignment a;
						string n;
						cout << "The number of aasigment that you want to delet : ";
						cin >> n;
						if (f.search_user("Assignment.bin", n)){
							f.delet("Assignment.bin", "temp.bin", n);
							cout << "The Assignment of the number " << n << " has been deleted\n";
						}
						else
							cout << "There is no Assignment with number " << n<<endl;
					}
					else if (ch2 == 3){
						string num1;
						cout << "The number of Assignment that you want to update : ";
						cin >> num1;
						if (f.search_user("Assignment.bin", num1)){
							cout << "The edit Assignment : \n\n";
							Question question[15];
							string assinum;
							string  day, month, year, wrong, right, code;
							string temp, num;
							cout << "Cours code : ";
							cout << "Enter :\n \tMath 100 \n \tArabic 101\n \tEnglish 102\n \tFrench 103\n \tScince 104\n \tSocial Studies 105\n";
							cin >> code;
							while (code != "100" && code != "101" && code != "102" && code != "103" && code != "104" && code != "105"){
								cout << "This cours code is not exist ... Please reenter cours code .\n";
								cin >> code;
							}
							cout << "Assignment number : ";
							cin >> assinum;
							cout << "Deadline day : ";
							cin >> day;
							cout << "Deadline month : ";
							cin >> month;
							cout << "Deadline year : ";
							cin >> year;

							for (int i = 0; i < 5; i++){
								cout << "Question num : ";
								cin >> num;
								question[i].set_question_code(num);
								cout << "Question : ";
								cin >> temp;
								//getline(cin, temp);
								question[i].setquestion(temp);
							}

							Assignment a(" ", assinum, day, month, year, code, question);
							f.update("Assignment.bin", "temp.bin", num1, a);
							cout << "The Assignment has been updated\n";
						}
						else cout << "This Assignment is NOT found\n";
					}
					else if (ch2 == 4){
						string number;
						Assignment *a = new Assignment;
						cout << "Enter the number of Assignment that you want to see : ";
						cin >> number;
						if (f.search_user("Assignment.bin", number)){
							f.see("Assignment.bin", number, a);
							cout << "Cours code : " << a->get_cours_code() << endl;
							cout << "Assignment number : " << a->getnumber() << endl;
							cout << "Deadline day : " << a->getday() << endl;
							cout << "Deadline month : " << a->getmonth() << endl;
							cout << "Deadline year : " << a->getyear() << endl;
							for (int i = 0; i < 5; i++){
								cout << i+1 << a->questions[i].getquestion() << endl;
							}
						}
						else
							cout << "The Assignment Not found\n";
					}
					else if(ch2==5){
						File <Question> ff;
						Question *q = new Question[100];
						int i;
						ff.see_all("assi_answer.bin", q, &i);
						for (int j = 0; j < 5; j++){
							cout << j <<" : "<< q[j].answer.get_answer();
						}
					}
				}
			}
			else if (ch1 == 2){
				Teacher t;
				int i;
				Post *p = new Post[100];
				File <Post> f;
				f.see_all("Post.bin",p,&i);
				for (int j = 0; j < i-1; j++){
					cout <<"The Post "<<j+1<< " is "<< p[j].question.getquestion() << endl;
				}
				string *answer=new string[i-1];
				File <Answer> ff;
				for (int j = 0; j < i - 1; j++){
					cout << "Your answer of Post " << j + 1 << " is : ";
					cin >> answer[j];
					Answer a(answer[j]);
					//getline(cin, answer[j]);
					ff.add("Post_answer.bin", a);
				}
			}
			else if (ch1 == 3){
				int ch2 = 0;
				while (ch2 != 5){
					cout << "1 -> Add Grade\n2 -> Delete Grade\n3 -> Update Grade\n4 -> Search Grade\n5 -> Exit\n\n";
					cin >> ch2;
					File <Grade> f;
					if (ch2 == 1){
						string work, midterm, final, fname, mname, lname, ID, code,number;
						cout << "Student name : ";
						cin >> fname >> mname >> lname;
						cout << "Student ID : ";
						cin >> ID;
						cout << "Enter cours code : ";
						cout << "Enter :\n \tMath 100 \n \tArabic 101\n \tEnglish 102\n \tFrench 103\n \tScince 104\n \tSocial Studies 105\n";
						cin >> code;
						while (code != "100" && code != "101" && code != "102" && code != "103" && code != "104" && code != "105"){
							cout << "This cours code is not exist ... Please reenter cours code .\n";
							cin >> code;
						}
						cout << "Grade number : ";
						cin >> number;
						cout << "Student work grade : ";
						cin >> work;
						cout << "Student midterm grade : ";
						cin >> midterm;
						cout << "Student final grade : ";
						cin >> final;
						Student s;
						s.setname(fname, mname, lname);
						s.setnumber(ID);
						Grade g(work, midterm, final, code, s);
						g.setnumber(number);
						g.computtotal();
						f.add("Grade.bin", g);
					}
					else if (ch2 == 2){
						string n;
						cout << "The number of Grade that you want to delet : ";
						cin >> n;
						if (f.search_user("Grade.bin", n)){
							f.delet("Grade.bin", "temp.bin", n);
							cout << "The Grade of the number " << n << " has been deleted\n";
						}
						else
							cout << "There is no Grade with number " << n << endl;
					}
					else if (ch2 == 3){
						string num1;
						cout << "The number of Grade that you want to update : ";
						cin >> num1;
						if (f.search_user("Grade.bin", num1)){
							cout << "The edit Grade : \n\n";
							string work, midterm, final, fname, mname, lname, ID, code, number;
							cout << "Student name : ";
							cin >> fname >> mname >> lname;
							cout << "Student ID : ";
							cin >> ID;
							cout << "Enter cours code : ";
							cout << "Enter :\n \tMath 100 \n \tArabic 101\n \tEnglish 102\n \tFrench 103\n \tScince 104\n \tSocial Studies 105\n";
							cin >> code;
							while (code != "100" && code != "101" && code != "102" && code != "103" && code != "104" && code != "105"){
								cout << "This cours code is not exist ... Please reenter cours code .\n";
								cin >> code;
							}
							cout << "Grade number : ";
							cin >> number;
							cout << "Student work grade : ";
							cin >> work;
							cout << "Student midterm grade : ";
							cin >> midterm;
							cout << "Student final grade : ";
							cin >> final;
							Student s;
							s.setname(fname, mname, lname);
							s.setnumber(ID);
							Grade g(work, midterm, final, code, s);
							g.computtotal();
							g.setnumber(number);
							f.update("Grade.bin", "temp.bin", num1, g);
							cout << "The Grade has been updated\n";
						}
						else cout << "This Grade is NOT found\n";
					}
					else if (ch2 == 4){
						string number;
						Grade *a = new Grade;
						cout << "Enter the number of Grade that you want to see : ";
						cin >> number;
						if (f.search_user("Grade.bin", number)){
							f.see("Grade.bin", number, a);
							cout << "Cours code : " << a->get_cours_code() << endl;
							cout << "Grade number : " << a->getnumber() << endl;
							cout << "Work Grade : " << a->getworkgrad() << endl;
							cout << "Midterm Grade : " << a->getmidterm() << endl;
							cout << "final Grade : " << a->getfinal() << endl;
							cout << "Total Grade : " << a->get_total_grade() << endl;
							cout << "Evaluation : " << a->t2der_grad(a->get_total_grade()) << endl;
						}
						else
							cout << "The Grade Not found\n";
					}
				}
			}
			else main1();
		}
	}
	else if (res == 1){
		Admin A;
		int ch1 = 0;
		while (ch1 != 5){
			cout << "                  _,-._                                _.-,_\n";
			cout << "                 / \\_/ \\                              / \\_/ \\\n";
			cout << "                 >-(_)-<  Welcome " << nam << " as a admin     >-(_)-< \n";
			cout << "                 \\_/ \\_/                              \\_/ \\_/\n";
			cout << "                   `-'                                  '-`\n";
			cout << "                             1 -> Add User\n";
			cout << "                             2 -> Delete User\n";
			cout << "                             3 -> Update User\n";
			cout << "                             4 -> Search User\n";
			cout << "                             5 -> Logout\n";
			cin >> ch1;
			if (ch1 == 1){
				int ch2 = 0;
				while (ch2 != 3){
					cout << "1 -> Add Student\n2 -> Add Teacher\n3 -> Exit\n";
					cin >> ch2;
					if (ch2 == 1){
						addstudentfun(A);
					}
					else if (ch2 == 2){
						addteacherfun(A);
					}
				}	
			}
			else if (ch1 == 2){
				int ch2 = 0;
				while (ch2 != 3)
				{
					cout << "1 -> Remove Student\n2 -> Remove Teacher\n3 -> Exit\n";
					cin >> ch2;
					if (ch2 == 1)
					{
						string ID;
						cout << "Enter ID of Student that you want to delete him : ";
						cin >> ID;
						File <Student> f;
						f.delet("student.bin", "temp.bin", ID);
						cout << "The student of ID " << ID << " has been deleted\n";
					}
					else if (ch2 == 2)
					{
						string num;
						cout << "Enter ID of Teacher that you want to delete him : ";
						cin >> num;
						File <Teacher> f;
						f.delet("student.bin", "temp.bin", num);
						cout << "The Teacher of ID " << num << " has been deleted\n";
					}
				}
			}
			else if (ch1 == 4){
				int ch2 = 0;
				while (ch2!=3)
				{
					cout << "1 -> Search student\n2 -> Search teacher\n3 -> Exit\n";
					cin >> ch2;
					if (ch2 == 1)
					{
						string number;
						cout << "Enter the ID of student that you want to see him : ";
						cin >> number;
						File<Student> f;
						Student *s = new Student;
						if (f.search_user("student.bin", number))
						{
							f.see("student.bin", number, s);
							cout <<"Student name : "<< s->getfname() << " " << s->getmname() << s->getlname() << endl;
							cout << "Student ID : " << s->getnumber() << endl;
						}
						else cout << "Student NOT found\n";
					}
					else if (ch2 == 2){
						string number;
						cout << "Enter the SSN of teacher that you want to see him : ";
						cin >> number;
						File<Teacher> f;
						Teacher *s = new Teacher;
						if (f.search_user("Teacher.bin", number))
						{
							f.see("Teacher.bin", number, s);
							cout << "Teacher name : " << s->getfname() << " " << s->getmname() << s->getlname() << endl;
							cout << "Teacher ID : " << s->getnumber() << endl;
						}
						else cout << "Teacher NOT found\n";
					}
				}
			}
			else if (ch1 == 3){
				int ch2 = 0;
				while (ch2 != 3){
					cout << "1 -> Update Student\n2 -> Update Teacher\n3 -> Exit\n";
					cin >> ch2;
					if (ch2 == 1){
						string ID;
						File <Student> f;
						cout << "Enter Student ID that you want to update him (without change his name and password) : ";
						cin >> ID;
						if (f.search_user("student.bin", ID)){
							string fname,lname,mname,password,adress, mail, phone, num, day, month, year;
							cout << "Enter new information  \n \n";
							cout << "Student name : ";
							cin >> fname >> mname >> lname;
							cout << "Student password : ";
							cin >> password;
							cout << "Student adress : ";
							cin >> adress;
							cout << "Student mail : ";
							cin >> mail;
							cout << "Student phone : ";
							cin >> phone;
							cout << "Student ID : ";
							cin >> num;
							cout << "Student birthday : ";
							cin >> day >> month >> year;
							Student s(fname, mname, lname, adress, mail, phone, password, day, month, year, ID);
							f.update("student.bin", "temp.bin", ID, s);
							cout << "The Student " <<fname<<" has been updated\n";
						}
						else cout << "Student NOT found\n";
					}
					else if (ch2 == 2){
						File <Teacher> f;
						string ID;
						cout << "Enter Teacher ID that you want to update him (without change his name and password) : ";
						cin >> ID;
						if (f.search_user("Teacher.bin", ID)){
							string fname, lname, mname, password, adress, mail, phone, ssn, day, month, year,salary,code;
							cout << "Enter new information  \n \n";
							cout << "Teacher name : ";
							cin >> fname >> mname >> lname;
							cout << "Teacher password : ";
							cin >> password;
							cout << "Teacher adress : ";
							cin >> adress;
							cout << "Teacher mail : ";
							cin >> mail;
							cout << "Teacher phone : ";
							cin >> phone;
							cout << "Teacher SSN : ";
							cin >> ssn;
							cout << "Teacher Salary : ";
							cin >> salary;
							cout << "Teacher birthday : ";
							cin >> day >> month >> year;
							cout << "Teaching : ";
							cout << "Enter :\n \tMath 100 \n \tArabic 101\n \tEnglish 102\n \tFrench 103\n \tScince 104\n \tSocial Studies 105\n";
							cin >> code;
							while (code != "100" && code != "101" && code != "102" && code != "103" && code != "104" && code != "105"){
								cout << "This cours code is not exist ... Please reenter cours code .\n";
								cin >> code;
							}
							cin >> code;
							Teacher s(fname, mname, lname, adress, mail, phone, password, day, month, year, ssn,salary,code);
							f.update("Teacher.bin", "temp.bin", ID, s);
							cout << "The Teacher "<<fname<<" has been updated\n";
						}
						else cout << "Teacher NOT found\n";
					}
				}
			
			}
			else main1();
		}
	}
}

