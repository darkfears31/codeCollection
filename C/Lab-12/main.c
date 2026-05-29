#include<stdio.h>
#include<string.h>

#include "ShoppingCart.h"

void PrintMenu() {
  printf("MENU\n");
  printf("a - Add item to cart\n");
  printf("r - Remove item from cart\n");
  printf("c - Change quantity of item\n");
  printf("i - Print items descriptions\n");
  printf("o - Output shopping cart\n");
  printf("q - Quit the program\n");
}

ShoppingCart ExecuteMenu(char option, ShoppingCart theCart) {
  char name[50] = "";
  char descr[50] = "";
  int price = 0;
  int quantity = 0;
  int i = 0;
  char c = ' ';
  ItemToPurchase theItem;
   
  switch (option) {
    case 'a':
        while ((c = getchar()) != EOF && c != '\n');
        printf("ADD ITEM TO CART\n");
        printf("Enter the item name:\n");
        fgets(name, 50, stdin);

        i = 0;
        while (name[i] != '\n') {
          theItem.itemName[i] = name[i];
          ++i;
        }
        theItem.itemName[i] = '\0';

        printf("Enter the item description:\n");
        fgets(theItem.itemDescription, 50, stdin);
        i = 0;
        while (theItem.itemDescription[i] != '\n') {
            ++i;
        }
        theItem.itemDescription[i] = '\0';

        printf("Enter the item price:\n");
        scanf("%d", &price);
        theItem.itemPrice = price;

        printf("Enter the item quantity:\n");
        scanf("%d", &theItem.itemQuantity);

        theCart = AddItem(theItem, theCart);
        printf("\n");
        break;
    case 'r':
        while ((c = getchar()) != EOF && c != '\n');
  
        printf("REMOVE ITEM FROM CART\n");
        printf("Enter name of item to remove:\n");
        fgets(name, 50, stdin);
  
        i = 0;
        while (name[i] != '\n') {
          ++i;
        }
        name[i] = '\0';
  
        theCart = RemoveItem(name, theCart);
        printf("\n");
        break;
    case 'c':
        MakeItemBlank(&theItem);
        while ((c = getchar()) != EOF && c != '\n');

        printf("CHANGE ITEM QUANTITY\n");
        printf("Enter the item name:\n");
        fgets(name, 50, stdin);

        i = 0;
        while (name[i] != '\n') {
          theItem.itemName[i] = name[i];
          ++i;
        }
        theItem.itemName[i] = '\0';

        printf("Enter the new quantity:\n");
        scanf("%d", &quantity);

        theItem.itemQuantity = quantity;

        theCart = ModifyItem(theItem, theCart);

        printf("\n");
        break;
  
    case 'i':
        printf("Printing Descriptions:\n");
        PrintDescriptions(theCart);
        printf("\n");
        break;
  
    case 'o':
        printf("Printing total cost of items:\n");
        PrintTotal(theCart);
        printf("\n");
        break;
  }
  return theCart;
}

int main(void) {
   char custName[50] = "";
   char dayDate[50] = "";
   char menuChoice = ' ';
   int i = 0;

   ShoppingCart myCart;

   printf("Enter Customer's Name:\n");
   fgets(custName, 50, stdin);

   printf("Enter Today's Date:\n");
   fgets(dayDate, 50, stdin);

   printf("\nCustomer Name: %s\n", custName);
   printf("Today's Date: %s\n", dayDate);

   while (custName[i] != '\n') {
      myCart.customerName[i] = custName[i];
      ++i;
   }
   myCart.customerName[i] = '\0';

   i = 0;
   while (dayDate[i] != '\n') {
      myCart.currentDate[i] = dayDate[i];
      ++i;
   }
   myCart.currentDate[i] = '\0';
   myCart.cartSize = 0;

   PrintMenu();
   while(menuChoice != 'q') {
      printf("Choose an option:\n");
      scanf(" %c", &menuChoice);
      if (menuChoice == 'a' || menuChoice == 'r' || menuChoice == 'c' ||
          menuChoice == 'i' || menuChoice == 'o') {
         myCart = ExecuteMenu(menuChoice, myCart);
         PrintMenu();
      }
   }

   return 0;
}

