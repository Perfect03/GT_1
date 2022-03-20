#include <QCoreApplication>
#include <iostream>
#include "stack.h"
#include "person_keeper.h"
#include "person.h"

int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
    Stack<int> t;
    t.Push(5);
    t.Push(4);
    t.Push(13);
    t.Print();
    //return t.Pop();

    //2-я часть
    PersonKeeper* b = Singleton<PersonKeeper>::Instance();
    // работа не доделана, пока что не могу разобраться, как работать с "singleton"-ом.
    b->ReadPersons("C:/Users/User/Documents/GT_1/txts/persons.txt");
    b->WritePersons("C:/Users/User/Documents/GT_1/txts/for_write.txt");

}
