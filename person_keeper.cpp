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
	QFile file(path);


	if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) //если файл недоступен для записи
	{
		throw "Couldn't open a file"; //выбрасываем исключение
	}

	QTextStream stream(&file); //поток текстовых данных файла

	stack_.ForEach([&](const Person &value) // перебираем все имена
	{
		stream << value.last_name() << '\t' << value.first_name() << '\t' << value.patronymic() << Qt::endl; // записываем
	});
	file.close();
}


int PersonKeeper::Size()
{
	return stack_.Size();
}

void PersonKeeper::Clear()
{
	return stack_.Clear();
}
