//comparing swaps of Bubble and Selection Sort
#include <stdio.h>
#include <stdlib.h>

//make the length of they arrays a global variable
int length = 9;

void swap(int* arr, int index1, int index2, int* frequency,int* origin){
    //swap indeces
    int tmp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = tmp;

    //add count to frequency array for the number
    for(int i=0;i<length;i++){
        if((arr[index1]==origin[i])||(arr[index2]==origin[i]))
        {frequency[i]++;}
    }
}

int* bubblesort(int *arr, int* frequency, int* origin){
    int temp;

    for (int i = 0; i < length-1; i++) {
        for (int j = 0; j < length-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                swap(arr,j,j+1,frequency,origin);
            }
        }
    }

    return arr;
}

int* selectionsort(int* arr, int* frequency,int* origin) {
    int minIndex, temp,n=length;

    // Iterate through the array
    for (int i = 0; i < n - 1; i++) {
        // Find the index of the minimum element in the unsorted part of the array
        minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the minimum element with the first element of the unsorted part
        if(i!=minIndex)
        {swap(arr,i,minIndex,frequency,origin);}
    }

    return arr;
}

int main(void){
    //arrays going through bubble sort
    int barr1[] = {97,16,45,63,13,22,7,58,72,-1};
    int barr2[] = {90,80,70,60,50,40,30,20,10,-1};
    //arrays going thorough selection sort
    int sarr1[] = {97,16,45,63,13,22,7,58,72,-1};
    int sarr2[] = {90,80,70,60,50,40,30,20,10,-1};

    //pointers to arrays
    int* b1 = barr1;
    int* b2 = barr2;
    int* s1 = sarr1;
    int* s2 = sarr2;

    //frequency array to store number of swaps (in sorted order)
    int numSwapsbarr1[]={0,0,0,0,0,0,0,0,0};
    int numSwapsbarr2[]={0,0,0,0,0,0,0,0,0};
    int numSwapssarr1[]={0,0,0,0,0,0,0,0,0};
    int numSwapssarr2[]={0,0,0,0,0,0,0,0,0};

    //pointers to frequency arrays
    int* fb1 = numSwapsbarr1;
    int* fb2 = numSwapsbarr2;
    int* fs1 = numSwapssarr1;
    int* fs2 = numSwapssarr2;

    //origin for frequency arrays (arrays in sorted order)
    int arr1[] = {7,13,16,22,45,58,63,72,97,-1};
    int arr2[] = {10,20,30,40,50,60,70,80,90,-1};
    

    //call sort methods
    b1 = bubblesort(barr1,numSwapsbarr1,arr1);
    b2 = bubblesort(barr2,numSwapsbarr2,arr2);
    s1 = selectionsort(sarr1,numSwapssarr1,arr1);
    s2 = selectionsort(sarr2,numSwapssarr2,arr2);

    //calculate total number of swaps (sum/2)
    int total1 = 0;
    for(int i=0;i<length;i++){
        total1+=numSwapsbarr1[i];
    }
    total1 /= 2;

    int total2 = 0;
    for(int i=0;i<length;i++){
        total2+=numSwapsbarr2[i];
    }
    total2 /= 2;

    int total3 = 0;
    for(int i=0;i<length;i++){
        total3+=numSwapssarr1[i];
    }
    total3 /= 2;

    int total4 = 0;
    for(int i=0;i<length;i++){
        total4+=numSwapssarr2[i];
    }
    total4 /= 2;

    //print swaps
    printf("Bubble Sort Array1");
    for(int i=0; i<length; i++){
        printf("\n%d:%d",b1[i],numSwapsbarr1[i]);
    }
    printf("\nTotal swaps = %d",total1);
    
    
    printf("\n\nBubble Sort Array2");
    for(int i=0; i<length; i++){
        printf("\n%d:%d",b2[i],numSwapsbarr2[i]);
    }
    printf("\nTotal swaps = %d",total2);

    printf("\n\nSelection Sort Array1");
    for(int i=0; i<length; i++){
        printf("\n%d:%d",s1[i],numSwapssarr1[i]);
    }
    printf("\nTotal swaps = %d",total3);

    printf("\n\nSelection Sort Array2");
    for(int i=0; i<length; i++){
        printf("\n%d:%d",s2[i],numSwapssarr2[i]);
    }
    printf("\nTotal swaps = %d",total4);
}