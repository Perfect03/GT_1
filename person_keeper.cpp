#include "person_keeper.h"

PersonKeeper::PersonKeeper()
{

}

PersonKeeper::~PersonKeeper()
{

}

//функция возвращающая ссылку на единственный объект класса
PersonKeeper &PersonKeeper::Instance()
{
	static PersonKeeper instance;
	return instance;
}


void PersonKeeper::ReadPersons(QString path)
{
	
}

void PersonKeeper::WritePersons(QString path) const
{
	
}


int PersonKeeper::Size()
{
	return stack_.Size();
}

void PersonKeeper::Clear()
{
	return stack_.Clear();
}
