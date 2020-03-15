#pragma once

typedef struct
{
	char name[20];
	char supplier[20];
	int quantity;
} Stock;

Stock MakeStock(char *name, char *supplier, int quantity);
