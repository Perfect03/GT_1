#include <iostream>
#include <string>
 
using namespace std;

#define SIZE 5

template <typename T> class Stack {
   public:

   ~Stack();
   void Push(const T &value); //Помещение объекта в стек;
   const T Pop(); // Извлечение объекта из стека;
   int Size(); // Получение размерности стека.

   private:
   
   struct Node // элемент односвязного списка
	{
		const T value_; // значение

		Node *prev_ = nullptr; // указатель на предыдущий элемент
	};

   int sz = 0; // изначальная размерность

};