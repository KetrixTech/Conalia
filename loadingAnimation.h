#include <bits/stdc++.h>
#include<windows.h>
using namespace std;
void jiazaizhong()
{
	string a[6]={"加","载","中",".",".","."};
	for(int i=1;i<=3;i++)
    {
	    system("cls");
	    printf("\n\n\n\n\n\n\n\n\n\n                                   ");
	    for(int j=0;j<=2;j++)printf("%s",a[j].c_str());
	    for(int j=3;j<6;j++)
        {
            Sleep(500);
            printf("%s",a[j].c_str());
        }
        Sleep(500);
    }
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n                                    加载成功\n\n\n\n\n\n\n\n\n\n                                    ");
}
