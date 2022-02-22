#include <QCoreApplication>
#include <iostream>
#include "stack.h"

int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
    Stack<int> t;
    t.Push(5);
    t.Push(4);
    t.Push(2);
    //t.Print();
    cout << 5;
    return t.Pop();
}
