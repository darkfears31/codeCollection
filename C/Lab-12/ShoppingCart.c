#include<stdio.h>
#include<string.h>
#include "ShoppingCart.h"

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart) {
  // Add Item to cart using cartSize.
  cart.cartItems[cart.cartSize] = item;
  // Make sure to increase the size.
  cart.cartSize++;
  return cart;
}

ShoppingCart RemoveItem(char name[], ShoppingCart cart) {
   int i = 0;
   int posItem = 0;
   int cartSize = cart.cartSize;
   int found = 0;
   
   for(i = 0; i < cartSize; ++i) {
      if(strcmp(cart.cartItems[i].itemName, name) == 0) {
         found = 1;
         posItem = i;
         if(i != (cartSize - 1)) {
            cart.cartItems[i] = cart.cartItems[i + 1];
         }  
      }
      
      if(i > posItem && i != (cartSize - 1) && found) {
         cart.cartItems[i] = cart.cartItems[i + 1];
      }
   }
   
   if(!found) {
      printf("Item not found in cart. Nothing removed.\n");
   }
   
   if(found) {
      --cart.cartSize;
   }
      
   return cart;   
}

ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart cart) {
   int i = 0;
   int found = 0;
   
   for(i = 0; i < cart.cartSize; ++i) {
      if(strcmp(cart.cartItems[i].itemName, item.itemName) == 0) {
         found = 1;
         if(strcmp(item.itemDescription, "none") != 0) {
            strcpy(cart.cartItems[i].itemDescription, item.itemDescription);
         } 
         
         if(item.itemPrice != 0) {
            cart.cartItems[i].itemPrice = item.itemPrice;
         }
         
         if(item.itemQuantity != 0) {
            cart.cartItems[i].itemQuantity = item.itemQuantity;
         }
      }
   }
   
   if(!found) {
      printf("Item not found in cart. Nothing modified.\n");
   }
   
   return cart;
}

int GetNumItemsInCart(ShoppingCart cart) {
  int numItems = 0;
  for(int i=0; i<cart.cartSize;i++){
    // Number of items is equal to
    // sum of each items (in cart) quantity.
    numItems = numItems + cart.cartItems[i].itemQuantity;
  }
  return numItems;
}

int GetCostOfCart(ShoppingCart cart) {
  int totalCost = 0;
  for(int i=0;i<cart.cartSize;i++){
    // Total Cost is equal to 
    // each item in cart multiplied by their own price.
    totalCost = totalCost + (cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice);
  }
  return totalCost;
}

void PrintTotal(ShoppingCart cart) {
   int i = 0;
   int totalCost = 0;
   
   printf("%s's Shopping Cart - %s\n", cart.customerName, cart.currentDate);
   printf("Number of Items: %d\n\n", GetNumItemsInCart(cart));
   
   if (cart.cartSize > 0) {
      for (i = 0; i < cart.cartSize; ++i) {
         PrintItemCost(cart.cartItems[i]);
      }
   }
   
   else {
      printf("SHOPPING CART IS EMPTY\n");
   }
   
   totalCost = GetCostOfCart(cart);
   
   printf("\nTotal: $%d\n", totalCost);
}

void PrintDescriptions(ShoppingCart cart) {
   int i = 0;
   
   printf("%s's Shopping Cart - %s\n\n", cart.customerName, cart.currentDate);
   printf("Item Descriptions\n");
   
   if (cart.cartSize > 0) {
      for (i = 0; i < cart.cartSize; ++i) {
         PrintItemDescription(cart.cartItems[i]);
      }
   }
   
   else {
      printf("SHOPPING CART IS EMPTY\n");
   }
}

