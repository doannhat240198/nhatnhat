/*File: program_c
Author: THAI DOAN NHAT
Date:24/4/2023
Description:print that year is leapyear or not leapyear  */
#include <stdio.h>

int tinhThu(int ngay, int thang, int nam) 
{
    if (thang < 3) //nếu tháng 1 và 2 thì
    {
        thang += 12;// tháng sẽ là tháng 13 và 14
        nam -= 1;// của năm trước
    }
    int k = nam % 100;// năm của thế kỉ, chia lấy dư
    int j = nam / 100;//thế kỉ
    int thu = ngay + 13 * (thang + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    //công thức của thuật toán zeller
    thu = thu % 7;
    return thu;
}

int main() 
{
    int ngay, thang, nam;
    char *thu[] = {"Thu Bay", "Chu Nhat", "Thu Hai", "Thu Ba", "Thu Tu", "Thu Nam", "Thu Sau"};

    printf("Nhap ngay: ");
    scanf("%d", &ngay);
    printf("Nhap thang: ");
    scanf("%d", &thang);
    printf("Nhap nam: ");
    scanf("%d", &nam);

    int thuIndex = tinhThu(ngay, thang, nam);

    printf("Ngay %d thang %d nam %d la %s\n", ngay, thang, nam, thu[thuIndex]);

    return 0;
}