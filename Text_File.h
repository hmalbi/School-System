#pragma once
#include <string>
#include <fstream>

using namespace std;

class Text_File
{
public:
	virtual void database_add() = 0;
	virtual int login(string name,string password) = 0;
};

