#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void gotoxy(int,int );
void showstd(double);
void menu();
void add();
void deleterec();
void modify();
void view();
void avg();
void maxtsc();
void mintsc();
void searchid();
void sortotal();
void ascending();
void descending();
void shascending(double arr[],int len);
void shdescending(double arr[],int len);
struct student
{
    char bid[10];
    char name[20];
    char gender[10];
    double quizzesc;
    double midsc;
    double finalsc;
    double totalsc;
};
int main()
{
    gotoxy(15,8);
    printf("<--:Student Management System:-->");
    gotoxy(19,15);
    printf("Press any key to continue.");
    getch();
    menu();
    return 0;
}
void menu()
{
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("<--:MENU:-->");
    gotoxy(10,5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10,7);
    printf("1 : Add student records.");
    gotoxy(10,8);
    printf("2 : Delete student records.");
    gotoxy(10,9);
    printf("3 : Update student records.");
    gotoxy(10,10);
    printf("4 : View all student records.");
    gotoxy(10,11);
    printf("5 : Calculate an average of a selected student's scores.");
    gotoxy(10,12);
    printf("6 : Show student who gets the max total score.");
    gotoxy(10,13);
    printf("7 : Show student who gets the min total score.");
    gotoxy(10,14);
    printf("8 : Find student by ID.");
    gotoxy(10,15);
    printf("9 : Sort records by total scores.");
    gotoxy(10,16);
    printf("10: Exit");
    gotoxy(10,19);
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        deleterec();
        break;

    case 3:
        modify();
        break;

    case 4:
        view();
        break;

    case 5:
        avg();
        break;

    case 6:
        maxtsc();
        break;
    case 7:
        mintsc();
        break;
    case 8:
        searchid();
        break;
    case 9:
        sortotal();
        break;
    case 10:
        exit(1);
        break;

    default:
        gotoxy(10,20);
        printf("Invalid Choice.");
    }
}

void add()
{

    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL)
    {
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD RECORD:-->");
        gotoxy(10,5);
        printf("Enter details of student.");
        gotoxy(10,7);
        printf("Enter ID : ");
        gets(std.bid);
        fflush(stdin);
        gotoxy(10,8);
        printf("Enter Name : ");
        gets(std.name);
        gotoxy(10,9);
        printf("Enter Gender: ");
        gets(std.gender);
        fflush(stdin);
        gotoxy(10,10);
        printf("Enter Quiz : ");
        scanf("%lf",&std.quizzesc);
        fflush(stdin);
        gotoxy(10,11);
        printf("Enter Mid : ");
        scanf("%lf",&std.midsc);
        fflush(stdin);
        gotoxy(10,12);
        printf("Enter Final : ");
        scanf("%lf",&std.finalsc);
        fflush(stdin);
        fwrite(&std,sizeof(std),1,fp);
        gotoxy(10,16);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void deleterec()
{

    char stbid[10];
    FILE *fp,*ft;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:Delete student records:-->");
    gotoxy(10,5);
    printf("Enter ID of student to delete record : ");
    fflush(stdin);
    gets(stbid);
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stbid,std.bid)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}
void modify()
{

    int i=1;
    char stbid[10];
    FILE *fp;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:Update student records:-->");
    gotoxy(10,5);
    printf("Enter ID of student to update: ");
    fflush(stdin);
    gets(stbid);
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stbid,std.bid) == 0)
        {
            gotoxy(10,7);
            printf("No.  ID        Name                Gender    Quiz        Mid         Final       Total Score");
            gotoxy(10,8);
            printf("--------------------------------------------------------------------------------------------");
            gotoxy(10,9);
            printf("%-5d%-10s%-20s%-10s%-12f%-12f%-12f%-12f",i,std.bid,std.name,std.gender,std.quizzesc,std.midsc,std.finalsc,std.totalsc=(std.quizzesc+std.midsc+std.finalsc));
            gotoxy(10,14);
            printf("Enter ID : ");
            gets(std.bid);
            fflush(stdin);
            gotoxy(10,15);
            printf("Enter Name : ");
            gets(std.name);
            gotoxy(10,16);
            printf("Enter Gender: ");
            gets(std.gender);
            fflush(stdin);
            gotoxy(10,17);
            printf("Enter Quiz : ");
            scanf("%lf",&std.quizzesc);
            fflush(stdin);
            gotoxy(10,18);
            printf("Enter Mid : ");
            scanf("%lf",&std.midsc);
            fflush(stdin);
            gotoxy(10,19);
            printf("Enter Final : ");
            scanf("%lf",&std.finalsc);
            fflush(stdin);
            fseek(fp,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,23);
    printf("Press any key to continue.");
    getch();
    menu();
}
void view()
{

    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:View all student records:-->");
    gotoxy(10,5);
    printf("No.  ID        Name                Gender    Quiz        Mid         Final       Total Score");
    gotoxy(10,6);
    printf("--------------------------------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        gotoxy(10,j);
        printf("%-5d%-10s%-20s%-10s%-12f%-12f%-12f%-12f",i,std.bid,std.name,std.gender,std.quizzesc,std.midsc,std.finalsc,std.totalsc=(std.quizzesc+std.midsc+std.finalsc));
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}
void avg()
{
    double avg=0;
    FILE *fp;
    struct student std;
    char stbid[10];
    system("cls");
    gotoxy(10,3);
    printf("<--:Calculate an average of a selected student's scores:-->");
    gotoxy(10,5);
    printf("Enter ID of student : ");
    fflush(stdin);
    gets(stbid);
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1)
    {
        if(strcmp(stbid,std.bid) == 0)
        {
            gotoxy(10,8);
            printf("ID : %s",std.bid);
            gotoxy(10,9);
            printf("Name : %s",std.name);
            gotoxy(10,10);
            printf("Gender : %s",std.gender);
            gotoxy(10,11);
            printf("Quiz Score : %f",std.quizzesc);
            gotoxy(10,12);
            printf("Mid Score : %f",std.midsc);
            gotoxy(10,13);
            printf("Final Score : %f",std.finalsc);
            gotoxy(10,14);
            printf("Total Score : %f",std.totalsc=(std.quizzesc+std.midsc+std.finalsc));
            gotoxy(10,16);
            printf("Average Score : %f",avg=(std.totalsc/3));

        }
    }
    fclose(fp);
    gotoxy(10,20);
    printf("Press any key to continue.");
    getch();
    menu();
}

