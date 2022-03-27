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

   ~Stack(); // деструктор
   void Push(const T &a); // Помещение объекта в стек;
   const T Pop(); // Извлечение объекта из стека;

   void ForEach(std::function<void(const T &value)> d) const; // функция перебора всех имеющихся значений,

   int Size(); // размерность стека

   private:
   
   struct Node // элемент односвязного списка
	{
		const T b; // значение

		Node *prev_ = nullptr; // указатель на предыдущий элемент
    };
   Node *back_ = nullptr; // последний элемент стека
   int size = 0; // изначальная размерность
};

template <class T> Stack<T>::~Stack()
{
    while (back_ != nullptr) // пока в стеке не закончились элементы
        {
            Node *tmp = back_; // сохраняем последний элемент
            back_ = back_->prev_; // делаем последним элементом предпоследний
            delete tmp; // удаляем указатель на последний элемент
        }
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

    size--; // уменьшается размерность

    return value; // возвращаем сохраненое значение звена
}

template <class T> int Stack<T>::Size()
{
    return size; // возвращаем известную размерность стека
}

template <class T> void Stack<T>::ForEach(std::function<void(const T &value)> d) const
{
    Node *k = back_; // начинаем с последнего элемента, т.к. это стек

    while (k != nullptr) // пока элементы существуют
    {
        d(k->b); // вызов функции обратной связи
        k = k->prev_;
    }
}

#endif
