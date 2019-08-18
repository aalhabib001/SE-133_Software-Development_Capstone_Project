#include <stdio.h>
#include <string.h>
#include <time.h>

int products = 17;
int a;
int b;
int c = 0;
int product_choiced[100];
int total_total = 0;
int total = 0;
int choice;
char t[100];
struct product_list
{
    int product_index;
    char product_name[50];
    int product_price;
} product_available[30];

void varriable_declure()
{
    for (int i = 1; i <= 30; i++)
    {
        product_available[i].product_index = i;
    }
    strcpy(product_available[1].product_name, "Processor Amd");
    strcpy(product_available[2].product_name, "Processor Intel");
    strcpy(product_available[3].product_name, "Motherboard Amd");
    strcpy(product_available[4].product_name, "Motherboard Intel");
    strcpy(product_available[5].product_name, "Ram 4GB");
    strcpy(product_available[6].product_name, "Ram 8GB");
    strcpy(product_available[7].product_name, "Hard Drive");
    strcpy(product_available[8].product_name, "Solid State Drive");
    strcpy(product_available[9].product_name, "Power Supply Unit");
    strcpy(product_available[10].product_name, "Graphics Card Amd");
    strcpy(product_available[11].product_name, "Graphics Card NVidia");
    strcpy(product_available[12].product_name, "Monitor 21 Inch");
    strcpy(product_available[13].product_name, "Monitor 17 Inch");
    strcpy(product_available[14].product_name, "DVD Writter");
    strcpy(product_available[15].product_name, "Keyboard");
    strcpy(product_available[16].product_name, "Mouse");

    product_available[1].product_price = 22500;
    product_available[2].product_price = 25500;
    product_available[3].product_price = 6700;
    product_available[4].product_price = 7300;
    product_available[5].product_price = 2300;
    product_available[6].product_price = 4200;
    product_available[7].product_price = 3600;
    product_available[8].product_price = 2400;
    product_available[9].product_price = 6600;
    product_available[10].product_price = 34000;
    product_available[11].product_price = 43000;
    product_available[12].product_price = 10500;
    product_available[13].product_price = 7600;
    product_available[14].product_price = 1300;
    product_available[15].product_price = 550;
    product_available[16].product_price = 260;
}

void main_menu();
int main();

struct customar_info
{
    char name[50];
    char phone_number[50];
    char address[100];
} customar;
int calculation(int choiced[], int c)
{
    for (int i = 0; i < c; i++)
    {
        total += product_available[product_choiced[i]].product_price;
    }
    return total;
}
void timee()
{
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strcpy(t, asctime(timeinfo));
}
void memo_print(int Total)
{
    system("CLS");
    Total += Total * .13;
    printf("------------ HABIB's Computer Shop----------\n");
    printf("-            14/B Los Angeles,USA          -\n");
    printf("-                                          -\n");
    printf("-  Time   : %s", t);
    printf("-  Bill To: %s                             \n", customar.name);
    printf("-  Phone  : %s                             \n", customar.phone_number);
    printf("-  Address: %s                             \n", customar.address);
    printf("--------------------------------------------\n");
    printf("\n-  Products:                               -\n");
    for (int i = 0; i < c; i++)
    {
        printf("-  %d.", i + 1);
        printf("%s", product_available[product_choiced[i]].product_name);
        printf(" %d/-\n", product_available[product_choiced[i]].product_price);
    }
    printf("--------------------------------------------\n");
    printf("-  Bill           : %d\n", total);
    printf("--------------------------------------------\n");
    printf("-  Vat 13%%        : %d\n", Total - total);
    printf("--------------------------------------------\n");
    printf("-  Total Bill     : %d\n", Total);
    printf("--------------------------------------------\n");
    printf("Press 0 to back in main menu: ");
    scanf("%d", &choice);
    if (choice == 0)
    {
        main_menu();
    }
}
void make_bill()
{
    system("CLS");
    printf("------------ HABIB's Computer Shop---------\n");
    for (int i = 1; i < products; i++)
    {
        printf("- ");
        printf("%d.", product_available[i].product_index);
        printf("%s", product_available[i].product_name);
        printf(" %d/-\n", product_available[i].product_price);
    }
    printf("-------------------------------------------\n");
    printf("Enter Your Choiced product ids: ");
    for (int i = 0; i < products; i++)
    {
        scanf("%d", &a);
        if (a == 0)
        {
            break;
        }
        else
        {
            product_choiced[i] = a;
            c++;
        }
    }
    total_total = calculation(product_choiced, c);
    system("CLS");
    printf("------------ HABIB's Computer Shop---------\n");
    printf("- Enter Your Name: ");
    scanf("%s", customar.name);
    printf("- Enter Your Phone Number: ");
    scanf("%s", customar.phone_number);
    printf("- Enter Your Address: ");
    scanf("%s", customar.address);
    memo_print(total_total);
}
void show_product_info()
{
    system("CLS");
    printf("------------ HABIB's Computer Shop----------\n");
    for (int i = 1; i < products; i++)
    {
        printf("- ");
        printf("%d.", product_available[i].product_index);
        printf("%s", product_available[i].product_name);
        printf(" %d/-\n", product_available[i].product_price);
    }
    printf("-------------------------------------------\n");
    printf("Press 0 to back in main menu: ");
    scanf("%d", &choice);
    if (choice == 0)
    {
        main_menu();
    }
}
void edit_price()
{
    system("CLS");
    varriable_declure();
    printf("------------ HABIB's Computer Shop----------\n");
    for (int i = 1; i < products; i++)
    {
        printf("- ");
        printf("%d.", product_available[i].product_index);
        printf("%s", product_available[i].product_name);
        printf(" %d/-\n", product_available[i].product_price);
    }
    printf("-------------------------------------------\n");
    printf("Choice which products price you wants to change: ");
    scanf("%d", &choice);
    printf("Enter The new price of %s : ", product_available[choice].product_name);
    int aa = product_available[choice].product_price;
    scanf("%d", &product_available[choice].product_price);
    printf("Price changed successfully.\n", product_available[choice].product_price);
    printf("Old price was %d & new price is %d\n", aa, product_available[choice].product_price);
    printf("-------------------------------------------\n");
    printf("Press 0 to back in main menu: ");
    scanf("%d", &choice);

    if (choice == 0)
    {
        main_menu();
    }
}
void add_new_product()
{
    printf("------------ HABIB's Computer Shop----------\n");
    products++;
    system("CLS");
    printf("Enter Product index: ");
    scanf("%d", &product_available[products - 1].product_index);
    printf("Enter Product Name: ");
    scanf("%s", &product_available[products - 1].product_name);
    printf("Enter Product Price: ");
    scanf("%d", &product_available[products - 1].product_price);
    printf("-------------------------------------------\n");
    printf("Press 0 to back in main menu: ");
    scanf("%d", &choice);

    if (choice == 0)
    {
        main_menu();
    }
}
void main_menu()
{
    system("CLS");
    printf("-------Welcome To HABIB's Computer Shop------\n");
    printf("-                                           -\n");
    printf("- 1.Make Bill                               -\n");
    printf("- 2.Show All Products & Info                -\n");
    printf("- 3.Edit Price of Product                   -\n");
    printf("- 4.Add New Product to the list             -\n");
    printf("-                                           -\n");
    printf("---------------------------------------------\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        make_bill();
        break;
    case 2:
        show_product_info();
        break;
    case 3:
        edit_price();
        break;
    case 4:
        add_new_product();
    default:
        main();
        break;
    }
}
int main()
{
    system("CLS");
    varriable_declure();
    timee();
    main_menu();
}
