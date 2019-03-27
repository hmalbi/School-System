#include "Resours.h"


Resours::Resours()
{
	name = "";
	number = 0;
}

Resours::Resours(string name, string number){
	this->name = name;
	this->number = atoi(number.c_str());
}

string Resours::getname(){
	return name;
}

void Resours::setname(string name){
	this->name = name;
}

int Resours::getnumber(){
	return this->number;
}

void Resours::setnumber(string number){
	this->number = atoi(number.c_str());
}

string Resours::search(string x, string KeyWord)
{
	string line;
	ifstream myfile(x);
	int result = 0;
	int i = 1;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			int pos = line.find(KeyWord);
			if (pos >= 0)
			{
				return line;
			}
			i++;
		}
	}
	return "";
}

void Resours::SplitMyWord(string x, char n, string ReturnArray[])
{

	string currentstring = "";

	int i = 0;
	int j = 0;
	while (i<x.size())
	{
		if (x[i] != n)
		{
			currentstring += x[i];
		}
		else
		{
			ReturnArray[j] = currentstring;
			currentstring = "";
			j++;
		}


		i++;
	}
	ReturnArray[j] = currentstring;
}

Resours::~Resours()
{
}
