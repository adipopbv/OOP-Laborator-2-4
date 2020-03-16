#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../domain/exceptions.h"
#include "../domain/validators.h"
#include "../domain/entities.h"
#include "../infrastructure/lists.h"
#include "services.h"

void test_AddStock()
{
	List list = MakeList();
	Stock stock = MakeStock("ceva", "cineva", 12);
	Stock stock2 = MakeStock("ceva", "\n", -15);
	Exception e = MakeException("");
	assert(strcmp(AddStock(&list, stock).message, e.message) == 0);
	assert(strcmp(list.values[0].name, stock.name) == 0);
	assert(strcmp(AddStock(&list, stock2).message, e.message) != 0);
	assert(list.currentLength == 1);
	DeconstructList(&list);
	DeconstructStock(&stock2);
}

void test_ModifyStock()
{
	List list = MakeList();
	Stock stock = MakeStock("ceva", "cineva", 12);
	Stock stock2 = MakeStock("ceva", "lalala", 15);
	Stock stock3 = MakeStock("", "", -15);
	Exception e = MakeException("\n");
	Append(&list, stock);
	assert(strcmp(ModifyStock(&list, stock, stock3).message, e.message) != 0);
	assert(strcmp(list.values[0].name, stock3.name) != 0);
	DeconstructStock(&stock3);
	assert(strcmp(ModifyStock(&list, stock, stock2).message, e.message) == 0);
	assert(strcmp(list.values[0].name, stock2.name) == 0);
	DeconstructStock(&stock);
	DeconstructList(&list);
}

void test_DeleteStock()
{
	List list = MakeList();
	Stock stock = MakeStock("ceva", "cineva", 11);
	Stock stock2 = MakeStock("ceva2", "cineva2", 12);
	Stock stock3 = MakeStock("ceva3", "cineva3", 13);
	Exception e = MakeException("");
	Append(&list, stock);
	assert(strcmp(DeleteStock(&list, stock).message, e.message) == 0);
	assert(strcmp(list.values[list.currentLength].name, stock.name) == 0);
	DeconstructStock(&stock);
	Append(&list, stock2);
	Append(&list, stock3);
	assert(strcmp(DeleteStock(&list, stock2).message, e.message) == 0);
	assert(strcmp(list.values[0].name, stock2.name) != 0);
	DeconstructList(&list);
	DeconstructStock(&stock2);
}

void test_NameStartsWithLetter()
{
	List list = MakeList();
	Stock stock = MakeStock("ceva", "cineva", 12);
	Stock stock2 = MakeStock("ceva", "cineva", 12);
	Stock stock3 = MakeStock("deva", "cineva", 12);
	Append(&list, stock);
	Append(&list, stock2);
	Append(&list, stock3);
	List temp = NameStartsWithLetter(&list, 'c');
	assert(strcmp(temp.values[0].name, stock.name) == 0);
	assert(strcmp(temp.values[1].name, stock2.name) == 0);
	DeconstructList(&list);
	free(temp.values);
}

void test_MaximumQuantity()
{
	List list = MakeList();
	Stock stock = MakeStock("ceva", "cineva", 12);
	Stock stock2 = MakeStock("ceva", "cineva", 22);
	Stock stock3 = MakeStock("deva", "cineva", 32);
	Append(&list, stock);
	Append(&list, stock2);
	Append(&list, stock3);
	List temp = MaximumQuantity(&list, 20);
	assert(strcmp(temp.values[0].name, stock.name) == 0);
	DeconstructList(&list);
	free(temp.values);
}

void test_OrderByName()
{
	List list = MakeList();
	Stock stock = MakeStock("beva", "cineva", 12);
	Stock stock2 = MakeStock("ceva", "cineva", 22);
	Stock stock3 = MakeStock("deva", "cineva", 32);
	Append(&list, stock);
	Append(&list, stock2);
	Append(&list, stock3);
	assert(strcmp(OrderByName(&list, 1).values[0].name, stock.name) == 0);
	assert(strcmp(OrderByName(&list, 1).values[1].name, stock2.name) == 0);
	assert(strcmp(OrderByName(&list, 1).values[2].name, stock3.name) == 0);
	assert(strcmp(OrderByName(&list, -1).values[0].name, stock3.name) == 0);
	assert(strcmp(OrderByName(&list, -1).values[1].name, stock2.name) == 0);
	assert(strcmp(OrderByName(&list, -1).values[2].name, stock.name) == 0);
	DeconstructList(&list);
}

void test_OrderByQuantity()
{
	List list = MakeList();
	Stock stock = MakeStock("beva", "cineva", 12);
	Stock stock2 = MakeStock("ceva", "cineva", 22);
	Stock stock3 = MakeStock("deva", "cineva", 32);
	Append(&list, stock);
	Append(&list, stock2);
	Append(&list, stock3);
	assert(strcmp(OrderByQuantity(&list, 1).values[0].name, stock.name) == 0);
	assert(strcmp(OrderByQuantity(&list, 1).values[1].name, stock2.name) == 0);
	assert(strcmp(OrderByQuantity(&list, 1).values[2].name, stock3.name) == 0);
	assert(strcmp(OrderByQuantity(&list, -1).values[0].name, stock3.name) == 0);
	assert(strcmp(OrderByQuantity(&list, -1).values[1].name, stock2.name) == 0);
	assert(strcmp(OrderByQuantity(&list, -1).values[2].name, stock.name) == 0);
	DeconstructList(&list);
}

void RunAllServiceTests()
{
	test_AddStock();
	test_ModifyStock();
	test_DeleteStock();
	test_NameStartsWithLetter();
	test_MaximumQuantity();
	test_OrderByName();
	test_OrderByQuantity();
}
