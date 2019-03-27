#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>
using namespace std;

class Resours
{
protected:
	string name;
	int number;
public:
	Resours();
	Resours(string, string);
	string getname();
	void setname(string);
	int getnumber();
	void setnumber(string);
	string search(string, string);
	void SplitMyWord(string x, char n, string ReturnArray[]);
	~Resours();
};

