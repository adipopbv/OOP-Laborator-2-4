#include "./exceptions.h"
#include "./entities.h"
#include "../infrastructure/lists.h"
#include <string.h>

Exception ValidateStockInList(List *list, Stock stock)
{
	/*
	 * validates a stock instance with list searching
	 *
	 * param list: the list to search into
	 * param stock: the stock to validate
	 *
	 * returns: exception instance
	 */
	Exception excTemp = MakeException("");
	if (GetStock(list, stock.name) != NULL)
		strcat(excTemp.message, "Name already in repo!\n");
	if (strcmp("", stock.supplier) == 0 || strcmp("\n", stock.supplier) == 0)
		strcat(excTemp.message, "Invalid supplier!\n");
	if (stock.quantity <= 0)
		strcat(excTemp.message, "Invalid quantity!\n");
	return excTemp;
}

Exception ValidateStock(Stock stock)
{
	/*
	 * validates a stock instance
	 *
	 * param stock: the stock to validate
	 *
	 * returns: exception instance
	 */
	Exception excTemp = MakeException("");
	if (strcmp("", stock.name) == 0 || strcmp("\n", stock.name) == 0)
		strcat(excTemp.message, "Invalid name!\n");
	if (strcmp("", stock.supplier) == 0 || strcmp("\n", stock.supplier) == 0)
		strcat(excTemp.message, "Invalid supplier!\n");
	if (stock.quantity <= 0)
		strcat(excTemp.message, "Invalid quantity!\n");
	return excTemp;
}
