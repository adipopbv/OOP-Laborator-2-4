#include <stdio.h>
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
	assert(strcmp(list.values[1].name, stock2.name) != 0);
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
	assert(strcmp(ModifyStock(&list, stock, stock2).message, e.message) == 0);
	assert(strcmp(list.values[0].name, stock2.name) == 0);
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
	assert(strcmp(list.values[list.length].name, stock.name) == 0);
	Append(&list, stock2);
	Append(&list, stock3);
	assert(strcmp(DeleteStock(&list, stock2).message, e.message) == 0);
	assert(strcmp(list.values[0].name, stock2.name) != 0);
}

void test_NameStartsWithLetter()
{
	List list = MakeList();
	List list2 = MakeList();
	Stock stock = MakeStock("ceva", "cineva", 12);
	Stock stock2 = MakeStock("ceva", "cineva", 12);
	Stock stock3 = MakeStock("deva", "cineva", 12);
	Append(&list, stock);
	Append(&list, stock2);
	Append(&list, stock3);
	Append(&list2, stock);
	Append(&list2, stock2);
	for (int i=0; i<2; i++)
		assert(strcmp(NameStartsWithLetter(&list, 'c').values[i].name, list2.values[i].name) == 0);
}

void test_MaximumQuantity()
{
	List list = MakeList();
	List list2 = MakeList();
	Stock stock = MakeStock("ceva", "cineva", 12);
	Stock stock2 = MakeStock("ceva", "cineva", 22);
	Stock stock3 = MakeStock("deva", "cineva", 32);
	Append(&list, stock);
	Append(&list, stock2);
	Append(&list, stock3);
	Append(&list2, stock);
	assert(strcmp(MaximumQuantity(&list, 20).values[0].name, list2.values[0].name) == 0);
}

void test_OrderByName()
{
	List list = MakeList();
	List list2 = MakeList();
	Stock stock = MakeStock("beva", "cineva", 12);
	Stock stock2 = MakeStock("ceva", "cineva", 22);
	Stock stock3 = MakeStock("deva", "cineva", 32);
	Append(&list, stock);
	Append(&list, stock2);
	Append(&list, stock3);
	Append(&list2, stock3);
	Append(&list2, stock2);
	Append(&list2, stock);
	for (int i=0; i<3; i++)
	{
		assert(strcmp(OrderByName(&list, 1).values[i].name, list.values[i].name) == 0);
		assert(strcmp(OrderByName(&list, -1).values[i].name, list2.values[i].name) == 0);
	}
}

void test_OrderByQuantity()
{
	List list = MakeList();
	List list2 = MakeList();
	Stock stock = MakeStock("beva", "cineva", 12);
	Stock stock2 = MakeStock("ceva", "cineva", 22);
	Stock stock3 = MakeStock("deva", "cineva", 32);
	Append(&list, stock);
	Append(&list, stock2);
	Append(&list, stock3);
	Append(&list2, stock3);
	Append(&list2, stock2);
	Append(&list2, stock);
	for (int i=0; i<3; i++)
	{
		assert(strcmp(OrderByQuantity(&list, 1).values[i].name, list.values[i].name) == 0);
		assert(strcmp(OrderByQuantity(&list, -1).values[i].name, list2.values[i].name) == 0);
	}
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
