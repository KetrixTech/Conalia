#include <bits/stdc++.h>
#include<windows.h>
using namespace std;
void jiazaizhong()
{
	string a[6]={"加","载","中",".",".","."};
	for(int i=1;i<=3;i++)
    {
	    system("cls");
	    cout<<"\n\n\n\n\n\n\n\n\n\n                                   ";
	    for(int j=0;j<=2;j++)cout<<a[j];
	    for(int j=3;j<6;j++)
        {
            Sleep(500);
            cout<<a[j];
        }
        Sleep(500);
    }
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n                                    加载成功\n\n\n\n\n\n\n\n\n\n                                    ";
}
