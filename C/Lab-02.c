#include <stdio.h>

int main() {
    // As said in the instructions, I set the initial balance to 1000, rate to 2% and year to 20.
    // If user doesn't input anything, it will use these default values. But if user inputs something, it will override the default values.
    double initial_balance=1000.0; 
    double rate=2.0;
    int years=20;

    printf("Enter initial balance: ");
    scanf("%lf", &initial_balance);

    printf("Enter annual interest rate (in percent): ");
    scanf("%lf", &rate);

    printf("Enter number of years: ");
    scanf("%d", &years);

    double daily = initial_balance, weekly = initial_balance, monthly = initial_balance, quarterly = initial_balance, annually = initial_balance;
    // before starting the loop, I printed the initial balances
    printf("\nYear  Daily     Weekly    Monthly   Quarterly Annually\n");
    printf("----  --------  --------  --------  --------- --------\n");
    // width of year is 2, because when it gets to 10, it will mess up the formatting.
    printf("%2d    %8.2lf  %8.2lf  %8.2lf  %8.2lf  %8.2lf\n", 0, daily, weekly, monthly, quarterly, annually); // Initial balances before interest
    for (int i = 1; i <= years; i++) { // Loop through each year
        // Daily compounding 
        for (int j = 0; j < 365; j++) {
            daily += daily * (rate / 100) / 365;
        }
        // Weekly compounding
        for (int j = 0; j < 52; j++) {
            weekly += weekly * (rate / 100) / 52;
        }
        // Monthly compounding
        for (int j = 0; j < 12; j++) {
            monthly += monthly * (rate / 100) / 12;
        }
        // Quarterly compounding
        for (int j = 0; j < 4; j++) {
            quarterly += quarterly * (rate / 100) / 4;
        }
        // Annually compounding
        annually += annually * (rate / 100);

        // print balances after each time period
        // print different balances
        printf("%2d    %8.2lf  %8.2lf  %8.2lf  %8.2lf  %8.2lf\n", i, daily, weekly, monthly, quarterly, annually);
    }
    return 0;
}