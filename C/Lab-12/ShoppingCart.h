#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "ItemToPurchase.h"


typedef struct ShoppingCart_struct {
   char customerName [50];
   char currentDate [50];
   ItemToPurchase cartItems [10];
   int cartSize;
} ShoppingCart;


ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart);
ShoppingCart RemoveItem(char name[], ShoppingCart cart);
ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart cart);
int GetNumItemsInCart(ShoppingCart cart);
int GetCostOfCart(ShoppingCart cart);
void PrintTotal(ShoppingCart cart);
void PrintDescriptions(ShoppingCart cart);

#endif

