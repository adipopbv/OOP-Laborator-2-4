#pragma once
#include "./exceptions.h"
#include "./entities.h"
#include "../infrastructure/lists.h"

Exception ValidateStockInList(List *list, Stock stock);

Exception ValidateStock(Stock stock);
