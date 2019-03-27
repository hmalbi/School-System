#include "Employee.h"


Employee::Employee()
{
	ssn = 000;
	salary = 1000;
}

Employee::Employee(string sal, string ssn){
	this->salary = atoi(sal.c_str());
	this->ssn = atoi(ssn.c_str());
}
void Employee::setsalary(string sal){
	this->salary = atoi(sal.c_str());
}

int Employee::getsalary(){
	return salary;
}

void Employee::setssn(string ssn){
	this->ssn = atoi(ssn.c_str());
}

int Employee::getssn(){
	return ssn;
}

Employee::~Employee()
{
}
