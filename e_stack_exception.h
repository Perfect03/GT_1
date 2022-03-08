#ifndef ESTACKEXCEPTION_H
#define ESTACKEXCEPTION_H
#include <cstring>

class EStackException
{
public:
	EStackException(const char *msg)
	{
		_msg = new char[strlen(msg) + 1]; // память под сообщение об ошибке

		strcpy(_msg, msg);
	}
	EStackException(const EStackException &obj)
	{
		_msg = new char[strlen(obj._msg) + 1];

		strcpy(_msg, obj._msg); 
	}
	~EStackException()
	{
		delete _msg;
	}

	const char *what() const { return _msg; }

private:
	char *_msg;
};

#endif