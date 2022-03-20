#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <functional>
#include <list>

#include "e_stack_exception.h"
#include "e_stack_empty.h"
 
using namespace std;

template <typename T> class Stack {
   public:
   Stack(int = 5); // конструктор по умолчанию, по умолчанию стек содержит 5 узлов
   ~Stack();
   void Push(const T &a); //Помещение объекта в стек;
   void Print(); // Вывод элементов стека
   const T Pop(); // Извлечение объекта из стека;

   private:
   
   struct Node // элемент односвязного списка
	{
		const T b; // значение

		Node *prev_ = nullptr; // указатель на предыдущий элемент
	};
   T *stackPtr; // указатель на стек
   Node *back_ = nullptr; // последний элемент стека
   int size = 0; // изначальная размерность

};

template <typename T> Stack<T>::Stack(int maxSize) : size(maxSize) // конструктор
{
    stackPtr = new T[size];
    back_ = 0; // инициализируем текущий элемент нулем
}

template <class T> Stack<T>::~Stack()
{
    delete [] stackPtr;
}

template <class T> void Stack<T>::Push(const T &a)
{
	Node *node = new Node{ a, back_ }; // создаем новое звено, предыдущее для которого - последнее на данный момент звено

	if (node == nullptr) 
	{
		throw EStackException("Lack of memory."); // случай, если для элемента не выделилась память
	}

	back_ = node; // делаем только что созданное звено последним

    size++; // размерность стека
}

template <class T> void Stack<T>::Print()
{
    if (back_ == nullptr) // если стек пуст - ошибка
    {
        throw EStackEmpty();
    }

            else {
        Node* q=back_;
                while (q != nullptr)
                {
                    cout << q->b << ' ';
                    q = q->prev_;
                }
            }
}

template <class T> const T Stack<T>::Pop()
{
    if (back_ == nullptr) // если стек пуст - ошибка
    {
        throw EStackEmpty();
    }

    const T value = back_->b; // сохраняем значение узла

    Node *temp = back_; // сохраняем ссылку на узел

    back_ = back_->prev_; // перемещаем конец стека

    delete temp; // удаляем узел

    size--;

    return value; // возвращаем сохраненое значение звена
}

#endif