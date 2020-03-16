#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "lists.h"
#include "../domain/entities.h"

void test_Append()
{
	List list = MakeList();
	Stock stock = MakeStock("ceva", "cineva", 12);
	Append(&list, stock);
	assert(strcmp(list.values[0].name, stock.name) == 0);
	DeconstructList(&list);
}

void test_GetFromIndex()
{
	List list = MakeList();
	Stock stock = MakeStock("ceva", "cineva", 12);
	Append(&list, stock);
	assert(strcmp(GetFromIndex(&list, 0).name, stock.name) == 0);
	DeconstructList(&list);
}

void test_GetStock()
{
	List list = MakeList();
	Stock stock = MakeStock("ceva", "cineva", 12);
	Append(&list, stock);
	Stock *new = (Stock*)GetStock(&list, "ceva");
	assert(strcmp(new->name, stock.name) == 0);
	new = (Stock*)GetStock(&list, "cv");
	assert(new == NULL);
	DeconstructList(&list);
}

void test_Delete()
{
	List list = MakeList();
	Stock stock = MakeStock("ceva", "cineva", 12);
	Stock stock2 = MakeStock("lala", "lalala", 14);
	Append(&list, stock);
	Stock *new = (Stock*)GetStock(&list, "ceva");
	assert(strcmp(new->name, stock.name) == 0);
	Delete(&list, stock);
	DeconstructStock(&stock);
	new = (Stock*)GetStock(&list, "ceva");
	assert(new == NULL);
	Delete(&list, stock2);
	new = (Stock*)GetStock(&list, "lala");
	assert(new == NULL);
	DeconstructList(&list);
	DeconstructStock(&stock2);
}

void RunAllListTests()
{
	test_Append();
	test_GetFromIndex();
	test_GetStock();
	test_Delete();
}
