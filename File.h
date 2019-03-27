#pragma once
#include <fstream>
#include <string>
using namespace std;

template <typename t>
class File
{
public:
	File(){

	}
	void add(string file_name, t T){
		ofstream file(file_name, ios::binary | ios::app);
		file.write((char *)(&T), sizeof(t));
		file.close();
	}

	void delet(string file_name,string File_name,string num){
		t* T = new t;
		int i = 0;
		ofstream assig(File_name, ios::binary | ios::out);
		ifstream file(file_name, ios::binary | ios::in);
		if (file.is_open()){
			while (!file.eof()){
				file.read((char *)(T), sizeof(t));
				cout << T->getname();
				if (T->getnumber() != atoi(num.c_str())){
					assig.write((char *)(T), sizeof(t));
				}
				i++;
			}
			file.close();
			assig.close();
			remove(file_name.c_str());
			rename(File_name.c_str(), file_name.c_str());
		}
	/*	ofstream assig(file_name, ios::binary | ios::app);
		if (assig.is_open()){
			for (int j = 0; j < i - 1; j++){
				if (T[j].getnumber() != atoi(num.c_str())){
					assig.write((char *)(&T[j]), sizeof(t));
				}
			}
			assig.close();
		}*/
	}
	bool update(string file_name, string File_name, string num, t Temp){
		t* T = new t;
		delet(file_name, File_name,num);
		add(file_name, Temp);
		return true;
	}

	bool search_user(string file_name,string num){
		int i = 0;
		t *T = new t;
		ifstream assi(file_name, ios::binary | ios::in);
		while (!assi.eof()){
			assi.read((char *)(T), sizeof(t));
			if (T->getnumber() == atoi(num.c_str())){
				return true;
			}
			i++;
		}
	/*	for (int j = 0; j < i; j++){
			if (T[j].getnumber() == atoi(num.c_str())){
				cout << "fff";
				return true;
			}*/
		return false;
	}

	bool see(string file_name,string num,t *temp){
		t *T = new t;
		int i = 0;
		ifstream assi(file_name, ios::binary | ios::in);
		while (!assi.eof()){
			assi.read((char *)(temp), sizeof(t));
			if (temp->getnumber() == atoi(num.c_str())){

				return true;
			}
			i++;
		}
		return false;
	}

	bool see_grad(string file_name, string cours_code,string ID, t *temp){
		t *T = new t;
		int i = 0;
		ifstream assi(file_name, ios::binary | ios::in);
		while (!assi.eof()){
			assi.read((char *)(temp), sizeof(t));
			if (temp->get_cours_code() == atoi(cours_code.c_str())){
				if (temp->student.getnumber() == atoi(ID.c_str()))
				return true;
			}
			i++;
		}
		return false;
	}

	void see_all(string file_name,  t *temp,int *m){
		int i = 0;
		ifstream assi(file_name, ios::binary | ios::in);
		while (!assi.eof()){
			assi.read((char *)(&temp[i]), sizeof(t));
			i++;
		}
		*m = i;
	}


	~File(){

	}
};

