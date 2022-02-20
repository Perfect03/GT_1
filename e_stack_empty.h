#ifndef ESTACKEMPTY_H
#define ESTACKEMPTY_H

#include "e_stack_exception.h"

class EStackEmpty : public EStackException
{
public:
	EStackEmpty() : EStackException("A stack is empty.")
	{
	}

	// конструктор копирования
	EStackEmpty(const EStackEmpty &obj) : EStackException(obj)
	{
	}
};

#endif // ESTACKEMPTY_H
