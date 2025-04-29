#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <time.h>
void SetColor(int ForgC)
{
    WORD wColor;
    // We will need this handle to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // We use csbi for the wAttributes word.
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        // Mask out all but the background attribute, and add in the forgournd color
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
    {
    }
}
COORD coord = {0, 0};

void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void wait(){
    gotoxy(15,32);
    printf("Please Wait");
    for(int i=27;i<37;i++){
    gotoxy(i,32);
    printf("*");
    delay(100);
    }
}
typedef struct supplier
{
    int supp_id;
    char supp_name[25];
    char city[20];
    char mob_no[11];
    char email[30];

} supplier;
typedef struct customer
{
    int cust_id;
    char cust_name[30];
    char city[20];
    char mob_no[11];
    char email[50];

} customer;
typedef struct medical
{
    int id;
    char medi_name[20];
    int rack;
    int quantity;
    float sell;
    float total;
    float unit;
    float cost;
    float profit;
    float bye;
    int qty;
    char pur_date[15];
    char exp_date[15];
    char manu_date[15];
    int bill_no;
    char comp_name[20];
    char supp_name[30];
} medical;
typedef struct bill
{
    int billno;
    char cname[30];
    char mediname[30];
    int medi_qty;
    float medi_rate;
    float total;
    int day;
    int month;
    int year;

} bill;
typedef struct salesreport
{
    int medi_id;
    char medir_name[20];
    char cust_name[30];
    int sDay, sMonth, sYear;
    int qty;
    float rate;
    float total;
} salesrpt;
typedef struct purchasereport
{
    int medi_id;
    char medi_name[20];
    char supp_name[30];
    int sDay, sMonth, sYear;
    int qty;
    float rate;
    float total;
} purchaserpt;
typedef struct profit_report
{
    char medi_id[6];
    char medir_name[20];
    int sDay, sMonth, sYear;
    int qty;
    float rate;
    float unit;
    float profit;
} profitrpt;
void login();
void menu();
void box();
void box1();
void box2();
void box3();
void box4();
//                                  Suppliers Functions                                            //
void supply();
void supentry();
void suppdisplay();
void noofsup();
void supsearch();
void supupdate();
void supdelete();
void supsortname();
void supsortnameinfile();
void supsortid();
int getsupp_id();
//                                  End Of Supplier Funtions                                          //

//                                  Customer Function                                                 //
void cust();
void custentry();
void custdisplay();
void noofcust();
void custsearch();
void custupdate();
void custdelete();
void custsortname();
void custsortnameinfile();
void custsortid();
int getcust_id();
//                                   End of Customer Functions                                          //

