#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H

#include <QString>
#include <QTextStream>
#include <QFile>

#include "person.h"
#include "stack.h"

class PersonKeeper
{
public:

	static PersonKeeper &Instance();

	void ReadPersons(QString path);
	void WritePersons(QString path) const;

    int Size(); // количество имён

private:
    PersonKeeper();
    ~PersonKeeper();

	Stack<Person> stack_; // стек имён
};

#endif
