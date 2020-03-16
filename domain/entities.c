#include <string.h>
#include <stdlib.h>
#include "entities.h"

Stock MakeStock(char *name, char *supplier, int quantity)
{
	/*
	 * creates a Stock instance from given data
	 *
	 * param name: the name
	 * param supplier: the supplier
	 * param quantity: the quantity
	 *
	 * returns: Stock instance
	 */
	Stock temp;
	temp.name = (char*)malloc(sizeof(char)*20);
	strcpy(temp.name, name);
	temp.supplier = (char*)malloc(sizeof(char)*20);
	strcpy(temp.supplier, supplier);
	temp.quantity = quantity;
	return temp;
}

void DeconstructStock(Stock *stock)
{
	if (stock->name != NULL)
		free(stock->name);
	if (stock->supplier != NULL)
		free(stock->supplier);
	stock->name = NULL;
	stock->supplier = NULL;
	stock->quantity = 0;
}
