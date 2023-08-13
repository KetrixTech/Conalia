#include<iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include<unistd.h>
#define Height 5 //迷宫的高度，必须为奇数
#define Width 5 //迷宫的宽度，必须为奇数
#define Wall 1
#define Road 0
#define Start 2
#define End 3
#define Esc 5
#define Up 1
#define Down 2
#define Left 3
#define Right 4
using namespace std;
const int Fx[4]={-1,1,0,0},Fy[10]={0,0,-1,1};
bool dt[101][101];
void sy(int a)
{
	int f=2;
	srand(time(0));
	if(a!=114514)return;
	for(int i=1;i<=50;i++)for(int j=1;j<=50;j++)dt[i][j]=rand()%2;
	for(int i=0;i<=51;i++)
	{
		for(int j=0;j<=51;j++)
		{
			if(f&&rand()%2&&(j==0||i==0||j==51||i==51))
			{
				cout<<"0 ";
				f--;
				if(f==0)f=rand()%2;
			}
			else if(dt[i][j]==0)cout<<"1 ";
			else cout<<"  ";
		}
		cout<<"\n";
	}
	
}
void tldyx(int a)
{
	if(a!=114514)return;
	int x=5,y=6,dx,dy,p,win,pwin;
	srand(time(0));
	win=(rand()%18)+1;
	dx=(rand()%18)+1;
	dy=(rand()%8)+1;
	system("cls");
	printf("\033[?25l");
	system("color 4");
	b:
		printf("\033[0;0H");
		if(dx<x)dx++;
		if(dx>x)dx--;
		if(dy<y)dy++;
		if(dy>y)dy--;
		int x1=x,y1=y,dx1=dx,dy1=dy;
		if(y==win&&x==30)
		{
			system("cls");
			cout<<"WIN";
			return;
		}	
		if(x==30)x=2;
		if(x==1)x=29;
		if(y==20)y=2;
		if(y==1)y=19;
//		if(y1==5)x=x1;
		if(dx>=30)dx=2;
		if(dx<=1)dx=29;
		if(dy>=20)dy=2;
		if(dy<=1)dy=19;
		if(dx==x&&dy==y)
		{
			system("cls");
			cout<<"game over";
			sleep(1);
			return;
		}
		int winc=0;
		if(y>win)winc=y-win;
		else if(y==win)winc=y;
		else winc=win-y;
		for(int i=1;i<=20;i++)
		{
			for(int j=1;j<=30;j++)
			{
				if(30-x<2&&winc<2&&i==win&&j==30)printf("门");
				else if(j==1||i==1||j==30||i==20)printf("墙");
				else if(i==dy&&dx==j)cout<<"杜";
				else if(i==y&&x==j)cout<<"帅";
				else printf("  ");
			}
			cout<<"\n";
		}
		a:
			if(_kbhit())
			{
				switch(_getch())
				{
					case'w':
						y--;
						goto b;
					case's':
						y++;
						goto b;
					case'a':
						x--;
						goto b;
					case'd':
						x++;
						goto b;
				}
			}
			goto a;
}
int map[Height+2][Width+2];
void gotoxy(int x,int y) { //????
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}
void hidden() { //????
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible=0;//?1???,?0???
    SetConsoleCursorInfo(hOut,&cci);
}
void create(int x,int y) { //?????
    int c[4][2]= {0,1,1,0,0,-1,-1,0}; //????
    int i,j,t;
//?????
    for(i=0; i<4; i++) {
        j=rand()%4;
        t=c[i][0];
        c[i][0]=c[j][0];
        c[j][0]=t;
        t=c[i][1];
        c[i][1]=c[j][1];
        c[j][1]=t;
    }
    map[x][y]=Road;
    for(i=0; i<4; i++)
        if(map[x+2*c[i][0]][y+2*c[i][1]]==Wall) {
            map[x+c[i][0]][y+c[i][1]]=Road;
            create(x+2*c[i][0],y+2*c[i][1]);
        }
}
int get_key() { //????
    char c;
    while(c=getch()) {
        if(c==27) return Esc; //Esc
        if(c!=-32)continue;
        c=getch();
        if(c==72) return Up; //?
        if(c==80) return Down; //?
        if(c==75) return Left; //?
        if(c==77) return Right; //?
    }
    return 0;
}
void paint(int x,int y) { //???
    gotoxy(2*y-2,x-1);
    switch(map[x][y]) {
        case Start:
            printf("1 ");
            break; //???
        case End:
            printf("0 ");
            break; //???
        case Wall:
            printf("1 ");
            break; //??
        case Road:
            printf("0 ");
            break; //??
    }
}
void game() {
    int x=2,y=1; //??????,???????
    int c; //??????
    while(1) {
        gotoxy(2*y-2,x-1);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
        printf("帅"); //????????
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);

        if(map[x][y]==End) { //????????
            gotoxy(30,24);
            printf("????,??????");
            getch();
            break;
        }
        c=get_key();
        if(c==Esc) {
            gotoxy(0,24);
            break;
        }
        switch(c) {
            case Up: //???
                if(map[x-1][y]!=Wall) {
                    paint(x,y);
                    x--;
                }
                break;
            case Down: //???
                if(map[x+1][y]!=Wall) {
                    paint(x,y);
                    x++;
                }
                break;
            case Left: //???
                if(map[x][y-1]!=Wall) {
                    paint(x,y);
                    y--;
                }
                break;
            case Right: //???
                if(map[x][y+1]!=Wall) {
                    paint(x,y);
                    y++;
                }
                break;
        }
    }
}
void sjmg() {
	//system("color 4A"); 
    int i,j;
    srand((unsigned)time(NULL)); //???????
    hidden(); //????
    for(i=0; i<=Height+1; i++)
        for(j=0; j<=Width+1; j++)
            if(i==0||i==Height+1||j==0||j==Width+1) //?????
                map[i][j]=Road;
            else map[i][j]=Wall;
    create(2*(rand()%(Height/2)+1),2*(rand()%(Width/2)+1)); //????????????,????????
    for(i=0; i<=Height+1; i++) { //????
        map[i][0]=Wall;
        map[i][Width+1]=Wall;
    }
    for(j=0; j<=Width+1; j++) { //????
        map[0][j]=Wall;
        map[Height+1][j]=Wall;
    }
    map[2][1]=Start; //????
    map[Height-1][Width]=End; //????
    for(i=1; i<=Height; i++)
        for(j=1; j<=Width; j++) //????
            paint(i,j);
    game(); //????
    getch();
    return;
}
