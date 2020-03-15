#include "lists.h"
#include "../domain/entities.h"
#include <string.h>

List MakeList()
{
	/*
	 * makes list instance
	 *
	 * returns: list instance
	 */
	List temp;
	temp.length = 0;
	return temp;
}

void Append(List* list, Stock stock)
{
	/*
	 * appends given stock instance to the list
	 *
	 * returns: nothing
	 */
	list->values[list->length++] = stock;
}

Stock GetFromIndex(List* list, int index)
{
	/*
	 * gets stock value from the list at the given index
	 *
	 * param list: the list
	 * param index: the index
	 *
	 * return stock value
	 */
	return list->values[index];
}

void* GetStock(List *list, char *name)
{
	/*
	 * gets instance of the stock with the given name from the list
	 *
	 * param list: the list
	 * param name: the name
	 *
	 * returs: an instance tho the stock or NULL
	 */
	for (int i=0; i<list->length; i++)
		if (strcmp(name, list->values[i].name) == 0)
			return &list->values[i];
	return NULL;
}

void Delete(List *list, Stock stock)
{
	/*
	 * deletes the given stock from the list
	 *
	 * param list: the list
	 * param stock: the stock
	 *
	 * returns: nothing
	 */
	int index = -1;
	for (int i=0; i<list->length; i++)
		if (strcmp(stock.name, list->values[i].name) == 0)
			index = i;
	if (index == -1)
		return;
	for (int i=index; i<list->length-1; i++)
		list->values[i] = list->values[i+1];
	list->length--;
}
