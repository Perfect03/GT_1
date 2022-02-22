#include <iostream>
#include <string>
#include <functional>

#include "e_stack_exception.h"
#include "e_stack_empty.h"
 
using namespace std;

#define SIZE 5

template <typename T> class Stack {
   public:

   ~Stack();
   void Push(const T &a); //Помещение объекта в стек;
   const T Pop(); // Извлечение объекта из стека;
   int Size(); // Получение размерности стека.

   private:
   
   struct Node // элемент односвязного списка
	{
		const T b; // значение

		Node *prev_ = nullptr; // указатель на предыдущий элемент
	};
   Node *back_ = nullptr; // последний элемент стека
   int sz = 0; // изначальная размерность

};

template <class T> Stack<T>::~Stack()
{
    //Clear();
}

template <class T> void Stack<T>::Push(const T &a)
{
	Node *node = new Node{ a, back_ }; // создаем новое звено, предыдущее для которого - последнее на данный момент звено

	if (node == nullptr) 
	{
		throw EStackException("Lack of memory."); // случай, если для элемента не выделилась память
	}

	back_ = node; // делаем только что созданное звено последним

    sz++; // размерность стека
}
