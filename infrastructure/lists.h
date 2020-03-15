#pragma once
#include "../domain/entities.h"

typedef struct
{
	Stock values[100];
	int length;
} List;

List MakeList();

void Append(List* list, Stock stock);

Stock GetFromIndex(List* list, int index);

void* GetStock(List *list, char *name);

void Delete(List *list, Stock stock);
