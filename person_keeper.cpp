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
	QFile file(path);

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // если файл недоступен для чтения
	{
		throw "Couldn't open a file!"; // то вызываем исключение
	}

	QTextStream stream(&file); // поток текстовых данных файла
	QString line; // переменная, в которую считываются имена

	while (stream.readLineInto(&line)) // цикл по всем именам в файле
	{
		stack_.Push(Person(line));
	}
	file.close();
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

QStringList PersonKeeper::ToQStringList() const
{
	QStringList string_list;

	stack_.ForEach([&](const Person &value)
	{
		string_list.prepend(value.last_name() + " " + value.first_name() + " " + value.patronymic());
	});

	return string_list;
}

int PersonKeeper::Size()
{
	return stack_.Size();
}

void PersonKeeper::Clear()
{
	return stack_.Clear();
}
