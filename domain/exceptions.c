#include <string.h>
#include "exceptions.h"

Exception MakeException(char *message)
{
	/*
	 * creates an exception instance
	 *
	 * param message: the message
	 *
	 * returns: exception instance
	 */
	Exception temp;
	strcpy(temp.message, message);
	return temp;
}