void maxtsc()
{
    FILE *fp;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:Show student who gets the max total score:-->");
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,5);
        printf("Error opening file.");
        exit(1);
    }
    int i=0,sz=sizeof(std);
    double max=0,ttsc=0;
    while(fread(&std,sz,1,fp) == 1)
    {
        std.totalsc=(std.quizzesc+std.midsc+std.finalsc);
        ttsc=std.totalsc;
        if(ttsc>max)
        {
            max=ttsc;
        }
    }
    printf("\n\nThe maximum total score is : %lf\n\n\nPress any key to see The students who got the maximum number.........",max);
    fclose(fp);
    getch();
    showstd(max);
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}
void mintsc()
{

    FILE *fp;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:Show student who gets the min total score:-->");
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,5);
        printf("Error opening file.");
        exit(1);
    }
    int i=0,sz=sizeof(std);
    double min=0,ttsc=0;
    while(fread(&std,sz,1,fp) == 1)
    {
        std.totalsc=(std.quizzesc+std.midsc+std.finalsc);
        ttsc=std.totalsc;
        if(min==0)
        {
            min=ttsc;
        }
        else if(ttsc<min)
        {
            min=ttsc;
        }
    }
    printf("\n\nThe minimum total score is : %lf\n\n\nPress any key to see The students who got the minimum number.....",min);
    fclose(fp);
    getch();
    showstd(min);
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}
void searchid()
{

    FILE *fp;
    struct student std;
    char stbid[10];
    system("cls");
    gotoxy(10,3);
    printf("<--:Find student by ID:-->");
    gotoxy(10,5);
    printf("Enter ID of student : ");
    fflush(stdin);
    gets(stbid);
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1)
    {
        if(strcmp(stbid,std.bid) == 0)
        {
            gotoxy(10,8);
            printf("ID : %s",std.bid);
            gotoxy(10,9);
            printf("Name : %s",std.name);
            gotoxy(10,10);
            printf("Gender : %s",std.gender);
            gotoxy(10,11);
            printf("Quiz Score : %f",std.quizzesc);
            gotoxy(10,12);
            printf("Mid Score : %f",std.midsc);
            gotoxy(10,13);
            printf("Final Score : %f",std.finalsc);
            gotoxy(10,14);
            printf("Total Score : %f",std.totalsc=(std.quizzesc+std.midsc+std.finalsc));

        }
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void showstd(double sad)
{



    FILE *fp;
    struct student std;
    system("cls");
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1)
    {
        std.totalsc=(std.quizzesc+std.midsc+std.finalsc);
        if(sad == std.totalsc)
        {
            gotoxy(10,8);
            printf("ID : %s",std.bid);
            gotoxy(10,9);
            printf("Name : %s",std.name);
            gotoxy(10,10);
            printf("Gender : %s",std.gender);
            gotoxy(10,11);
            printf("Quiz Score : %f",std.quizzesc);
            gotoxy(10,12);
            printf("Mid Score : %f",std.midsc);
            gotoxy(10,13);
            printf("Final Score : %f",std.finalsc);
            gotoxy(10,14);
            printf("Total Score : %f",std.totalsc=(std.quizzesc+std.midsc+std.finalsc));

        }
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();


}

void sortotal()
{
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("<--:Sort records by total scores:-->");
    gotoxy(10,5);
    printf("1 : Ascending Order");
    gotoxy(10,7);
    printf("2 : Descending Order ");
    gotoxy(10,12);
    printf("Enter your choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        ascending();
        break;

    case 2:
        descending();
        break;
    }

}
void ascending()
{

    FILE *fp;
    struct student std;
    system("cls");
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,3);
        printf("Error opening file.");
        exit(1);
    }
    int i=0,len=0,sz=sizeof(std);
    double arr[1000];
    while(fread(&std,sz,1,fp) == 1)
    {
        std.totalsc=(std.quizzesc+std.midsc+std.finalsc);
        arr[i]=std.totalsc;
        i++;

    }
    len=i;
    shascending(arr,len);
    fclose(fp);
    getch();
    menu();
}
void descending()
{


    FILE *fp;
    struct student std;
    system("cls");
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,3);
        printf("Error opening file.");
        exit(1);
    }
    int i=0,len=0,sz=sizeof(std);
    double arr[1000];
    while(fread(&std,sz,1,fp) == 1)
    {
        std.totalsc=(std.quizzesc+std.midsc+std.finalsc);
        arr[i]=std.totalsc;
        i++;
    }
    len=i;
    shdescending(arr,len);

    fclose(fp);
    getch();
    menu();
}
void shascending(double arr[],int len)
{
    int i=0,j=0;
    double temp=0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    FILE *fp;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:View all student records Ascending Order:-->");
    gotoxy(10,5);
    printf("No.  ID        Name                Gender    Quiz        Mid         Final       Total Score");
    gotoxy(10,6);
    printf("--------------------------------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,8);
        printf("Error opening file");
        exit(1);
    }
    int p=1,q=8;
    while(fread(&std,sizeof(std),1,fp ) == 1)
    {
        std.totalsc=(std.quizzesc+std.midsc+std.finalsc);
        i=0;
        for(i=0;i<len;i++){
        if(arr[i] == std.totalsc)
        {
        gotoxy(10,q+i);
        printf("%-5d%-10s%-20s%-10s%-12f%-12f%-12f%-12f",i+1,std.bid,std.name,std.gender,std.quizzesc,std.midsc,std.finalsc,std.totalsc=(std.quizzesc+std.midsc+std.finalsc));
        p++;
        }
        }

    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();


}

void shdescending(double arr[],int len)
{
    int i=0,j=0;
    double temp=0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    FILE *fp;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:View all student records Descending Order:-->");
    gotoxy(10,5);
    printf("No.  ID        Name                Gender    Quiz        Mid         Final       Total Score");
    gotoxy(10,6);
    printf("--------------------------------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL)
    {
        gotoxy(10,8);
        printf("Error opening file");
        exit(1);
    }
    int p=1,q=8;
    while(fread(&std,sizeof(std),1,fp ) == 1)
    {
        std.totalsc=(std.quizzesc+std.midsc+std.finalsc);
        i=0;
        for(i=0;i<len;i++){
        if(arr[i] == std.totalsc)
        {
        gotoxy(10,q+i);
        printf("%-5d%-10s%-20s%-10s%-12f%-12f%-12f%-12f",i+1,std.bid,std.name,std.gender,std.quizzesc,std.midsc,std.finalsc,std.totalsc=(std.quizzesc+std.midsc+std.finalsc));
        p++;
        }
        }

    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();

}

void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
