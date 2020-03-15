#include "../domain/exceptions.h"
#include "../domain/entities.h"
#include "../infrastructure/lists.h"

Exception AddStock(List *list, Stock stock);

Exception ModifyStock(List *list, Stock oldStock, Stock newStock);

Exception DeleteStock(List *list, Stock stock);

List NameStartsWithLetter(List *list, char letter);

List MaximumQuantity(List *list, int number);

List OrderByName(List *list, int order);

List OrderByQuantity(List *list, int order);
