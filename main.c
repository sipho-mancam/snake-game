#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "ESD.h"
#include <time.h>

int x[500]={0 , } ,y[500]={0, };

int main()
{

    int ers_x, ers_y;
    int dir;
    char key;
    int xrPos, yrPos;
    int s_length;
    int score1=0;

    int i, j;

    for(int k=0;k<4; k++)y[k]=4;

    x[0]=3;
    x[1]=2;
    x[2]=1;
    x[3]=1;
    x[4]=1;

    x[1] = x[0]-1;
    y[1] = y[0];

    ers_x = 0;
    ers_y = 0;
    dir = 3;

    box(0,0,79,20);

    gotoxy(5, 23);
    printf("Score : %d", score1);
    srand(time(NULL));

    xrPos = 5+rand()%70;
    yrPos = 3+rand()%15;

    //generate random numbers between 1 and 79 for x and 1 and 19 for y
    gotoxy(xrPos, yrPos);
    printf("%c",254);

    do
    {
        // keys management
        if(kbhit())
        {
            key=getch();
            if(key==-32)key=getch();

            switch(key)
            {
            case 72:
                dir=-1;
                break;
            case 80:
                dir=1;
                break;
            case 75:
                dir=2;
                break;
            case 77:
                dir=3;
                break;
            }
        }
        //control snake directions automated
        switch(dir)
        {
        case -1:
            y[0]--;
            break;
        case 1:
            y[0]++;
            break;
        case 2:
            x[0]--;
            break;
        case 3:
            x[0]++;
            break;
        }

        //keep rat on the screen for every iteration
        gotoxy(xrPos, yrPos);
        printf("%c",254);

        //count snake segments
        for(i=0;x[i]!=0;++i);

       // s_length = i;
        //print worm segments
        for(j=0;j<i;++j)
        {
            gotoxy(x[j],y[j]);
            printf("%c",223);
        }

        // check if the snake isn't eating itself,
//        for(int k=1; k<3; k++)
//        {
//            if(x[0]==x[k] && y[0]==y[k])
//            {
////                    clrscr();
//                gotoxy(5,5);
//                printf("Game Over!!!\n\n\n");
//                break;
//            }
//        }
        // make snake bigger after eating a rat
        if(x[0]==xrPos && y[0]==yrPos)
        {
            int k;
            while(x[k]!=0)
            {
                if(x[k+1]==0)
                {
                    i=k;
                }
                ++k;
            }
            s_length = i;
//
            x[s_length+1]=1;
            y[s_length+1]=4;
            gotoxy(5,23);
            printf("Score : %d", (s_length-1)*5);
            gotoxy(xrPos, yrPos);
            printf("%c",254);
            k=0;
        }

            //shift the position
            for(j=i;j>=1;--j)
            {
                //give the last coordinate to ers
                if(j==i)
                {
                    ers_x = x[j-1];
                    ers_y = y[j-1];
                }
                else //shift the positions
                {
                    x[j]=x[j-1]; // assign one position higher
                    y[j]=y[j-1];
                }
             }

              gotoxy(ers_x,ers_y);
              printf(" ");
              usleep(50000);

              //wall penetration
              if(x[0]>=77&&dir==3)x[0]=2;
              else if(x[0]<=1&&dir==2)x[0]= 77;
              if(y[0]<=1&&dir==-1)y[0]=18;
              else if(y[0]>=19&&dir == 1)y[0]=1;

              //print new rat when old one is eaten
              if(x[0]==xrPos&&y[0]==yrPos)
              {
                   //generate random numbers between 5 and 77 for x and 2 and 19 for y
                   //create the rat
                    xrPos = 5+rand()%70;
                    yrPos = 3+rand()%15;
                    gotoxy(xrPos, yrPos);
                    printf("%c",254);
//                    x[i] = x[i-1]+1;
//                    y[i] = y[i-1]+1;
              }



    }while(1);

    return 0;
}
