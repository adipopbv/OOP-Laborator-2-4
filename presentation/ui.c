#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../domain/entities.h"
#include "../infrastructure/lists.h"
#include "../domain/exceptions.h"
#include "../domain/validators.h"
#include "../business/services.h"

void PrintException(Exception exception)
{
	/*
	 * prints an exception
	 *
	 * param exception: the exception
	 *
	 * returns: nothing
	 */
	printf("%s", exception.message);
}

void PrintStock(Stock stock)
{
	/*
	 * prints a stock's instance values
	 *
	 * param stock: the stock
	 *
	 * returns: nothing
	 */
	printf("Name: %s", stock.name);
	printf("Supplier: %s", stock.supplier);
	printf("Quantity: %d\n", stock.quantity);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void ShowMenu()
{
	/*
	 * prints the command menu
	 *
	 * returns: nothing
	 */
	printf("~ BAKERY APP ~\n\n");
	printf("Commands:\n");
	printf("[1]: Add stock;\n");
	printf("[2]: Modify stock;\n");
	printf("[3]: Delete stock;\n");
	printf("[4]: Get stock by criteria;\n");
	printf("[5]: Get stock ordered by name or quantity;\n");
	printf("[6]: Exit app.\n\n");
}

Stock ReadStock()
{
	/*
	 * reads a stock from the console
	 *
	 * returns: a stock
	 */
	char text[20], name[20], supplier[20];
	int quantity = 0;

	printf("Please input:\nName: ");
	fgets(name, 20, stdin);
	printf("Supplier: ");
	fgets(supplier, 20, stdin);
	printf("Cantitate: ");
	fgets(text, 20, stdin);
	quantity = atoi(text);

	return MakeStock(name, supplier, quantity);
}

void RunUI()
{
	/*
	 * runs the application interface and functionality
	 *
	 * returns: nothing
	 */
	printf("Application started... \n\n");
	
	char text[256];
	int command = 0;
	List stockList = MakeList();

	while (1)
	{
		ShowMenu();
		
		printf("Input a command: ");
		fgets(text, 256, stdin);
		command = atoi(text);
		printf("\n");

		if (command <= 0 || command >= 7)
		{
			printf("Invalid command!\n\n");
			continue;
		}
		else if (command == 1)
		{
			Stock stock = ReadStock();
			Exception excTemp = AddStock(&stockList, stock);
			if (strcmp("", excTemp.message) != 0)
				PrintException(excTemp);
		}
		else if (command == 2)
		{
			Stock oldStock = ReadStock();
			Stock newStock = ReadStock();
			Exception excTemp = ModifyStock(&stockList, oldStock, newStock);
			if (strcmp("", excTemp.message) != 0)
				PrintException(excTemp);
		}
		else if (command == 3)
		{
			Stock stock = ReadStock();
			Exception excTemp = DeleteStock(&stockList, stock);
			if (strcmp("", excTemp.message) != 0)
				PrintException(excTemp);
		}
		else if (command == 4)
		{
			printf("Choose criteria: \n");
			printf("  [1]: Name starts with letter;\n");
			printf("  [2]: Maximum quantity.\n\n");
			printf("  Please input a command: ");
			fgets(text, 256, stdin);
			command = atoi(text);
			if (command == 1)
			{
				printf("  Please input a letter: ");
				fgets(text, 256, stdin);
				List listTemp = NameStartsWithLetter(&stockList, text[0]);
				if (listTemp.currentLength == 0)
					printf("No item found!\n");
				else
				{
					printf("\n~~~~~~~~~~~~~~~~~~~~~~~~\n");
					for (int i=0; i<listTemp.currentLength; i++)
						PrintStock(listTemp.values[i]);
					printf("\n");
				}
			}
			else 
			{
				printf("  Please input a number: ");
				fgets(text, 256, stdin);
				int number = atoi(text);
				List listTemp = MaximumQuantity(&stockList, number);
				if (listTemp.currentLength == 0)
					printf("No item found!\n");
				else
				{
					printf("\n~~~~~~~~~~~~~~~~~~~~~~~~\n");
					for (int i=0; i<listTemp.currentLength; i++)
						PrintStock(listTemp.values[i]);
					printf("\n");
				}
			}
		}
		else if (command == 5)
		{
			printf("Choose criteria: \n");
			printf("  [1]: Name;\n");
			printf("  [2]: Quantity.\n\n");
			printf("  Please input a command: ");
			fgets(text, 256, stdin);
			command = atoi(text);
			if (command == 1)
			{
				printf("Order: ");
				fgets(text, 256, stdin);
				int order = atoi(text);
				List listTemp = OrderByName(&stockList, order);
				printf("\n~~~~~~~~~~~~~~~~~~~~~~~~\n");
				for (int i=0; i<listTemp.currentLength; i++)
					PrintStock(listTemp.values[i]);
				printf("\n");
			}
			else
			{
				printf("Order: ");
				fgets(text, 256, stdin);
				int order = atoi(text);
				List listTemp = OrderByQuantity(&stockList, order);
				printf("\n~~~~~~~~~~~~~~~~~~~~~~~~\n");
				for (int i=0; i<listTemp.currentLength; i++)
					PrintStock(listTemp.values[i]);
				printf("\n");
			}
		}
		else if (command == 6)
		{
			DeconstructList(&stockList);		
			return;
		}
	}
}
