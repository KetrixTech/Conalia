#include <stdio.h>
#include<string.h>
#include<conio.h>
bool validPassword(int i,char passwd[])
{
	if(i==strlen(passwd))
		return true;
	while(1)
	{
		if(_kbhit())
		{
			if(_getch()==passwd[i])
				return validPassword(i+1,passwd);
			else
				return false;
		}
	}
}
bool checkPasswdUntilCorrect(char passwd[])
{
	while(1)
		if(validPassword(0,passwd))
			return true;
}

