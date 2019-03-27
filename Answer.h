#pragma once
#include <string>
using namespace std;
class Answer
{
protected:
	string answer;
public:
	Answer();
	Answer(string);
	string get_answer();
	void set_answer(string);
	~Answer();
};
