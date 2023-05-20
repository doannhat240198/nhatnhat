/**
 * @author Lam Nguyen
 * @email nguyenthualam1@gmail.com
 * @create date 2023-04-09
 * @desc [Sort the elements in the array and count the number of occurrences]
 */

#include <stdio.h>
#include "stdlib.h"

#define SIZE 10
int temp[SIZE];


/*
* Function: insertionSort
* Description: SỬ DỤNG THUẬT TOÁN INSERTION SORT ĐỂ SẮP XẾP
* Input:
*   int arr[]
*   int size
* Output:
*   return new arr[]
*/
void  insertionSort(int arr[],int size){
    int temp,j ;
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


/*
* Function: countElement
* Description: sỐ LẦN PHẨN TỬ TRONG MẢNG XUẤT HIỆN
* Input:
*   int arr[]
*   int size
* Output:
*   return count
*/
void countElement(int arr[], int size){
    int temp[SIZE];                     //DÙNG MẢNG temp ĐỂ ĐÁNH DẤU CÁC PHẦN TỬ ĐƯỢC XÉT HAY CHƯA ĐƯỢC XÉT

    for(int i = 0; i<size ; i++){
        int count = 1;
        if(temp[i])                     //TRUE khi temp[i] != 0 
        {
            temp[i]=0;
            for(int j = i + 1; j<size; j++)
            {
                if(arr[j] == arr[i])
                {
                    count ++;
                    temp[j]=0;          //NHỮNG PHẦN TỬ NÀO TRÙNG THÌ GÁN GIÁ TRỊ ĐÓ VÔ MẢNG temp = 0
                }
            }
            printf("So %d xuat hien %d lan\n", arr[i], count);
        }
    }
    
}

/*
* Function: input
* Description: HÀM TẠO NGẪU NHIÊN SỐ TỰ NHIÊN
*/
void input(int *arr, int size){
    for(int i=0; i<SIZE;i++)
    {
        arr[i] = rand() % 10;
    }
}

/*
* Function: output
* Description: HÀM IN RA SỐ TỰ NHIÊN CÓ TRONG MẢNG
*/
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