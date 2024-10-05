#include<iostream>
#include<conio.h>
using namespace std;
bool gameover;
const int width=25;
const int height=20;
int x,y,fx,fy,point;
enum eDirecton {STOP=0,LEFT,RIGHT,UP,DOWN};
eDirecton d;
void start()
{
    gameover=false;
    d = STOP;
    x=width/2;
    y=height/2;
    fx=rand()%width;
    fy=rand()%height;
    point=0;
}
void infras()
{
    system("cls");
    cout<<"A = Snake"<<endl;
    //cout<<"mara = Point"<<endl;

    for(int i=0;i<width+2;i++)
    {
        cout<<"*";
    }
    cout<<endl;
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
            {
                cout<<"*";
            }
            if(i==y && j==x)
            {
                cout<<"A";
            }
            else if(i==fy && j==fx)
            {
                cout<<"0";
            }
            else
            {
                cout<<" ";
            }
            if(j==width-1)
            {
                cout<<"*";
            }
        }
        cout<<endl;
    }
    for(int i=0;i<width+2;i++)
    {
        cout<<"*";
    }
    cout<<endl;
    cout<<"point : "<<point<<endl;
}
void inputt()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a':
            d=LEFT;
            break;
            case 'd':
            d=RIGHT;
            break;
            case 'w':
            d=UP;
            break;
            case 's':
            d=DOWN;
            break;
            case 'q':
            gameover=true;
            break;
        }
    }
}
void game_logic()
{
    switch(d)
        {
            case LEFT:
                x--;
            break;
            case RIGHT:
                x++;
            break;
            case UP:
                y--;
            break;
            case DOWN:
                y++;
            break;
            default :
            break;
        }
        if(x>width || x<0 || y>height|| y<0)
        {
            gameover= true;
        }
        if(x==fx && y==fy)
        {
            point = point + 10;
            fx=rand()%width;
            fy=rand()%height;
        }
}
int main()
{
    start();
    while(!gameover)
    {
        infras();
        inputt();
        game_logic();
    }
}