//                                   Medicine Functions                                                 //
void medi();
void medipur();
void medistock();
void medistockupdate();
void medisearch();
void medisell();
//                                   End of Medicine Functions                                          //
//                                   Report Function                                                    //
void report();
void purreport();
void salereport();
//                                   End of Report Fucntion                                             //
//                                   Function for bill                                                  //
void billing();
//                                   End of Bill Fuction                                                //
int main()
{
    system("cls");
    menu();
}
void menu()
{
    system("cls");
    login();
    box();
}
void login()
{
    int t = 0;
    do
    {

        int i = 0;
        char us[20], ps[20];
        char user[20] = "medical", pass[20] = "12345";
        system("cls");
        gotoxy(23, 0);
        SetColor(3);
        printf("IIIT PHARMACY");
        gotoxy(15, 2);
        SetColor(6);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB LOGIN \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
        gotoxy(18, 4);
        SetColor(5);
        printf("Username: ");
        gotoxy(18, 6);
        printf("Password: ");
        gotoxy(15, 8);
        SetColor(6);
        printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
        for (int j = 3; j <= 7; j++)
        {
            gotoxy(15, j);
            printf("\xDB");
            gotoxy(45, j);
            printf("\xDB");
        }
        SetColor(7);
        gotoxy(27, 4);
        scanf("%s", us);
        gotoxy(27, 6);

        while (i < 20)
        {
            ps[i] = getch();
            if (ps[i] == 13)
            {
                break;
            }
            else
            {
                printf("*");
                i++;
            }
        }
        ps[i] = '\0';
        if (strcmp(ps, pass) == 0 && strcmp(us, user) == 0)
        {
            SetColor(2);
            printf("  \n\n\n       WELCOME TO IIIT PHARMACY !!!! YOUR LOGIN IS SUCCESSFULL");
            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getch();
            break;
        }
        else
        {
            SetColor(4);
            printf("\n\n\n        SORRY !!!!  LOGIN IS UNSUCESSFUL\n        RETRY AGAIN");
            t++;

            getch();
            system("cls");
        }
    } while (t <= 2);
    {
        if (t > 2)
        {
            printf("\nSorry you have entered the wrong username and password for three times!!!");
            getch();
            exit(0);
        }
        system("cls");
    }
}
void noofsup()
{
    supplier s1;
    int i;
    box1();
    gotoxy(18, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(29, 2);
    printf("    RECORDS");
    FILE *p;
    p = fopen("sup.txt", "r");
    fseek(p, 0, SEEK_END);
    int n = ftell(p) / sizeof(supplier);
    gotoxy(3, 7);
    printf("No. Of Records = %d", n);
    fclose(p);
    gotoxy(3, 10);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Supplier Menu Press S");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 's':
        {
            supply();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 's' || 'S');
    getch();
}
void supsearch()
{
    supplier s;
    box2();
    int i;
    gotoxy(28, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(39, 2);
    printf("     SEARCH");
    FILE *fp;
    int no, found = 0;
    fp = fopen("sup.txt", "r");
    gotoxy(3, 5);
    SetColor(6);
    printf("Enter ID No. to search: ");
    SetColor(7);
    scanf("%d", &no);
    while (fread(&s, sizeof(supplier), 1, fp))
    {
        if (s.supp_id == no)
        {
            found = 1;
            gotoxy(3, 7);
            SetColor(6);
            printf("Id No  Name                      City                 Mobile No.       Email\n");
            gotoxy(3, 9);
            SetColor(7);
            printf("%-4d   %-25s %-20s %-11s %-30s", s.supp_id, s.supp_name, s.city, s.mob_no, s.email);
        }
    }
    if (!found)
    {
        gotoxy(3, 7);
        SetColor(4);
        printf("Record not found\n");
    }
    gotoxy(3, 14);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Supplier Menu Press S");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 's':
        {
            supply();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 's' || 'S');
    getch();
    fclose(fp);
}
void supdelete()
{
    box2();
    int i;
    gotoxy(28, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(39, 2);
    printf("     DELETE");
    supplier s;
    FILE *fp, *fp1;
    int id, found = 0;
    fp = fopen("sup.txt", "r");
    fp1 = fopen("temp.txt", "w");
    gotoxy(3, 5);
    SetColor(6);
    printf("Enter Id No. to delete: ");
    SetColor(7);
    scanf("%d", &id);
    while (fread(&s, sizeof(supplier), 1, fp))
    {
        if ((s.supp_id) == (id))
        {
            found = 1;
        }
        else
        {
            fwrite(&s, sizeof(supplier), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    if (found)
    {
        fp = fopen("sup.txt", "w");
        fp1 = fopen("temp.txt", "r");

        while (fread(&s, sizeof(supplier), 1, fp1))
        {
            fwrite(&s, sizeof(supplier), 1, fp);
        }
        gotoxy(3, 7);
        SetColor(2);
        printf("Supplier deleted successfully");
        fclose(fp);
        fclose(fp1);
    }
    else
    {
        SetColor(4);
        gotoxy(3, 5);
        printf("Record not found\n");
    }
    gotoxy(3, 15);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Supplier Menu Press S");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 's':
        {
            supply();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 's' || 'S');
    getch();
}
void supsortname()
{
    supplier *s, s1;
    box2();
    gotoxy(28, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(39, 2);
    printf("      SORT");
    FILE *fp;
    fp = fopen("sup.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(supplier);
    int i, j;
    rewind(fp);
    s = (supplier *)calloc(n, sizeof(supplier));
    for (i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(supplier), 1, fp);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(s[i].supp_name, s[j].supp_name) > 0)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }
    gotoxy(3, 5);
    SetColor(6);
    printf("Id No  Name                      City                 Mobile No.       Email\n");
    int k = 7;
    for (i = 0; i < n; i++)
    {
        gotoxy(3, k);
        SetColor(7);
        printf("%-4d   %-25s %-20s %-11s %-30s\n", s[i].supp_id, s[i].supp_name, s[i].city, s[i].mob_no, s[i].email);
        k++;
    }
    fclose(fp);
    k += 2;
    gotoxy(3, k);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Supplier Menu Press S");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 's':
        {
            supply();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 's' || 'S');
    getch();
}
int getsupp_id()
{
    supplier s;
    FILE *fp;
    fp = fopen("sup.txt", "r");
    if (fp == NULL)
    {
        gotoxy(3, 5);
        printf("Data not Found.....");
        // getch();
    }
    else
    {
        s.supp_id = 100;
        rewind(fp);
        while (fread(&s, sizeof(supplier), 1, fp))
        {
        }
    }
    fclose(fp);
    printf("%d", s.supp_id + 1);
    return s.supp_id + 1;
}
void supsortnameinfile()
{
    supplier *s, s1;
    box2();
    gotoxy(28, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(39, 2);
    printf("      SORT");
    FILE *fp;
    fp = fopen("sup.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(supplier);
    int i, j;
    rewind(fp);
    s = (supplier *)calloc(n, sizeof(supplier));
    for (i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(supplier), 1, fp);
    }
    fclose(fp);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(s[i].supp_name, s[j].supp_name) > 0)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }
    gotoxy(3, 5);
    SetColor(6);
    printf("Id No  Name                      City                 Mobile No.       Email\n");
    int k = 7;
    for (i = 0; i < n; i++)
    {
        gotoxy(3, k);
        SetColor(7);
        printf("%-4d   %-25s %-20s %-11s %-30s\n", s[i].supp_id, s[i].supp_name, s[i].city, s[i].mob_no, s[i].email);
        k=k+2;
    }
    fp = fopen("sup.txt", "w");

    for (i = 0; i < n; i++)
    {
        fwrite(&s[i], sizeof(supplier), 1, fp);
    }
    fclose(fp);
    k += 2;
    gotoxy(3, k);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Supplier Menu Press S");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 's':
        {
            supply();
            break;
        }
        default:
            SetColor(4);
            gotoxy(3, i + 1);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 's' || 'S');
    getch();
}
void supsortid()
{
    supplier *s, s1;
    box2();
    gotoxy(28, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(39, 2);
    printf("    ID SORT");
    FILE *fp;
    fp = fopen("sup.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(supplier);
    int i, j;
    rewind(fp);
    s = (supplier *)calloc(n, sizeof(supplier));
    for (i = 0; i < n; i++)
    {
        fread(&s[i], sizeof(supplier), 1, fp);
    }
    fclose(fp);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (s[i].supp_id > s[j].supp_id)
            {
                s1 = s[i];
                s[i] = s[j];
                s[j] = s1;
            }
        }
    }
    gotoxy(3, 5);
    SetColor(6);
    printf("Id No  Name                      City                 Mobile No.       Email\n");
    int k = 7;
    for (i = 0; i < n; i++)
    {
        gotoxy(3, k);
        SetColor(7);
        printf("%-4d   %-25s %-20s %-11s %-30s\n", s[i].supp_id, s[i].supp_name, s[i].city, s[i].mob_no, s[i].email);
        k=k+2;
    }
    fp = fopen("sup.txt", "w");

    for (i = 0; i < n; i++)
    {
        fwrite(&s[i], sizeof(supplier), 1, fp);
    }
    k += 2;
    fclose(fp);
    gotoxy(3, k);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Supplier Menu Press S");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 's':
        {
            supply();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 's' || 'S');
    getch();
}
void supupdate()
{
    supplier s;
    FILE *fp, *fp1;
    int id, found = 0;
    fp = fopen("sup.txt", "r");
    fp1 = fopen("temp.txt", "w");
    box1();
    gotoxy(3, 5);
    SetColor(6);
    printf("Enter ID No. to update: ");
    SetColor(7);
    scanf("%d", &id);
    while (fread(&s, sizeof(supplier), 1, fp))
    {
        if ((s.supp_id) == (id))
        {
            found = 1;
            fflush(stdin);
            box1();
            gotoxy(18, 2);
            SetColor(6);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
            SetColor(7);
            gotoxy(29, 2);
            printf("     UPDATE");
            gotoxy(3, 7);
            SetColor(6);
            printf("Enter New ID No: ");
            SetColor(7);
            scanf("%d", &s.supp_id);
            fflush(stdin);
            gotoxy(3, 9);
            SetColor(6);
            printf("Enter the New Name: ");
            SetColor(7);
            scanf("%[^\n]s", s.supp_name);
            fflush(stdin);
            gotoxy(3, 11);
            SetColor(6);
            printf("Enter the New City:  ");
            SetColor(7);
            scanf("%[^\n]s", s.city);
            fflush(stdin);
            gotoxy(3, 13);
            SetColor(6);
            printf("Enter The New Mob:  ");
            SetColor(7);
            scanf("%[^\n]s", s.mob_no);
            fflush(stdin);
            gotoxy(3, 15);
            SetColor(6);
            printf("Enter the New Email:  ");
            SetColor(7);
            scanf("%[^\n]s", s.email);
            fflush(stdin);
        }
        fwrite(&s, sizeof(supplier), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if (found)
    {
        fp = fopen("sup.txt", "w");
        fp1 = fopen("temp.txt", "r");

        while (fread(&s, sizeof(supplier), 1, fp1))
        {
            fwrite(&s, sizeof(supplier), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
    {
        system("cls");
        box2();
        gotoxy(5, 5);
        SetColor(4);
        printf("Record not found!!!!!!\n");
    }
    int i;
    gotoxy(3, 18);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Supplier Menu Press S");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 's':
        {
            supply();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 's' || 'S');
    getch();
}
void supentry()
{
    FILE *p;
    p = fopen("sup.txt", "a");
    if (p == 0)
    {
        printf("Couldn't Open");
    }
    else
    {
        box1();
        supplier *s;
        int n, i, j;
        gotoxy(3, 5);
        SetColor(6);
        printf("How many suppliers you want: ");
        scanf("%d", &n);
        s = (supplier *)calloc(n, sizeof(supplier));
        for (i = 0; i < n; i++)
        {
            box1();
            gotoxy(18, 2);
            SetColor(6);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
            SetColor(7);
            gotoxy(29, 2);
            printf("    ENTRY");
            gotoxy(3, 7);
            SetColor(6);
            printf("Enter ID No: ");
            SetColor(7);
            scanf("%d", &s[i].supp_id);
            fflush(stdin);
            gotoxy(3, 9);
            SetColor(6);
            printf("Enter  Name: ");
            SetColor(7);
            scanf("%[^\n]s", s[i].supp_name);
            fflush(stdin);
            gotoxy(3, 11);
            SetColor(6);
            printf("Enter City:  ");
            SetColor(7);
            scanf("%[^\n]s", s[i].city);
            fflush(stdin);
            gotoxy(3, 13);
            SetColor(6);
            printf("Enter Mob:  ");
            SetColor(7);
            scanf("%[^\n]s", s[i].mob_no);
            fflush(stdin);
            gotoxy(3, 15);
            SetColor(6);
            printf("Enter Email:  ");
            SetColor(7);
            scanf("%[^\n]s", s[i].email);
            fflush(stdin);
            fwrite(&s[i], sizeof(supplier), 1, p);
        }
        fclose(p);
    }
    int i;
    gotoxy(3, 18);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Supplier Menu Press S");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 's':
        {
            supply();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 's' || 'S');
    getch();
}
void suppdisplay()
{
    box2();
    gotoxy(28, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(39, 2);
    printf("    RECORDS");
    supplier s;
    FILE *p;
    p = fopen("sup.txt", "r");
    int i = 7;
    gotoxy(3, 5);
    SetColor(6);
    printf("Id No  Name                      City                 Mobile No.       Email\n");

    while (fread(&s, sizeof(supplier), 1, p))
    {
        gotoxy(3, i);
        SetColor(7);
        printf("%-4d   %-25s %-20s %-11s %-30s", s.supp_id, s.supp_name, s.city, s.mob_no, s.email);
        i = i + 2;
    }
    fclose(p);
    gotoxy(3, i);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Supplier Menu Press S");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 's':
        {
            supply();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 's' || 'S');
    getch();
}
void supply()
{   wait();
    char c;
    box1();
    gotoxy(18, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(29, 2);
    printf("     SUPPLY");
    gotoxy(3, 5);
    SetColor(6);
    printf("1. Add Supplier");
    gotoxy(3, 7);
    SetColor(6);
    printf("2. Display Suppliers");
    gotoxy(3, 9);
    SetColor(6);
    printf("3. No. Of Suppliers");
    gotoxy(3, 11);
    SetColor(6);
    printf("4. Search Supplier using ID No.");
    gotoxy(3, 13);
    SetColor(6);
    printf("5. Update Supplier Record");
    gotoxy(3, 15);
    SetColor(6);
    printf("6. Delete Suppliers");
    gotoxy(3, 17);
    SetColor(6);
    printf("7. Sort Suppliers on Screen by Name");
    gotoxy(3, 19);
    SetColor(6);
    printf("8. Sort Suppliers in File by Name");
    gotoxy(3, 21);
    SetColor(6);
    printf("9. Sort Suppliers by ID");
    gotoxy(3, 23);
    SetColor(6);
    printf("0. Menu");
    do
    {
        gotoxy(3, 25);
        SetColor(6);
        printf("Enter the Key to select the option: ");
        SetColor(7);
        c = getche();
        switch (c)
        {
        case '1':
        {
            supentry();
            break;
        }
        case '2':
        {
            suppdisplay();
            break;
        }
        case '3':
        {
            noofsup();
            break;
        }
        case '4':
        {
            supsearch();
            break;
        }
        case '5':
        {
            supupdate();
            break;
        }
        case '6':
        {
            supdelete();
            break;
        }
        case '7':
        {
            supsortname();
            break;
        }
        case '8':
        {
            supsortnameinfile();
            break;
        }
        case '9':
        {
            supsortid();
            break;
        }
        case '0':
        {
            box();
            break;
        }
        default:
        {
            gotoxy(3, 27);
            SetColor(4);
            printf("Enter Right Character");
        }
        }
    } while (c != '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9' || '0');
}
void custdelete()
{
    box2();
    gotoxy(28, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(39, 2);
    printf("    DELETE");
    customer c;
    FILE *fp, *fp1;
    int id, found = 0;
    fp = fopen("cust.txt", "r");
    fp1 = fopen("temp.txt", "w");
    gotoxy(3, 5);
    SetColor(6);
    printf("Enter Id No. to delete: ");
    SetColor(7);
    scanf("%d", &id);
    while (fread(&c, sizeof(customer), 1, fp))
    {
        if ((c.cust_id) == (id))
        {
            found = 1;
        }
        else
        {
            fwrite(&c, sizeof(customer), 1, fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    if (found)
    {
        fp = fopen("cust.txt", "w");
        fp1 = fopen("temp.txt", "r");

        while (fread(&c, sizeof(customer), 1, fp1))
        {
            fwrite(&c, sizeof(customer), 1, fp);
        }
        gotoxy(3, 7);
        SetColor(2);
        printf("Customer deleted successfully");
        fclose(fp);
        fclose(fp1);
    }
    else
    {
        SetColor(4);
        gotoxy(3, 7);
        printf("Record not found\n");
    }
    int i;
    gotoxy(3, 15);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Customer Menu Press C");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 'c':
        {
            cust();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 'C' || 'c');
    getch();
}
void custdisplay()
{
    box2();
    gotoxy(28, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(39, 2);
    printf("    RECORDS");
    customer c;
    FILE *p;
    p = fopen("cust.txt", "r");
    int i = 7;
    gotoxy(3, 5);
    SetColor(6);
    printf("Id No  Name                      City                 Mobile No.       Email\n");

    while (fread(&c, sizeof(customer), 1, p))
    {
        gotoxy(3, i);
        SetColor(7);
        printf("%-4d   %-25s %-20s %-11s %-30s", c.cust_id, c.cust_name, c.city, c.mob_no, c.email);
        i = i + 2;
    }
    fclose(p);
    gotoxy(3, i);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Customer Menu Press C");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 'c':
        {
            cust();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 'c' || 'C');
    getch();
}
void custsearch()
{
    customer c;
    box2();
    gotoxy(28, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(39, 2);
    printf("    SEARCH");
    FILE *fp;
    int no, found = 0;
    fp = fopen("cust.txt", "r");
    gotoxy(3, 5);
    SetColor(6);
    printf("Enter ID No. to search: ");
    SetColor(7);
    scanf("%d", &no);
    while (fread(&c, sizeof(customer), 1, fp))
    {
        if (c.cust_id == no)
        {
            found = 1;
            gotoxy(3, 7);
            SetColor(6);
            printf("Id No  Name                      City                 Mobile No.       Email\n");
            gotoxy(3, 9);
            SetColor(7);
            printf("%-4d   %-25s %-20s %-11s %-30s", c.cust_id, c.cust_name, c.city, c.mob_no, c.email);
        }
    }
    if (!found)
    {
        box2();
        gotoxy(3, 7);
        SetColor(4);
        printf("Record not found\n");
    }
    fclose(fp);
    int i;
    gotoxy(3, 15);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Customer Menu Press C");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 'c':
        {
            cust();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 'C' || 'c');
    getch();
}
void custsortid()
{
    customer *c, c1;
    box2();
    gotoxy(28, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(39, 2);
    printf("    ID SORT");
    FILE *fp;
    fp = fopen("cust.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(customer);
    int i, j;
    rewind(fp);
    c = (customer *)calloc(n, sizeof(customer));
    for (i = 0; i < n; i++)
    {
        fread(&c[i], sizeof(customer), 1, fp);
    }
    fclose(fp);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (c[i].cust_id > c[j].cust_id)
            {
                c1 = c[i];
                c[i] = c[j];
                c[j] = c1;
            }
        }
    }
    fp = fopen("cust.txt", "w");
    for (i = 0; i < n; i++)
    {
        fwrite(&c[i], sizeof(customer), 1, fp);
    }
    gotoxy(3, 5);
    SetColor(6);
    printf("Id No  Name                      City                 Mobile No.       Email\n");
    int k = 7;
    for (i = 0; i < n; i++)
    {
        gotoxy(3, k);
        SetColor(7);
        printf("%-4d   %-25s %-20s %-11s %-30s\n", c[i].cust_id, c[i].cust_name, c[i].city, c[i].mob_no, c[i].email);
        k=k+2;
    }
    fclose(fp);
    k += 2;


    gotoxy(3, k);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Customer Menu Press C");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 'c':
        {
            cust();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 'c' || 'C');
    getch();
}
void custsortname()
{
    customer *c, c1;
    box2();
    gotoxy(28, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(39, 2);
    printf("      SORT");
    FILE *fp;
    fp = fopen("cust.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(customer);
    int i, j;
    rewind(fp);
    c = (customer *)calloc(n, sizeof(customer));
    for (i = 0; i < n; i++)
    {

        fread(&c[i], sizeof(customer), 1, fp);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(c[i].cust_name, c[j].cust_name) > 0)
            {
                c1 = c[i];
                c[i] = c[j];
                c[j] = c1;
            }
        }
    }
    gotoxy(3, 5);
    SetColor(6);
    printf("Id No  Name                      City                 Mobile No.       Email\n");
    int k = 7;
    for (i = 0; i < n; i++)
    {
        gotoxy(3, k);
        SetColor(7);
        printf("%-4d   %-25s %-20s %-11s %-30s\n", c[i].cust_id, c[i].cust_name, c[i].city, c[i].mob_no, c[i].email);
        k=k+2;
    }
    fclose(fp);
    k += 2;
    gotoxy(3, k);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Customer Menu Press C");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 'c':
        {
            cust();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 'c' || 'C');
    getch();
}
void custsortnameinfile()
{
    customer *c, c1;
    box2();
    gotoxy(28, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(39, 2);
    printf("      SORT");
    FILE *fp;
    fp = fopen("cust.txt", "r");
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp) / sizeof(customer);
    int i, j;
    rewind(fp);
    c = (customer *)calloc(n, sizeof(customer));
    for (i = 0; i < n; i++)
    {
        fread(&c[i], sizeof(customer), 1, fp);
    }
    fclose(fp);
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(c[i].cust_name, c[j].cust_name) > 0)
            {
                c1 = c[i];
                c[i] = c[j];
                c[j] = c1;
            }
        }
    }
    gotoxy(3, 5);
    SetColor(6);
    printf("Id No  Name                      City                 Mobile No.       Email\n");
    int k = 7;
    for (i = 0; i < n; i++)
    {
        gotoxy(3, k);
        SetColor(7);
        printf("%-4d   %-25s %-20s %-11s %-30s\n", c[i].cust_id, c[i].cust_name, c[i].city, c[i].mob_no, c[i].email);
        k=k+2;
    }
    fp = fopen("cust.txt", "w");

    for (i = 0; i < n; i++)
    {
        fwrite(&c[i], sizeof(customer), 1, fp);
    }

    fclose(fp);
    k += 2;
    gotoxy(3, k);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Customer Menu Press C");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 'c':
        {
            cust();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 'c' || 'C');
    getch();
}
void custupdate()
{
    customer c;
    FILE *fp, *fp1;
    int id, found = 0;
    fp = fopen("cust.txt", "r");
    fp1 = fopen("temp.txt", "w");
    box1();
    gotoxy(3, 5);
    SetColor(6);
    printf("Enter ID No. to update: ");
    SetColor(7);
    scanf("%d", &id);
    while (fread(&c, sizeof(customer), 1, fp))
    {
        if ((c.cust_id) == (id))
        {
            found = 1;
            fflush(stdin);
            box1();
            gotoxy(18, 2);
            SetColor(6);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
            SetColor(7);
            gotoxy(29, 2);
            printf("    UPDATE");
            gotoxy(3, 7);
            SetColor(6);
            printf("Enter New ID No: ");
            SetColor(7);
            scanf("%d", &c.cust_id);
            fflush(stdin);
            gotoxy(3, 9);
            SetColor(6);
            printf("Enter the New Name: ");
            SetColor(7);
            scanf("%[^\n]s", c.cust_name);
            fflush(stdin);
            gotoxy(3, 11);
            SetColor(6);
            printf("Enter the New City:  ");
            SetColor(7);
            scanf("%[^\n]s", c.city);
            fflush(stdin);
            gotoxy(3, 13);
            SetColor(6);
            printf("Enter The New Mob:  ");
            SetColor(7);
            scanf("%[^\n]s", c.mob_no);
            fflush(stdin);
            gotoxy(3, 15);
            SetColor(6);
            printf("Enter the New Email:  ");
            SetColor(7);
            scanf("%[^\n]s", c.email);
            fflush(stdin);
        }
        fwrite(&c, sizeof(customer), 1, fp1);
    }
    fclose(fp);
    fclose(fp1);
    if (found)
    {
        fp = fopen("cust.txt", "w");
        fp1 = fopen("temp.txt", "r");

        while (fread(&c, sizeof(customer), 1, fp1))
        {
            fwrite(&c, sizeof(customer), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
    {
        box2();
        gotoxy(3, 7);
        SetColor(4);
        printf("Record not found\n");
    }
    gotoxy(3, 20);
    int i;
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Customer Menu Press C");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 'c':
        {
            cust();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 'c' || 'C');
    getch();
}
void noofcust()
{
    customer c;
    box1();
    FILE *p;
    p = fopen("cust.txt", "r");
    fseek(p, 0, SEEK_END);
    int n = ftell(p) / sizeof(customer);
    gotoxy(18, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(29, 2);
    printf("    RECORDS");
    gotoxy(3, 7);
    SetColor(7);
    printf("No. Of Records = %d", n);
    fclose(p);
    gotoxy(3, 15);
    SetColor(6);
    int i;
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Customer Menu Press C");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 'c':
        {
            cust();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 'c' || 'C');
    getch();
}
void custentry()
{
    FILE *p;
    p = fopen("cust.txt", "a");
    if (p == 0)
    {
        box1();
        gotoxy(3, 7);
        SetColor(4);
        printf("Couldn't Open");
    }
    else
    {
        box1();
        customer *c;
        int n, i, j;
        gotoxy(3, 5);
        SetColor(6);
        printf("How many Customers you want: ");
        SetColor(7);
        scanf("%d", &n);
        c = (customer *)calloc(n, sizeof(customer));
        for (i = 0; i < n; i++)
        {
            box1();
            gotoxy(18, 2);
            SetColor(6);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
            SetColor(7);
            gotoxy(29, 2);
            printf("     ENTRY");
            gotoxy(3, 7);
            SetColor(6);
            printf("Enter ID No: ");
            scanf("%d", &c[i].cust_id);
            fflush(stdin);
            gotoxy(3, 9);
            SetColor(6);
            printf("Enter  Name: ");
            SetColor(7);
            scanf("%[^\n]s", c[i].cust_name);
            fflush(stdin);
            gotoxy(3, 11);
            SetColor(6);
            printf("Enter City:  ");
            SetColor(7);
            scanf("%[^\n]s", c[i].city);
            fflush(stdin);
            gotoxy(3, 13);
            SetColor(6);
            printf("Enter Mob:  ");
            SetColor(7);
            scanf("%[^\n]s", c[i].mob_no);
            fflush(stdin);
            gotoxy(3, 15);
            SetColor(6);
            printf("Enter Email:  ");
            SetColor(7);
            scanf("%[^\n]s", c[i].email);
            fflush(stdin);
            fwrite(&c[i], sizeof(customer), 1, p);
        }
        fclose(p);
    }
    gotoxy(3, 20);
    int i;
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Customer Menu Press C");
    char ch;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        ch = getche();
        ch = tolower(ch);
        switch (ch)
        {
        case 'm':
        {
            box();
            break;
        }
        case 'c':
        {
            cust();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (ch != 'm' || 'M' || 'c' || 'C');
    getch();
}
void cust()
{   wait();
    char c;
    box1();
    gotoxy(18, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(29, 2);
    printf("   CUSTOMER");
    gotoxy(3, 5);
    SetColor(6);
    printf("1. Add Customers");
    gotoxy(3, 7);
    SetColor(6);
    printf("2. Display Customers");
    gotoxy(3, 9);
    SetColor(6);
    printf("3. No. Of Customers");
    gotoxy(3, 11);
    SetColor(6);
    printf("4. Search Customers using ID No.");
    gotoxy(3, 13);
    SetColor(6);
    printf("5. Update Record");
    gotoxy(3, 15);
    SetColor(6);
    printf("6. Delete Customers");
    gotoxy(3, 17);
    SetColor(6);
    printf("7. Sort Customerss on Screen by Name");
    gotoxy(3, 19);
    SetColor(6);
    printf("8. Sort Customerss in File by Name");
    gotoxy(3, 21);
    SetColor(6);
    printf("9. Sort Customers by ID");
    gotoxy(3, 23);
    SetColor(6);
    printf("0. Menu");
    do
    {
        gotoxy(3, 25);
        SetColor(6);
        printf("Enter the Key to select the option: ");
        SetColor(7);
        c = getche();
        switch (c)
        {
        case '1':
        {
            custentry();
            break;
        }
        case '2':
        {
            custdisplay();
            break;
        }
        case '3':
        {
            noofcust();
            break;
        }
        case '4':
        {
            custsearch();
            break;
        }
        case '5':
        {
            custupdate();
            break;
        }
        case '6':
        {
            custdelete();
            break;
        }
        case '7':
        {
            custsortname();
            break;
        }
        case '8':
        {
            custsortnameinfile();
            break;
        }
        case '9':
        {
            custsortid();
            break;
        }
        case '0':
        {
            box();
            break;
        }
        default:
        {
            gotoxy(3, 27);
            SetColor(4);
            printf("Enter Right Character");
            break;
        }
        }
    } while (c != '1' || '2' || '3' || '4' || '5' || '6' || '7' || '8' || '9' || '0');
}
void medisell()
{
    time_t now = time(0);
    struct tm *si = localtime(&now);
    medical m;
    bill b;
    salesrpt s;
    FILE *fp, *fp1, *p, *e;
    int id, found = 0, sum = 0;
    char ch = 'y';
    char nam[30];
    int k = 1;
    box3();
    fp = fopen("medicine.txt", "r");
    fp1 = fopen("temp.txt", "w");
    p = fopen("bill.txt", "a");
    e = fopen("salesrpt.txt", "a");
    box2();
    gotoxy(3, 5);
    SetColor(6);
    printf("Enter the Customer Name: ");
    SetColor(7);
    fflush(stdin);
    scanf("%[^\n]s", nam);
    while (ch == 'y' || ch == 'Y')
    {
        if (k != 1)
        {
            fp = fopen("medicine.txt", "r");
            fp1 = fopen("temp.txt", "w");
        }
        box2();
        gotoxy(3, 5);
        rewind(fp);
        gotoxy(3, 5);
        SetColor(6);
        printf("Enter Medicine ID to be Sold: ");
        SetColor(7);
        scanf("%d", &id);
        while (fread(&m, sizeof(medical), 1, fp))
        {
            if ((m.id) == (id))
            {
                found = 1;
                box1();
                strcpy(b.cname, nam);
                gotoxy(3, 5);
                SetColor(6);
                printf("Enter the Customer Name: ");
                SetColor(7);
                fflush(stdin);
                printf("%s", b.cname);
                box1();
                gotoxy(3, 7);
                SetColor(6);
                printf("Medcine Name: ");
                SetColor(7);
                fflush(stdin);
                printf("%s", m.medi_name);
                fflush(stdin);
                strcpy(b.mediname, m.medi_name);
                gotoxy(3, 9);
                SetColor(6);
                printf("Quantity Available: ");
                SetColor(7);
                printf("%d", m.quantity);
                gotoxy(3, 11);
                SetColor(6);
                printf("Price of Each quantity: ");
                SetColor(7);
                fflush(stdin);
                printf("%.2f", m.sell);
                gotoxy(3, 13);
                SetColor(6);
                printf("Customer Name: ");
                SetColor(7);
                fflush(stdin);
                printf("%s", b.cname);
                gotoxy(3, 15);
                SetColor(6);
                printf("Bill number: ");
                SetColor(7);
                scanf("%d", &m.bill_no);
                b.billno = m.bill_no;
                gotoxy(3, 17);
                SetColor(6);
                printf("Enter the Quantity to Sell: ");
                SetColor(7);
                fflush(stdin);
                scanf("%d", &b.medi_qty);
                m.quantity = m.quantity - b.medi_qty;
                b.day = si->tm_mday;
                b.month = si->tm_mon + 1;
                b.year = si->tm_year + 1900;
                b.medi_rate = m.sell;
                ch = 'f';
                strcpy(s.cust_name, b.cname);
                s.medi_id = m.id;
                strcpy(s.medir_name, m.medi_name);
                s.rate = m.sell;
                s.sDay = si->tm_mday;
                s.sMonth = si->tm_mon + 1;
                s.sYear = si->tm_year + 1900;
                s.qty = b.medi_qty;
                s.total = b.medi_qty * m.sell;
                b.total = s.total;
            }
            fwrite(&m, sizeof(medical), 1, fp1);
        }
        fwrite(&b, sizeof(bill), 1, p);
        fwrite(&s, sizeof(salesrpt), 1, e);
        fclose(fp);
        fclose(fp1);
        k++;

        if (found)
        {
            fp = fopen("medicine.txt", "w");
            fp1 = fopen("temp.txt", "r");

            while (fread(&m, sizeof(medical), 1, fp1))
            {
                fwrite(&m, sizeof(medical), 1, fp);
            }
            fclose(fp);
            fclose(fp1);
            box1();
            SetColor(6);
            gotoxy(3, 9);
            printf("Want add more y/n: ");
            SetColor(7);
            ch = getch();
            found = 0;
        }
        else
        {
            SetColor(4);
            box1();
            gotoxy(3, 5);
            printf("Medicine not found");
            SetColor(6);
            gotoxy(3, 7);
            printf("Want add more y/n: ");
            ch = getch();
        }
    }
    fclose(p);
    fclose(e);
    gotoxy(3, 15);
    int i;
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Medicine Menu Press T");
    char c;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        c = getche();
        c = tolower(c);
        switch (c)
        {
        case 'm':
        {
            box();
            break;
        }
        case 't':
        {
            medi();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (c != 'm' || 'M' || 't' || 'T');
    getch();
}
void medisearch()
{
    medical m;
    box2();
    gotoxy(28, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb            \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(39, 2);
    printf("   MEDI SEARCH");
    FILE *fp;
    int no, found = 0;
    fp = fopen("medicine.txt", "r");
    gotoxy(3, 5);
    SetColor(6);
    printf("Enter Medicine ID to search: ");
    SetColor(7);
    scanf("%d", &no);
    while (fread(&m, sizeof(medical), 1, fp))
    {
        if (m.id == no)
        {
            found = 1;
            gotoxy(3, 7);
            SetColor(6);
            printf("ID      Medicine Name         QTY.         Supplier Name         Rack No.  Expiry Date");
            gotoxy(3, 9);
            SetColor(7);
            printf("%-4d    %-20s   %-3d  %-30s %-2d      %-15s", m.id, m.medi_name, m.quantity, m.supp_name,m.rack, m.exp_date);
        }
    }
    if (!found)
    {
        gotoxy(3, 7);
        SetColor(4);
        printf("Medicine not found\n");
    }
    fclose(fp);
    gotoxy(3, 20);
    int i;
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Medicine Menu Press T");
    char c;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        c = getche();
        c = tolower(c);
        switch (c)
        {
        case 'm':
        {
            box();
            break;
        }
        case 't':
        {
            medi();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (c != 'm' || 'M' || 't' || 'T');
    getch();
}
void medistockupdate()
{
    time_t now = time(0);
    struct tm *si = localtime(&now);

    medical m;
    purchaserpt p;
    FILE *fp, *fp1,*fp2;
    int id, found = 0;
    fp = fopen("medicine.txt", "r");
    fp2 = fopen("purchaserpt.txt", "a");
    fp1 = fopen("temp.txt", "w");
    box1();
    gotoxy(3, 5);
    SetColor(6);
    printf("Enter Medicine ID to update the stock: ");
    SetColor(7);
    scanf("%d", &id);
    while (fread(&m, sizeof(medical), 1, fp))
    {   int n;
        if ((m.id) == (id))
        {
            found = 1;
            fflush(stdin);
            box1();
            gotoxy(3, 7);
            SetColor(6);
            printf("Medcine Name: ");
            SetColor(7);
            printf("%s", m.medi_name);
            fflush(stdin);
            gotoxy(3, 9);
            SetColor(6);
            printf("Quantity Available: ");
            SetColor(7);
            printf("%d", m.quantity);
            fflush(stdin);
            gotoxy(3, 11);
            SetColor(6);
            printf("Enter the Quantity To Update: ");
            SetColor(7);
            scanf("%d", &n);
            fflush(stdin);
            m.quantity=m.quantity + n;
            p.medi_id=m.id;
            strcpy(p.medi_name,m.medi_name);
            p.qty = n;
            p.rate = m.cost;
            strcpy(p.supp_name,m.supp_name);
            p.sDay = si->tm_mday;
            p.sMonth = si->tm_mon + 1;
            p.sYear = si->tm_year + 1900;
            p.total = m.cost * n;

        }
        fwrite(&m, sizeof(medical), 1, fp1);
    }
    fwrite(&p,sizeof(purchaserpt),1,fp2);
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    if (found)
    {
        fp = fopen("medicine.txt", "w");
        fp1 = fopen("temp.txt", "r");

        while (fread(&m, sizeof(medical), 1, fp1))
        {
            fwrite(&m, sizeof(medical), 1, fp);
        }
        fclose(fp);
        fclose(fp1);
    }
    else
    {
        SetColor(4);
        gotoxy(3, 11);
        printf("Record not found\n");
    }
    gotoxy(3, 15);
    int i;
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Medicine Menu Press T");
    char c;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        c = getche();
        c = tolower(c);
        switch (c)
        {
        case 'm':
        {
            box();
            break;
        }
        case 't':
        {
            medi();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (c != 'm' || 'M' || 't' || 'T');
    getch();
}
void medistock()
{
    medical m;
    FILE *p;
    box3();
    gotoxy(28, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(39, 2);
    printf("     STOCK");
    p = fopen("medicine.txt", "r");
    gotoxy(3, 5);
    SetColor(6);
    printf("ID      Medicine Name         QTY.         Supplier Name          Expiry Date");
    int i = 7;
    while (fread(&m, sizeof(medical), 1, p))
    {
        gotoxy(3, i);
        SetColor(7);
        printf("%-4d    %-20s   %-3d  %-30s %-15s", m.id, m.medi_name, m.quantity, m.supp_name, m.exp_date);
        i = i + 2;
    }
    fclose(p);
    i++;
    gotoxy(3, i);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Medicine Menu Press T");
    char c;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        c = getche();
        c = tolower(c);
        switch (c)
        {
        case 'm':
        {
            box();
            break;
        }
        case 't':
        {
            medi();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (c != 'm' || 'M' || 't' || 'T');
    getch();
}
void medipur()
{
    FILE *p, *fp;
    p = fopen("medicine.txt", "a");
    fp = fopen("purchaserpt.txt", "a");
    box2();
    if (p == 0)
    {
        SetColor(4);
        printf("Couldn't Open");
    }
    else
    {
        time_t now = time(0);
        struct tm *si = localtime(&now);
        medical *m;
        purchaserpt *q;
        int n, i, j;
        gotoxy(3, 4);
        SetColor(6);
        printf("How many Medicines you want to Purchase: ");
        SetColor(7);
        scanf("%d", &n);
        m = (medical *)calloc(n, sizeof(medical));
        q = (purchaserpt *)calloc(n, sizeof(purchaserpt));
        for (i = 0; i < n; i++)
        {
            box2();
            gotoxy(3, 6);
            SetColor(6);
            printf("Medicine id: ");
            SetColor(7);
            scanf("%d", &m[i].id);
            fflush(stdin);
            gotoxy(3, 8);
            SetColor(6);
            printf("Medicine name: ");
            SetColor(7);
            scanf("%[^\n]s", m[i].medi_name);
            fflush(stdin);
            gotoxy(3, 10);
            SetColor(6);
            printf("Rack No. ");
            SetColor(7);
            scanf("%d", &m[i].rack);
            fflush(stdin);
            gotoxy(3, 12);
            SetColor(6);
            printf("Company Name: ");
            SetColor(7);
            scanf("%[^\n]s", m[i].comp_name);
            fflush(stdin);
            gotoxy(3, 14);
            SetColor(6);
            printf("Supplier Name: ");
            SetColor(7);
            scanf("%[^\n]s", m[i].supp_name);
            fflush(stdin);
            gotoxy(3, 16);
            SetColor(6);
            printf("Unit Cost Price Rs. ");
            SetColor(7);
            scanf("%f", &m[i].cost);
            fflush(stdin);
            gotoxy(3, 18);
            SetColor(6);
            printf("Unit Selling Price Rs. ");
            SetColor(7);
            scanf("%f", &m[i].sell);
            fflush(stdin);
            gotoxy(3, 20);
            SetColor(6);
            printf("Quantity ");
            SetColor(7);
            scanf("%d", &m[i].quantity);
            fflush(stdin);
            gotoxy(3, 22);
            SetColor(6);
            printf("Manu. Date: ");
            SetColor(7);
            scanf("%[^\n]s", m[i].manu_date);
            fflush(stdin);
            gotoxy(3, 24);
            SetColor(6);
            printf("EXP. Date: ");
            SetColor(7);
            scanf("%[^\n]s", m[i].exp_date);
            q[i].medi_id = m[i].id;
            strcpy(q[i].medi_name, m[i].medi_name);
            q[i].qty = m[i].quantity;
            q[i].rate = m[i].cost;
            strcpy(q[i].supp_name, m[i].supp_name);
            q[i].sDay = si->tm_mday;
            q[i].sMonth = si->tm_mon + 1;
            q[i].sYear = si->tm_year + 1900;
            q[i].total = m[i].cost * m[i].quantity;
            fwrite(&m[i], sizeof(medical), 1, p);
            fwrite(&q[i], sizeof(purchaserpt), 1, fp);
        }
        fclose(p);
        fclose(fp);
    }
    gotoxy(3, 27);
    int i;
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Medicine Menu Press T");
    char c;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        c = getche();
        c = tolower(c);
        switch (c)
        {
        case 'm':
        {
            box();
            break;
        }
        case 't':
        {
            medi();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (c != 'm' || 'M' || 't' || 'T');
    getch();
}
void medi()
{   wait();
    box1();
    char c;
    gotoxy(20, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(31, 2);
    printf("    MEDICINE");
    gotoxy(3, 5);
    SetColor(6);
    printf("1. Purchase Medicine");
    gotoxy(3, 7);
    SetColor(6);
    printf("2. Sell Medicine");
    gotoxy(3, 9);
    SetColor(6);
    printf("3. Stock of Medicine");
    gotoxy(3, 11);
    SetColor(6);
    printf("4. Update Stock");
    gotoxy(3, 13);
    SetColor(6);
    printf("5. Search Medicine");
    gotoxy(3, 15);
    SetColor(6);
    printf("0. Menu");
    do
    {
        gotoxy(3, 17);
        SetColor(6);
        printf("Enter the character: ");
        SetColor(7);
        c = getche();
        switch (c)
        {
        case '1':
        {
            medipur();
            break;
        }
        case '2':
        {
            medisell();
            break;
        }
        case '3':
        {
            medistock();
            break;
        }
        case '4':
        {
            medistockupdate();
            break;
        }
        case '5':
        {
            medisearch();
            break;
        }
        case '0':
        {
            box();
            break;
        }
        default:
        {
            gotoxy(3, 19);
            SetColor(4);
            printf("Enter Right Character");
            break;
        }
        }
    } while (c != '0' || '1' || '2' || '3' || '4' || '5');
}
void salereport()
{
    salesrpt m;
    FILE *p;
    box3();
    gotoxy(25, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb                    \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(37, 2);
    printf("     SALES REPORT");
    p = fopen("salesrpt.txt", "r");
    gotoxy(3, 5);
    SetColor(6);
    printf("ID      Medicine Name          Customer Name                   QTY. Rate   Total    Date");
    int i = 7;
    while (fread(&m, sizeof(salesrpt), 1, p))
    {
        gotoxy(3, i);
        SetColor(7);
        printf("%-4d    %-20s   %-30s  %-3d  %-3.2f  %-7.2f   %02d/%02d/%-4d", m.medi_id, m.medir_name, m.cust_name, m.qty, m.rate, m.total, m.sDay, m.sMonth, m.sYear);
        i = i + 2;
    }
    fclose(p);
    i += 2;
    gotoxy(3, i);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Report Menu Press R");
    char c;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        c = getche();
        c = tolower(c);
        switch (c)
        {
        case 'm':
        {
            box();
            break;
        }
        case 'r':
        {
            report();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (c != 'm' || 'M' || 'r' || 'R');
    getch();
}
void purreport()
{
    purchaserpt m;
    FILE *p;
    box3();
    gotoxy(25, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb                    \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(37, 2);
    printf("   PURCHASE REPORT");
    p = fopen("purchaserpt.txt", "r");
    gotoxy(3, 5);
    SetColor(6);
    printf("ID      Medicine Name          Supplier Name                   QTY. Rate   Total    Date");
    int i = 7;
    while (fread(&m, sizeof(purchaserpt), 1, p))
    {
        gotoxy(3, i);
        SetColor(7);
        printf("%-4d    %-20s   %-30s  %-3d  %-3.2f  %-7.2f  %02d/%02d/%-4d", m.medi_id, m.medi_name, m.supp_name, m.qty, m.rate, m.total, m.sDay, m.sMonth, m.sYear);
        i = i + 2;
    }
    fclose(p);
    i += 2;
    gotoxy(3, i);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Report Menu Press R");
    char c;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        c = getche();
        c = tolower(c);
        switch (c)
        {
        case 'm':
        {
            box();
            break;
        }
        case 'r':
        {
            report();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (c != 'm' || 'M' || 'r' || 'R');
    getch();
}
void report()
{   wait();
    box1();
    gotoxy(18, 2);
    SetColor(6);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
    SetColor(7);
    gotoxy(29, 2);
    printf("    REPORT");
    char c;
    gotoxy(3, 5);
    SetColor(6);
    printf("1. Purchase Report");
    gotoxy(3, 7);
    SetColor(6);
    printf("2. Sales Report");
    gotoxy(3, 9);
    SetColor(6);
    printf("0. Menu");
    do
    {
        gotoxy(3, 11);
        SetColor(6);
        printf("Enter the character: ");
        SetColor(7);
        c = getche();
        switch (c)
        {
        case '1':
        {
            purreport();
            break;
        }
        case '2':
        {
            salereport();
            break;
        }
        case '0':
        {
            box();
            break;
        }
        default:
        {
            gotoxy(3, 19);
            SetColor(4);
            printf("Enter Right Character");
            break;
        }
        }
    } while (c != '1' || '2' || '0');
}
void billing()
{
    bill b;
    FILE *fp;
    fp = fopen("bill.txt", "r");
    static int i = 10;
    int j = 1;
    int bi;
    float total = 0;
    box2();
    gotoxy(3, 5);
    SetColor(6);
    printf("Enter the Bill No: ");
    SetColor(7);
    scanf("%d", &bi);
    system("cls");
    box4();
    while (fread(&b, sizeof(bill), 1, fp))
    {
        if (b.billno == bi)
        {
            gotoxy(18, 2);
            SetColor(6);
            printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb\xDb\xDb           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDb");
            SetColor(7);
            gotoxy(29, 2);
            printf("      BILL");
            gotoxy(3, 4);
            SetColor(6);
            printf("Bill No: ");
            SetColor(7);
            printf("%d", bi);
            gotoxy(57, 4);
            SetColor(6);
            printf("Date: ");
            SetColor(7);
            printf("%2d/%02d/%-4d", b.day, b.month, b.year);
            gotoxy(3, 6);
            SetColor(6);
            printf("Customer Name: ");
            SetColor(7);
            printf("%s", b.cname);
            gotoxy(3, 8);
            printf("SL.No.   Medicine Name                       Qty.    Rate       Total");
            gotoxy(3, i);
            SetColor(7);
            printf("%-2d       %-30s      %-3d     %-4.2f      %4.2f", j, b.mediname, b.medi_qty, b.medi_rate, b.total);
            j++;
            i += 2;
            total = total + b.total;
        }
    }
    gotoxy(3, i);
    printf("----------------------------------------------------------------------");
    i += 2;
    gotoxy(60, i);
    SetColor(6);
    printf("Total: ");
    SetColor(7);
    printf("%4.2f", total);

    gotoxy(3, i + 2);
    SetColor(6);
    printf("Press Any Character: ");
    getch();
    i = 5;
    box2();
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Main Menu Press M");
    i = i + 2;
    gotoxy(3, i);
    SetColor(6);
    printf("\xDb For Bill Menu Press B");
    char c;
    i = i + 2;
    do
    {
        gotoxy(3, i);
        SetColor(6);
        printf("Enter the character: ");
        c = getche();
        c = tolower(c);
        switch (c)
        {
        case 'm':
        {
            box();
            break;
        }
        case 'b':
        {
            billing();
            break;
        }
        default:
            gotoxy(3, i + 1);
            SetColor(4);
            printf("Enter Right Character");
        }
    } while (c != 'm' || 'M' || 'b' || 'B');
    getch();
}
void box()
{
    system("cls");
    SetColor(3);
    for (int i = 1; i < 81; i++)
    {
        gotoxy(i, 1);
        printf("%c", 205);
    }
    gotoxy(81, 1);
    printf("%c", 187);
    gotoxy(0, 1);
    printf("%c", 201);
    for (int i = 2; i < 34; i++)
    {
        gotoxy(0, i);
        printf("%c", 186);
    }
    for (int i = 1; i < 81; i++)
    {
        gotoxy(i, 34);
        printf("%c", 205);
    }
    gotoxy(0, 34);
    printf("%c", 200);
    for (int i = 2; i < 34; i++)
    {
        gotoxy(81, i);
        printf("%c", 186);
    }
    gotoxy(81, 34);
    printf("%c", 188);
    gotoxy(20, 2);
    SetColor(6);
    printf(" \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB           \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    SetColor(7);
    gotoxy(33, 2);
    printf(" Main Menu");
    SetColor(7);
    gotoxy(3, 5);
    printf("\xDb 1.");
    SetColor(7);
    printf(" Supply");
    gotoxy(3, 7);
    printf("\xDB 2. Customer");
    gotoxy(3, 9);
    printf("\xDb 3. Medicine");
    gotoxy(3, 11);
    printf("\xDb 4. Reports");
    gotoxy(3, 13);
    printf("\xDb 5. Billing");
    char a;
    do{
    gotoxy(3, 37);
    SetColor(7);
    printf("Enter the character: ");
    a = getche();
    switch (a)
    {
    case '1':
    {
        supply();
        break;
    }
    case '2':
    {
        cust();
        break;
    }
    case '3':
    {
        medi();
        break;
    }
    case '4':
    {
        report();
        break;
    }
    case '5':
    {
        billing();
        break;
    }
    default:{
            gotoxy(3, 38);
            SetColor(4);
            printf("Enter Right Character");
        }
    }
    }while(a !='1'||'2'||'3'||'4'||'5');
}
void box1()
{
    system("cls");
    SetColor(3);
    for (int i = 1; i < 81; i++)
    {
        gotoxy(i, 1);
        printf("%c", 205);
    }
    gotoxy(81, 1);
    printf("%c", 187);
    gotoxy(0, 1);
    printf("%c", 201);
    for (int i = 2; i < 34; i++)
    {
        gotoxy(0, i);
        printf("%c", 186);
    }
    for (int i = 1; i < 81; i++)
    {
        gotoxy(i, 34);
        printf("%c", 205);
    }
    gotoxy(0, 34);
    printf("%c", 200);
    for (int i = 2; i < 34; i++)
    {
        gotoxy(81, i);
        printf("%c", 186);
    }
    gotoxy(81, 34);
    printf("%c", 188);
}
void box2()
{
    system("cls");
    SetColor(3);
    for (int i = 1; i < 100; i++)
    {
        gotoxy(i, 1);
        printf("%c", 205);
    }
    gotoxy(100, 1);
    printf("%c", 187);
    gotoxy(0, 1);
    printf("%c", 201);
    for (int i = 2; i < 34; i++)
    {
        gotoxy(0, i);
        printf("%c", 186);
    }
    for (int i = 1; i < 100; i++)
    {
        gotoxy(i, 34);
        printf("%c", 205);
    }
    gotoxy(0, 34);
    printf("%c", 200);
    for (int i = 2; i < 34; i++)
    {
        gotoxy(100, i);
        printf("%c", 186);
    }
    gotoxy(100, 34);
    printf("%c", 188);
}
void box3()
{
    system("cls");
    SetColor(3);
    for (int i = 1; i < 100; i++)
    {
        gotoxy(i, 1);
        printf("%c", 205);
    }
    gotoxy(100, 1);
    printf("%c", 187);
    gotoxy(0, 1);
    printf("%c", 201);
    for (int i = 2; i < 38; i++)
    {
        gotoxy(0, i);
        printf("%c", 186);
    }
    for (int i = 1; i < 100; i++)
    {
        gotoxy(i, 38);
        printf("%c", 205);
    }
    gotoxy(0, 38);
    printf("%c", 200);
    for (int i = 2; i < 38; i++)
    {
        gotoxy(100, i);
        printf("%c", 186);
    }
    gotoxy(100, 38);
    printf("%c", 188);
}
void box4()
{
    system("cls");
    SetColor(3);
    for (int i = 1; i < 75; i++)
    {
        gotoxy(i, 1);
        printf("%c", 205);
    }
    gotoxy(75, 1);
    printf("%c", 187);
    gotoxy(0, 1);
    printf("%c", 201);
    for (int i = 2; i < 38; i++)
    {
        gotoxy(0, i);
        printf("%c", 186);
    }
    for (int i = 1; i < 75; i++)
    {
        gotoxy(i, 38);
        printf("%c", 205);
    }
    gotoxy(0, 38);
    printf("%c", 200);
    for (int i = 2; i < 38; i++)
    {
        gotoxy(75, i);
        printf("%c", 186);
    }
    gotoxy(75, 38);
    printf("%c", 188);
}