#include <string.h>
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
	strcpy(temp.name, name);
	strcpy(temp.supplier, supplier);
	temp.quantity = quantity;
	return temp;
}
