#ifndef ESTACKEXCEPTION_H
#define ESTACKEXCEPTION_H
#include <string.h>

class EStackException
{
public:
	EStackException(const char *msg)
	{
		_msg = new char[strlen(msg) + 1]; // память под сообщение об ошибке

        _msg = strdup(msg);
	}
	EStackException(const EStackException &obj)
	{
		_msg = new char[strlen(obj._msg) + 1];

    _msg = strdup(obj._msg);
	}
	~EStackException()
	{
		delete _msg;
	}

    const char *m() const { return _msg; }

private:
	char *_msg;
};

#endif
