/*File: program_c
Author: THAI DOAN NHAT
Date:2/5/2023
Description:reverse string and
number of occurrences of each letter*/
#include <stdio.h>
#include <stdint.h>

char arr[]= "So I heard you found somebody\
 else And at first, I thought it was a lie";

typedef struct
{
    char *addr;
    uint8_t len;
}typeArr;
/*Split string*/
void extractWord(typeArr *word){
    static int16_t index = sizeof(arr)-2; 
    //initialization variable index save\
    last location of aray (not Character '\0')
    word->len=0;
    for (; index >= 0; index--)   
    //browse character of loop\
    last string come first string
    {
        word->len++;
        if ((arr[index-1]==' ')||(index==0))
        {
            word->addr=arr+index;  
             //save address first character of the word
            index-=2;
            break;
        } 
    }
    if(index==-2)
        index = sizeof(arr)-2; 
}
/*reverse string and save new string */
int sortEndtoStart(typeArr *word, char sortedArr[]){
    uint16_t index=0;
    uint8_t wordNumbers=0;
 
    while (word->addr!=arr)//browse the word from last string come first string
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
/*save the word in array 2 way */
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
/*arrange the word in 2 way ascending order value like 
  code table ASCII:array2d[][] - array two-way */
void sort2dArray(char array2d[][20],uint8_t wordNumbers){
    char temp[20];
    for (uint8_t i = 0; i < wordNumbers-1; i++)                   
    {                                                           
        //loop of i and j compare for word in array
        for (uint8_t j = i+1; j < wordNumbers; j++)
        {
            for (uint8_t n = 0; array2d[i][n] != '\0'; n++)     
            //loop of n browse for word
            {           
                if((array2d[i][n]>64)&(array2d[i][n]<91)){      
                    array2d[i][n]=array2d[i][n]+32;             
                    //convert uppercase characters to lowercase
                }                                                       
                if((array2d[j][n]>64)&(array2d[j][n]<91)){      
                array2d[j][n]=array2d[j][n]+32;                 
                }
                if (array2d[i][n]>array2d[j][n])   
                // array[i] bigger (code ASCII) is array[j] then swap location 2 word     
                {
                    uint8_t k=0;
                    do
                    {
                        *(temp+k)=array2d[i][k];            
                        //save array2d[i] in variable temp
                        k++;
                    } while (array2d[i][k-1] != '\0');
                
                    uint8_t l=0;
                    do
                    {
                        array2d[i][l]=array2d[j][l];        
                        //save array2d[j] in array2d[i] 
                        l++;
                    } while (array2d[j][l-1] != '\0');
                
                    uint8_t m=0;
                    do
                    {
                        array2d[j][m]=temp[m];
                        //save variable temp in array2d[j]
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


/*check if string like string*/
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

/*count number appear of the word in string*/
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
