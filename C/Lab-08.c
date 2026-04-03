#include <stdio.h>
// Given prototypes of function.
int sum(int array[], int asize); // returns the sum of the elements of a one dimensional array.
int swap( int *pA, int *pB ); // returns a 1 if the integer stored at *pA is greater then the integer stored at *pB and swaps the two integers. returns 0 otherwise.
int sort_1pass(int array[], int asize ); // makes one pass through the array, swapping pairs of values that are not in ascending order, using the swap() function above. Returns a 1 if any values were swapped and returns 0 otherwise.
void sort(int array[], int asize); // sorts the values in array in ascending order using sort_1pass(). 
void printarray(int array[], int asize); // prints the contents of the array on one line.
// As instructed I used preprocessor #define to set array size = 11.
#define array_size 11

int main(){
    int array[array_size] ={1,8,2,0,1,0,7,6,4,0,4}; // Array of size 11 with integers of my ID.
    printarray(array, array_size); 
    // Calculated sum of array with function sum() and printed it.
    int sum1=sum(array, array_size); 
    printf("Sum: %d\n", sum1);
    // Sorted array with sort() function and used printarray() function to display it.
    printf("Sorting array:\n");
    sort(array, array_size);
    printf("Sorted: ");
    printarray(array, array_size);
    // Median is the middle element of the sorted array, which is the element at index array_size/2.
    int median=array[array_size/2];
    printf("Median: %d\n", median);
    // Average is the sum of the elements divided by the number of elements, which is array_size.
    double average=sum1/11.0;
    printf("Average: %lf", average);
    
    return 0;
}

// Function definitions for the prototypes declared above.
// To calculate sum of array, I used for loop to iterate through the array and add each element to sum variable, which is returned at the end.
int sum(int array[], int asize){
    int sum=0;
    for(int i=0;i<asize;i++){
        sum=sum+array[i];
    }
    return sum;
}

// To swap two integers, I used a temporary variable to hold one of the values while swapping.
// If swapping is done, function returns 1, otherwise it returns 0.
int swap(int *pA, int *pB){
    if(*pA>*pB){
        int tmp=*pA;
        *pA=*pB;
        *pB=tmp;
        return 1;
    }
    else {return 0;}
}

// To sort array for 1 pass, I used for loop in which for loop goes over array one time and uses function swap() to copare every element.
// After one for loop, biggest number will be at the end of array.
// So when called multiple times it will sort the array completely.
// If array is sorted completely function will return swapped=0, which means array's sorting is done and tells sort() function to stop while loop. 
// If array is not completely sorted it will return swapped=1, which means array is not sorted yet and while loop should continue sorting.
int sort_1pass(int array[], int size_minus_one ){
    int swapped=0;
    for(int i=0;i<size_minus_one;i++){
        if(swap(&array[i], &array[i+1])) swapped=1;
    }
    printarray(array, array_size);
    return swapped;
}
// While 'while' loop is active it will repeatedly call sort_1pass() function which itself calls swap() function to swap integers if certain condition is met. 
void sort(int array[], int asize){
    int swapping=1;
    int times_swapped=0;
    while(swapping==1){
        swapping=sort_1pass(array, asize-1-times_swapped);
        times_swapped++;
    }
}
// Void function which prints array with for loop.
// Used this function everytime printing array was needed.
void printarray(int array[], int asize){
    for(int i=0;i<asize;i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}
