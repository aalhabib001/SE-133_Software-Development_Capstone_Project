#include <stdio.h>
#include <windows.h>
char array[24][79]= {NULL};
int h=35;
int i=22;
int j=29;
int x=0;
int y=0;

void plate();
void gotoxy(int x,int y)
{
    HANDLE console_handle;
    COORD cursor_coord;
    cursor_coord.X=x;
    cursor_coord.Y=y;
    console_handle= GetStdHandle( STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(console_handle,cursor_coord);
}

void move(char array[24][79])
{
    system("color FC");
    char space='32';
    char ball='O';
    char grid='229';
    int x=23;
    int y=-4+rand()%70;
    int x1=40,y2=2;

    while(1)
    {
        plate();
        Sleep(50);
        gotoxy(y-1,x+1);
        gotoxy(y,x);
        printf("%c",ball);
        if((x-1)==3)
        {
            gotoxy(y-1,x+1);
            printf("%c",ball);
            gotoxy(y,0);
            printf("%c",grid);
            while(1)
            {
                Sleep(50);
                if((y+1)==78)
                {
                    gotoxy(y-1,x-1);
                    printf("%c",space);
                    while(1)
                    {
                        y=y-1;
                        x=x+1;
                        if(x==23)
                        {
                            gotoxy(y-1,x+1);
                            printf("%c",space);
                            gotoxy(y,23);
                            printf("%c",grid);
                            while(1)
                            {
                                Sleep(50);
                                if(x==23)
                                {
                                    gotoxy(0,25);
                                    printf("sorry better luck\n");
                                }
                            }
                            gotoxy(y+1,x-1);
                            printf("%c",space);
                            gotoxy(y,x);
                            printf("%c",ball);
                            y=y-1;
                            x=x-1;


                        }
                        Sleep(50);
                        gotoxy(y+1,x-1);
                        printf("%c",space);
                        gotoxy(y,x);
                        printf("%c",ball);
                    }
                }
                x=x+1;
                y=y+1;
                gotoxy(y-1,x-1);
                printf("%c",space);
                gotoxy(y,x);
                printf("%c",ball);

            }
        }
        x=x-1;
        y=y+1;
    }
}

void grid(char array[][79],int row,int col)
{

    system("color FC");
    int i, j, grid=219,brick=35,space=32;
    for(i=1; i<5; i++)
    {
        for(j=2; j<col; j++)
        {
            array[i][j]=brick;
        }
    }
    for(i=0, j=0; j<col; j++)
    {
        array[i][j]=grid;
    }
    for(i=23, j=0; j<col; j++)
    {
        array[i][j]=grid;
    }
    for(i=0, j=0; i<row; i++)
    {
        array[i][j]=grid;
    }
    for(i=0, j=78; i<row; i++)
    {
        array[i][j]=grid;
    }
    for(i=22,j=35; j<40; j++)
    {
        array[i][j]=grid;
    }
    for(i=0; i<24; i++)
    {
        for(j=0; j<79; j++)
        {

            printf("%c",array[i][j]);
        }
        printf("\n");
    }

}

void plate()
{
    char ch;
    scanf("%c",&ch);
    if(1)
    {
        if(ch=='a')
        {
            printf("a");
            array[22][h+4]=' ';
            array[22][h-1]= 219;

        }
    }
}
    int main()
    {
        system("color FC");
        char input;
        printf("please press c to play the brick game:\n");
        scanf("%c",&input);

        {
            grid(array,24,79);
            move(array);

        }
    }
