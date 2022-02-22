#include <QCoreApplication>
#include <iostream>
#include "stack.h"

int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
   //не знаю, нужно это или нет, но ниже проверка использования функций
    Stack<int> t;
    t.Push(5);
    t.Push(4);
    t.Push(13);
    t.Print();
    return t.Pop();
}
