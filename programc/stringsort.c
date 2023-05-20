/*
* File: Bai2.c
* Author: Quang Linh
* Date: 29/04/2023
* Description: In chuỗi cho trước theo chiều ngược lại và tính số lần xuất hiện của các từ trong chuỗi.
*/
#include <stdio.h>
#include <stdint.h>

char arr[]= "I think when I work as an English teacher, I enjoy seeing my students learning progress.";

typedef struct
{
    char *addr;
    uint8_t len;
}typeArr;


/*
* Function: extractWord
* Description: Tách từng từ trong chuỗi, lưu địa chỉ ký tự đầu và kích thước của từ
* Input:
*   word - biến dạng con trỏ để lưu địa chỉ và kích thước từ
*/
void extractWord(typeArr *word){
    static int16_t index = sizeof(arr)-2;  //Khởi tạo biến index lưu vị trí kí tự cuối cùng của chuỗi (không tính ký tự '\0' )
    word->len=0;
    for (; index >= 0; index--)   //Chạy vòng lặp duyệt từ kí tự cuối chuỗi đến kí tự đầu chuỗi
    {
        word->len++;
        if ((arr[index-1]==' ')||(index==0))
        {
            word->addr=arr+index;   //Lưu địa chỉ ký tự đầu tiên của từ
            index-=2;
            break;
        } 
    }
    if(index==-2)
        index = sizeof(arr)-2; 
}


/*
* Function: sortEndtoStart
* Description: Sắp xếp chuỗi theo hướng ngược lại và lưu vào mảng chuỗi mới
* Input:
*   word - biến dạng con trỏ để lưu địa chỉ và kích thước từ
*   sortedArr[] - mảng lưu chuỗi ngược
*Output:
*   wordNumbers: trả về số lượng từ có trong chuỗi
*/
int sortEndtoStart(typeArr *word, char sortedArr[]){
    uint16_t index=0;
    uint8_t wordNumbers=0;
 
    while (word->addr!=arr)     //duyệt từng word từ cuối chuỗi lên đầu chuỗi
    {   
        extractWord(word);
        for (uint8_t i=0; i < word->len; i++)
        {
            sortedArr[index++]=*(word->addr+i);
        }
        sortedArr[index++]=' '; 
        wordNumbers++; 
    }
    sortedArr[index]='\0';
    //printf("ky tu dau cua chuoi nguoc: %c\n", sortedArr[0]);
    return wordNumbers;
}



/*
* Function: create2dArray
* Description: lưu từng từ vào mảng 2 chiều
* Input:
*   word - biến dạng con trỏ để lưu địa chỉ và kích thước từ
*   array2d[][] - mảng 2 chiều
*/
void create2dArray(typeArr *word,char array2d[][20]){
    
    for (uint8_t index=0; word->addr!=arr; index++)     //duyệt từng word từ cuối chuỗi lên đầu chuỗi
    {    
        extractWord(word);
        for (uint8_t i = 0; i < word->len; i++)
        {   
            array2d[index][i]=*(word->addr+i);
        }
        if (((array2d[index][word->len-1]>64) & (array2d[index][word->len-1] < 91))
        ||((array2d[index][word->len-1]>96) & (array2d[index][word->len-1] < 123)))     //lệnh if để đảm bảo các từ được lưu chỉ có chữ cái, không có dấu câu
            array2d[index][word->len]='\0';
        else
            array2d[index][word->len-1]='\0';
    }
}


/*
* Function: sort2dArray
* Description: sắp xếp các từ trong mảng 2 chiều theo thứ tự tăng dần giá trị theo bảng mã ASCII
* Input:
*   wordNumbers - số lượng từ trong chuỗi
*   array2d[][] - mảng 2 chiều
*/
void sort2dArray(char array2d[][20],uint8_t wordNumbers){
    char temp[20];
    for (uint8_t i = 0; i < wordNumbers-1; i++)                   
    {                                                           //vòng for của i và j dùng để so từng từ trong chuỗi
        for (uint8_t j = i+1; j < wordNumbers; j++)
        {
            for (uint8_t n = 0; array2d[i][n] != '\0'; n++)     //vòng for của n để duyệt qua từng kí tự của từ
            {           
                if((array2d[i][n]>64)&(array2d[i][n]<91)){      
                    array2d[i][n]=array2d[i][n]+32;             //chuyển những kí tự in hoa thành in thường
                }                                                       
                if((array2d[j][n]>64)&(array2d[j][n]<91)){      
                array2d[j][n]=array2d[j][n]+32;                 
                }
                if (array2d[i][n]>array2d[j][n])   //nếu từ ở array[i] lớn lơn (theo mã ASCII) từ ở array[j] thì swap vị trí 2 từ     
                {
                    uint8_t k=0;
                    do
                    {
                        *(temp+k)=array2d[i][k];            //lưu từ ở array2d[i] vào biến temp
                        k++;
                    } while (array2d[i][k-1] != '\0');
                
                    uint8_t l=0;
                    do
                    {
                        array2d[i][l]=array2d[j][l];        //lưu từ ở array2d[j] vào array2d[i] 
                        l++;
                    } while (array2d[j][l-1] != '\0');
                
                    uint8_t m=0;
                    do
                    {
                        array2d[j][m]=temp[m];              //lưu từ ở biến temp vào array2d[j]
                        m++;
                    } while (temp[m-1] != '\0');

                    break;
                }
                else if (array2d[i][n]<array2d[j][n])
                    break;                          
            }
        }            
    }   
}


/*
* Function: isEqual
* Description: kiểm tra sự giống nhau của 2 chuỗi
* Input:
*   char1[] - chuỗi 1
*   char2[] - chuỗi 2
*Output:
*   Return 0: không giống nhau
*   Return 1: giống nhau
*/
int isEqual(const char char1[],const char char2[])
{
    uint8_t i=0;
    do
    {
        if (char1[i]!=char2[i])
            return 0;
        i++;
    } while (char1[i-1] != '\0');
    return 1;
}

/*
* Function: countWord
* Description: đếm số lượng xuất hiện của các từ có trong chuỗi
* Input:
*   array2d[][] - mảng 2 chiều
*   wordNumbers- số lượng từ trong chuỗi
*/
void countWord(char array2d[][20], uint8_t wordNumbers){
    for (uint8_t i = 0; i < wordNumbers; i++)
    {
        uint8_t count=1;
        for (int j = i+1; j < wordNumbers+1; j++)
        {
            if (isEqual(array2d[i],array2d[j])==1)   
                count++;
            else
            {
                printf(" '%s' xuat hien %d lan\n",array2d[i],count);
                i=j-1;
                break;
            }
        }
    }
}



int main(int argc, char const *argv[])
{
    typeArr word;
    char sortedArray[sizeof(arr)];
    uint8_t wordNumbers;

    wordNumbers=sortEndtoStart(&word, sortedArray);

    char array2d[wordNumbers][20];

    printf("%s\n\n",sortedArray);

    create2dArray(&word, array2d);
    sort2dArray(array2d, wordNumbers);
    countWord(array2d, wordNumbers);
    
    return 0;
}
