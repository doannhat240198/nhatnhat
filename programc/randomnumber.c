/*File: program_c
Author: THAI DOAN NHAT
Date:5/5/2023
Description:print out random numbers and sort*/

#include <stdio.h>
#include "stdlib.h"

#define SIZE 10
int temp[SIZE];


/*use algorithm insertion sort arrange*/
void  insertionSort(int arr[],int size){
    int temp,j ;//declare variable
    for(int i = 1; i<SIZE; i++)
    {
        j = i;
        while(j>0 && arr[j]<=arr[j-1])
        {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}


/*number of times array appeared*/
void countElement(int arr[], int size){
    int temp[SIZE];                     
    // array temp to tick elements considered or not considered
    for(int i = 0; i<size ; i++){
        int count = 1;
        if(temp[i])                     
        //TRUE then temp[i] != 0 
        {
            temp[i]=0;
            for(int j = i + 1; j<size; j++)
            {
                if(arr[j] == arr[i])
                {
                    count ++;
                    temp[j]=0;          
                    //coincidence element then assign value in array temp = 0
                }
            }
            printf("So %d xuat hien %d lan\n", arr[i], count);
        }
    }
    
}

/*Description: function create ramdom number*/
void input(int *arr, int size){
    for(int i=0; i<SIZE;i++)
    {
        arr[i] = rand() % 10;
    }
}

/*Description: function print number have in array*/
void output(int *arr, int size){
    for(int i =0; i<SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    int arr[SIZE];
    

    input(arr, SIZE);
    output(arr, SIZE);

    insertionSort(arr, SIZE);
    output(arr, SIZE);

    countElement(arr, SIZE);

    return 0;
}