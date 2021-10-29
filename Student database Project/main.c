/*  Student database program       */

#include <stdio.h>
#include <string.h>

typedef struct vehicle
{
    char name[100];
    int year;
    int course;
    char grade[100];

}record;

int main(void)
{
    int i , choice;
    FILE *fp1,*fp2;
    char oname[100];
    record det;
    int recsize;
    char c;

    fp1 = fopen("record.dat" , "r+");
    if(fp1 == NULL)
    {
        fp1 = fopen("record.dat" , "w+");
        if(fp1 == NULL)
        {
            printf("error in opening file : \n");
            return -1;
        }
    }
    recsize = sizeof(det);

    fseek(fp1 , 0 ,SEEK_END);
    printf("\n________________________________________________\n");
    printf("                                               \n");
    printf("Student Database System\n");
    printf("________________________________________________\n");
    printf("                                               \n");
    printf("Enter Student ID : ");
    scanf("%[^\n]" , det.name);
    printf("Enter the Year   : ");
    scanf("%d" , &det.year);
    printf("Enter Course_1 ID    : ");
    scanf("%d" , &det.course);
    scanf("%c" , &c);
    printf("Enter Course_1 Grade: ");
    scanf("%[^\n]" , det.grade);
    printf("Enter Course_2 ID    : ");
    scanf("%d" , &det.course);
    scanf("%c" , &c);
    printf("Enter Course_2 Grade: ");
    scanf("%[^\n]" , det.grade);
    printf("Enter Course_3 ID    : ");
    scanf("%d" , &det.course);
    scanf("%c" , &c);
    printf("Enter Course_3 Grade: ");
    scanf("%[^\n]" , det.grade);
    fwrite(&det,recsize,1,fp1);
}
