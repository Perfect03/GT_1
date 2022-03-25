#include <QCoreApplication>
#include <iostream>
#include "stack.h"
#include "person_keeper.h"
#include "person.h"

int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);

   setlocale(LC_ALL, "Russian");

    Stack<const char *> t;
    t.Push("+");
    t.Push("+");
    t.Push("B");
    cout << "Size of stack before node removal: " << t.Size() << endl;
    t.Pop();
    cout << "Size of stack after node removal: " << t.Size() << endl;
    t.Push("C");


    cout << "Elements of stack: " << endl;
    while (true)
    {
        cout << t.Pop() << endl;
    }


    // ПРОВЕРКА ИСКЛЮЧЕНИЯ

    Stack<int> e;
    e.Pop(); // пробуем извлечь элемент из пустого стека - получаем исключение

    //2-я часть
    //PersonKeeper* b = Singleton<PersonKeeper>::Instance();
    // работа не доделана, пока что не могу разобраться, как работать с "singleton"-ом.
    //b->ReadPersons("C:/Users/User/Documents/GT_1/txts/persons.txt");
   // b->WritePersons("C:/Users/User/Documents/GT_1/txts/for_write.txt");

}
