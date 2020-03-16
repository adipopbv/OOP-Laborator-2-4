#pragma once

typedef struct
{
	char* name;
	char* supplier;
	int quantity;
} Stock;

Stock MakeStock(char *name, char *supplier, int quantity);

void DeconstructStock(Stock* stock);
