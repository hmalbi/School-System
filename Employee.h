#pragma once
#include <iostream>
#include <string>
#include "Person.h"
class Employee :
	public Person
{
protected:
	int salary;
	int ssn;
public:
	Employee();
	Employee(string, string);
	void setsalary(string);
	int getsalary();
	void setssn(string);
	int getssn();
	~Employee();
};

