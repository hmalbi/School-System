#pragma once
#include <string>
#include "File.h"
#include "Answer.h"
#include "Question.h"
#include "Resours.h"
using namespace std;
class Post : public Resours
{
public:
	Question question;
	Post();
	void answer_post(string);
	Post(Question);
	~Post();
};
