#include <stdio.h>
#include <string.h>
#include "../domain/exceptions.h"
#include "../domain/validators.h"
#include "../domain/entities.h"
#include "../infrastructure/lists.h"

Exception AddStock(List *list, Stock stock)
{
	/*
	 * adds the given stock to the list after validation
	 *
	 * param list: the list
	 * param stock: the stock
	 *
	 * returns: exception
	 */
	Exception excTemp = ValidateStockInList(list, stock);
	if (strcmp("", excTemp.message) == 0)
		Append(list, stock);	
	return excTemp;
}

Exception ModifyStock(List *list, Stock oldStock, Stock newStock)
{
	/*
	 * modifies the given stock from the list after validations
	 *
	 * param list: the list
	 * param oldStock: the stock to be modified
	 * param newStock: the new stock's values
	 *
	 * returns: exception
	 */
	Exception excTempOld = ValidateStock(oldStock);
	Exception excTempNew = ValidateStock(newStock);
	char message[100];
	strcpy(message, excTempOld.message);
	strcat(message, "\n");
	strcat(message, excTempNew.message);
	Exception excTemp = MakeException(message);
	if (strcmp("\n", excTemp.message) == 0)
	{
		Stock *stock = (Stock*)GetStock(list, oldStock.name);
		if (stock != NULL)
		{
			Delete(list, oldStock);
			Append(list, newStock);
		}
	}
	return excTemp;
}

Exception DeleteStock(List *list, Stock stock)
{
	/*
	 * deletes the given stock from the list after validation
	 *
	 * param list: the list
	 * param stock: the stock
	 *
	 * returns: exception
	 */
	Exception excTemp = ValidateStock(stock);
	if (strcmp("", excTemp.message) == 0)
		Delete(list, stock);
	return excTemp;
}

List NameStartsWithLetter(List *list, char letter)
{
	/*
	 * gets all stocks that have the name starting with the given letter
	 *
	 * param list: the list
	 * param letter: the letter
	 *
	 * returns: list of stock
	 */
	List listTemp = MakeList();
	for (int i=0; i<list->currentLength; i++)
		if (letter == list->values[i].name[0])
			Append(&listTemp, list->values[i]);
	return listTemp;
}

List MaximumQuantity(List *list, int number)
{
	/*
	 * gets all stock that have quantity less than given number
	 *
	 * param list: the list
	 * param number: maximum quantity
	 *
	 * returns: list of stock
	 */
	List listTemp = MakeList();
	for (int i=0; i<list->currentLength; i++)
		if (number > list->values[i].quantity)
			Append(&listTemp, list->values[i]);
	return listTemp;
}

List OrderByName(List *list, int order)
{
	/*
	 * gets all stock ordered by name in the given order
	 *
	 * param list: the list
	 * param order: positive for ascending, negative for descending
	 *
	 * returns: list of stock
	 */
	List *listTemp = list;
	for (int i=0; i<listTemp->currentLength-1; i++)
	{
		for (int j=i+1; j<listTemp->currentLength; j++)
		{
			if (strcmp(listTemp->values[i].name, listTemp->values[j].name) * order > 0)
			{
				Stock auxStock = listTemp->values[i];
				listTemp->values[i] = listTemp->values[j];
				listTemp->values[j] = auxStock;
			}
		}
	}
	return *listTemp;
}

List OrderByQuantity(List *list, int order)
{
	/*
	 * gets all stock ordered by quantity in the given order
	 *
	 * param list: the list
	 * param order: positive for ascending, negative for descending
	 *
	 * returns: list of stock
	 */
	List *listTemp = list;
	for (int i=0; i<listTemp->currentLength-1; i++)
	{
		for (int j=i+1; j<listTemp->currentLength; j++)
		{
			if ((listTemp->values[i].quantity - listTemp->values[j].quantity) * order > 0)
			{
				Stock auxStock = listTemp->values[i];
				listTemp->values[i] = listTemp->values[j];
				listTemp->values[j] = auxStock;
			}
		}
	}
	return *listTemp;
}
