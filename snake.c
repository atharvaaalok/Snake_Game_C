#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

// we will use some pre defined functions

// kbhit() - keyboard hit function -> inside conio.h
// rand() - generates random number -> inside stdlib.h
// this rand function returns a very large value so we can use it
// after doing modulus with some number


// first we want to make a boundary
void draw();
int width = 20;
int height = 20;

// setting initial variables
void setup(); 

int x, y, fruitX, fruitY, score, gameOver, flag;

void input();
void makelogic();
int tailX[100], tailY[100];
int CountTail;



int main()
{
    int m, n;
    char c;
    label5:
    setup();
    while(!gameOver)
    {
        draw();
        input();
        makelogic();
        for (m = 0; m < 10000; m++)         // better use  sleep function
        {
            for (n = 0; n < 10000; n++)
            {

            }
        }
        for (m = 0; m < 1000; m++)         // better use  sleep function
        {
            for (n = 0; n < 10000; n++)
            {

            }
        }
    }

    printf("\nPress Y to continue again");
    scanf("%c", &c);
    while(1)
    {
        if (c == 'y' || c == 'Y')
        {
            goto label5;
        }
    }
    
    

    return 0;
}












void draw()
{
    system("cls");
    int i, j, k;
    for (j = 0; j < width; j++)
    {
        for(i = 0; i < height; i++)
        {
            if (i == 0|| i == height - 1||j == 0|| j == width - 1)
            {
                printf("#");
            }
            else
            {
                if (i == x && j == y)
                {
                    printf("O");
                }
                else if (i == fruitX && j == fruitY)
                {
                    printf("F");
                }
                else
                {
                    int ch = 0;
                    for (k = 0; k < CountTail; k++)
                    {
                        if (i == tailX[k] && j == tailY[k])
                        {
                            printf("o");
                            ch = 1;
                        }
                    }
                    if(ch == 0)
                    {
                        printf(" ");
                    }
                    
                }
            }
        }
        printf("\n");
    }
    printf("SCORE = %d", score);

}



void setup()
{
    gameOver = 0;
    x = width / 2;
    y = height / 2;

    label1:
    fruitX = rand() % 20;
    if (fruitX == 0)
    {
        goto label1;
    }

    label2:
    fruitY = rand() % 20;
    if (fruitY == 0)
    {
        goto label2;
    }
    score = 0;

    return;
}


void input()
{
    if(kbhit())
    {
        switch(getch())
        {
            case '1':  // aswz
            flag = 1;
            break;
            case '2':  // aswz
            flag = 2;
            break;
            case '3':  // aswz
            flag = 3;
            break;
            case '4':  // aswz
            flag = 4;
            break;
            case 'x':
                gameOver = 1;
                break;
        }
    }

}



void makelogic()
{
    int i;
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (i = 1; i < CountTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }


    switch(flag)
    {
        case 1:
            x--;
            break;
        case 2:
            y++;
            break;
        case 3:
            y--;
            break;
        case 4:
            x++;
            break;
        default:                   // if anything else happens
            break;
    }

    if (x < 0 || x > width || y < 0 || y > height)
    {
        gameOver = 1;
    }

    for (i = 0; i < CountTail; i++)
    {
        if(x == tailX[i] && y == tailY[i])
        {
            gameOver = 1;
        }
    }



    if (x == fruitX && y == fruitY)
    {
        label3:
        fruitX = rand() % 20;
        if (fruitX == 0)
        {
            goto label3;
        }

        label4:
        fruitY = rand() % 20;
        if (fruitY == 0)
        {
            goto label4;
        }

        score += 10;
        CountTail++;
    }

    

}

/*  while(1)
    {
        if (kbhit())      // until we type a key it returns zero
        {
            ch = getch();
            printf("character = %c", ch);
            break;

        }
        

    }
*/

/* int a = rand() % 20;
    printf("%d", a);
    */