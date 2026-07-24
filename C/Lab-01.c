// Removed every newline indicator from inputted strings because I needed to check if user inputted "-1". 
// Assumed none of the input string will be bigger than 49 character. 
// Assumed not more than 50 data point will be created
// After 'fgets' is done every string at end will have \n because of when we press "enter" at end of the line.
// So I Replaced every newline with '\0'.
// Which will be useful later in the code
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(){

    char title[50], col_1_Header[50], col_2_Header[50], data_String_Array[50][50]; // Array which will hold inputted strings.
    int data_Integer, data_Integer_Array[50], position=0;

    printf("Enter a title for the data: \n");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';
    printf("\nYou entered: %s\n", title);
    
    printf("\nEnter the column 1 header: \n");
    fgets(col_1_Header, sizeof(col_1_Header), stdin);
    col_1_Header[strcspn(col_1_Header, "\n")] = '\0';
    printf("\nYou entered: %s\n", col_1_Header);
    
    printf("\nEnter the column 2 header: \n");
    fgets(col_2_Header, sizeof(col_2_Header), stdin);
    col_2_Header[strcspn(col_2_Header, "\n")] = '\0';
    printf("\nYou entered: %s\n", col_2_Header);

    printf("Enter a data point (-1 to stop input): \n");
    // Loop continues before user inputs "-1" or number of times inputted reaches 50 and program breaks while loop.
    while(true){
        int data_Integer;
        char data_Point[100], data_String[50];
        fgets(data_Point, sizeof(data_Point), stdin);
        data_Point[strcspn(data_Point, "\n")] = '\0';
        if(strcmp(data_Point, "-1")==0 || position==50){
            break;
        }
        //To Work around given example I did this: 
        //I stored everything before comma to data_String and after comma into data_Integer.
        //    It will fail if comma isn't in the sentence.
        sscanf(data_Point, "%[^,], %d", data_String, &data_Integer);
        printf("\nData String: %s\n", data_String);    
        printf("Data Integer: %d\n", data_Integer);
        //Store stuff to array with matching positions.
        strcpy(data_String_Array[position], data_String);
        data_Integer_Array[position]=data_Integer;
        position++;
    }

    // 4 - Outputting the information in a formatted table.
    printf("%33s\n", title);
    printf("%-20s | %23s\n", col_1_Header, col_2_Header);
    //width of whole line is 46 -> 20 from left 23 from right and width of '|' is 3, so 20+23+3=46;
    for(int i=0;i<46;i++){
        printf("-");
    }
    printf("\n");
    for(int i=0;i<position;i++){
        printf("%-20s | %23d\n", data_String_Array[i], data_Integer_Array[i]);
    }

    printf("\n\n\n");
    
    //5 - Output the information as a formatted histogram.
    for(int i=0;i<position;i++){
        printf("%20s ", data_String_Array[i]);
        for(int j=0;j<=data_Integer_Array[i];j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}