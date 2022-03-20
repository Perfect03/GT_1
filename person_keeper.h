#ifndef PERSONKEEPER_H
#define PERSONKEEPER_H

#include <QString>
#include <QTextStream>
#include <QFile>

#include "singleton.h"
#include "person.h"
#include "stack.h"

class PersonKeeper
{
public:
	PersonKeeper();
	PersonKeeper(const PersonKeeper &);
	~PersonKeeper();
	PersonKeeper &operator=(const PersonKeeper &);

	static PersonKeeper &Instance();

	void ReadPersons(QString path);
	void WritePersons(QString path) const;

	QStringList ToQStringList() const; // экспорт стека имён в список строк

	int Size();
	void Clear();

private:
	Stack<Person> stack_; // стек имён
};

#endif
