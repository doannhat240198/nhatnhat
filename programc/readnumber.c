/*
File: program_c
Author: THAI DOAN NHAT
Date:4/5/2023
Description: input number and print read digits 
*/
#include<stdio.h>
#include<stdint.h>
uint32_t number; //save number
uint8_t has_zero = 0; //variable SET up 1 when have 0
/*function read number*/
void printNum(uint8_t num, uint8_t loca){  
    switch (num)
    {
    case 0: 
        if(loca % 3 == 1){ 
            printf("LINH "); //if dozens then read 'LINH'
        }
        else printf("KHONG ");
        break;
    case 1:
        if(loca % 3 != 1) printf("MOT "); //if not dozens then print 
        break;
    case 2:
        printf("HAI ");
        break;
    case 3:
        printf("BA ");
        break;
    case 4:
        printf("BON ");
        break;
    case 5:
        if((loca % 3 == 0) && has_zero == 0) printf("LAM ");
        // check location is unit and front position not 0
        else printf("NAM ");
        break;
    case 6: 
        printf("SAU ");
        break;
    case 7: 
        printf("BAY ");
        break;
    case 8: 
        printf("TAM ");
        break;
    case 9: //SỐ 9
        printf("CHIN ");
        break;
    
    default:
        break;
    }
}
void printUnit(uint8_t num, uint8_t loca){
    switch (loca % 3)  // consider each location
    {
    case 2: // location hundreds
        printf("TRAM ");
        break;

    case 1: // location dozens
        if(num != 0) printf("MUOI "); // if dozens equal 0 not print 
        break;

    case 0: //if it is unit
        if(loca / 3 == 1) printf("NGAN "); //if it is unit thousand
        else if(loca / 3 == 2) printf("TRIEU "); //if it is unit milion
        break;
    default:
        break;
    }
}

void readNumber(uint32_t num){
    uint8_t size = 1; //number of digits write in
    uint8_t *ptr = (uint8_t *)malloc(size*sizeof(uint8_t)); //dynamic allocation array save each digit
    uint8_t check_num_first = 0; //check location frist number in the row
    /*number separation*/
    while(1){
        *(ptr + size - 1) = num % 10; //number separation and  in position in array
        num /= 10; //reduce number by 10 and separate
        if(num == 0) break; // if devired then BREAK
        ++size; //increase the number of stats after every split
        realloc(ptr, size*sizeof(uint8_t)); // increase the number of Arrays and save number
    }
    /*READ NUMBER*/
    for(int i=size-1; i>=0; i--) //browse from end to first Arrays and save number  above
    {
        if(check_num_first > 0){ // if had first number
            if(*(ptr+i) == 0) //ì number is 0
            {
                has_zero = 1; //number 0 then set variable up 1
                uint8_t vitri_sodautien = check_num_first / 3 * 3; //check a first number in row?
                if(i == vitri_sodautien) printUnit(*(ptr+i), i); 
                /*if done approval a row and row contain first number then read unit row*/
                continue;
            }
            else //if number other 0
            {
                if(has_zero == 1) //if front number browsing is number 0 then read value and unit of befor number
                 
                {
                    printNum(*(ptr+i+1), i+1);
                    printUnit(*(ptr+i+1), i+1);  
                }
                //read value and unit of number
                printNum(*(ptr+i), i);
                printUnit(*(ptr+i), i);
                has_zero = 0;
                continue;
            }
            
        }
        if(*(ptr+i) != 0 && check_num_first == 0) /* if first number then read value and unit,
        save first location in variable location if first number other 0 then still read uint of row original number */
        {
            printNum(*(ptr+i), i); //dozen and dozen thousand
            printUnit(*(ptr+i), i);
            check_num_first = i;
        }
    }

    if(check_num_first == 0) printf("KHONG"); 
    //if brows array but variable check_num_first = 0 then number transmission is 0
    free(ptr); //delete array dynamic memory allocation
}

int main(int argc, char const *argv[])
{
    printf("Nhap mot so: ");
    scanf("%lu", &number);

    printf("So duoc nhap: %lu\n", number);

    readNumber(number);
    return 0;
}
