#include <cstdio>
#include <windows.h>
#include "getWindowInfo.h"
struct _gameData
{
	char courseName;
	int score;
	int usetime;
};
int choosingUIBackground(_gameData data[],int numberOfCourses)
{
	for(int i=0;i<(getWindowSize.getWindowHeight()-100)/2;i++)
		printf("\n");
	for(int i=0;i<((getWindowSize.getWindowHeight() > 20)? 20 : getWindowSize.getWindowHeight());i++)
	{
		for(int j=0;j<getWindowSize.getWindowWidth() - 100;j++)
			printf(" ");
		printf("|");
		if(i==0||i==((getWindowSize.getWindowHeight() > 20)? 20 : getWindowSize.getWindowHeight())-1)
			for(int j=0;j<100;j++)
				printf("-");
		else
			for(int j=0;j<100;j++)
				printf(" ");
		printf("|\n");
	}
}
int main()
{
	_gameData data[100];
	int lastx,lasty;
	system("cls");
	printf("\033[?25l");
	while(1)
	{
		if(lastx!=getWindowSize.getWindowHeight())
		{
			system("cls");
			lastx=getWindowSize.getWindowHeight();
		}
		if(lasty!=getWindowSize.getWindowWidth())
		{
			system("cls");
			lasty=getWindowSize.getWindowWidth();
		}
		printf("\033[0;0H");
		printf("\033[?25l");
		choosingUIBackground(data,10);
	}
}

