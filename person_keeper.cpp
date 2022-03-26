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
    QFile file(path); // переменнаяя, в которую считывается файл

	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // если файл недоступен для чтения
	{
		throw "Couldn't open a file!"; // то вызываем исключение
	}

    QTextStream f(&file); // поток текстовых данных файла
    Stack<Person> s; // временный стек
    QString line; // переменная, в которую в итогу считаются имена

    while (f.readLineInto(&line)) // цикл по всем именам в файле
    {
        s.Push(Person(line)); // записываем в стек
    }

    while (s.Size() != 0) // цикл по всем именам в файле
	{
        stack_.Push(s.Pop()); // записываем в стек
    }
    file.close();
}

void PersonKeeper::WritePersons(QString path) const
{
    QFile f(path);


    if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) //если файл недоступен для записи
	{
		throw "Couldn't open a file"; //выбрасываем исключение
	}

    QTextStream stream(&f); //поток текстовых данных файла

    stack_.ForEach([&](const Person &b) // перебираем все имена
	{
        stream << b.last_name() << " " << b.first_name() << " " << b.patronymic() << Qt::endl; // записываем
	});
    f.close();
}

int PersonKeeper::Size()
{
	return stack_.Size();
}
