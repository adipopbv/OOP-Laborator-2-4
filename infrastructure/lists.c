#include "lists.h"
#include "../domain/entities.h"
#include <string.h>
#include <stdlib.h>

List MakeList()
{
	/*
	 * makes list instance
	 *
	 * returns: list instance
	 */
	List temp;
	temp.currentLength = 0;
	temp.maxLength = 1;
	temp.values = (Stock*)malloc(sizeof(Stock)*temp.maxLength);
	return temp;
}

void Append(List* list, Stock stock)
{
	/*
	 * appends given stock instance to the list
	 *
	 * returns: nothing
	 */
	if (list->currentLength >= list->maxLength)
	{
		int newLength = list->currentLength * 2;
		Stock* newValues = (Stock*)malloc(sizeof(Stock)*newLength);
		memcpy(newValues, list->values, list->currentLength * sizeof(Stock));
		list->maxLength = newLength;
		free(list->values);
		list->values = newValues;
	}
	list->values[list->currentLength++] = stock;
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
	for (int i=0; i<list->currentLength; i++)
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
	for (int i=0; i<list->currentLength; i++)
		if (strcmp(stock.name, list->values[i].name) == 0)
			index = i;
	if (index == -1)
		return;
	for (int i=index; i<list->currentLength-1; i++)
		list->values[i] = list->values[i+1];
	list->currentLength--;
}

void DeconstructList(List* list)
{
	for (int i=0; i<list->currentLength; i++)
		DeconstructStock(&list->values[i]);
	free(list->values);
	list->values = NULL;
	list->currentLength = list->maxLength = 0;
}
