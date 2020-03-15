#pragma once

typedef struct
{
	char message[256];
} Exception;

Exception MakeException(char *message);	
