#pragma once
#include <string>
using namespace std;
class Student
{
private:
	string name;
	string rollNO;
	int stdId;
public:
	Student(string name, string rollNo, int stdId);
	string getName() const;
	string getRollNo() const;
	int getstdId() const;
};

Student::Student(string name, string rollNo, int stdId)
	:name{ name }, rollNO{ rollNo }, stdId{stdId} {
}

string Student::getName() const
{
	return name;
}

string Student::getRollNo() const
{
	return rollNO;
}

int Student::getstdId() const
{
	return stdId;
}
