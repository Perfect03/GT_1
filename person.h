#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <functional>
#include <list>
 
using namespace std;

class Person
{
private:
	long key;
	std::string last_name_;
	std::string first_name_;
	std::string patronymic_;
public:
	Person();
	Person(const Person&);

	const std::string& getLastName() const { return last_name_; }
	const std::string& getFirstName() const { return first_name_; }
	const std::string& getPatronymic() const { return patronymic_; }

	void setLastName(const std::string& last_name)  { last_name_ = last_name; }	
	void setFirstame(const std::string& first_name) { first_name_ = first_name; }
	void setpatronymic(const std::string& patronymic) { patronymic_ = patronymic; }

};

#endif
