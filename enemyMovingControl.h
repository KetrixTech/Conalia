#include <cstdio>
#include "mapControl.h"
int enemyMoving(int a[Height][Width],int x1,int x2,int y1,int y2)
{
	const int fx[]={1,-1,0,0},fy[]={0,0,-1,1};
	int head=1,tail=1;
	int pos[3000000][5];
	bool zg[10000][10000];
	int n,m;
//	scanf("%d%d",&n,&m);
	n=Height;
	m=Width;
	//printf("%d %d\n",n,m);
	/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}*/
	//scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	pos[head][1]=x1;
	pos[head][2]=y1;
	while(head<=tail)
	{
		for(int i=0;i<4;i++)
		{
			if(pos[head][1]==0&&i==0)
				continue;
			if(pos[head][2]==0&&i==2)
				continue;
			if(pos[head][1]==n-1&&i==1)
				continue;
			if(pos[head][2]==m-1&&i==3)
				continue;
			tail++;
			pos[tail][1]=pos[head][1]+fx[i];
			pos[tail][2]=pos[head][2]+fy[i];
			if(zg[pos[tail][1]][pos[tail][2]])
			{
				tail--;
				continue;
			}
			if(a[pos[tail][1]][pos[tail][2]]==1)
			{
				tail--;
				continue;
			}
			zg[pos[tail][1]][pos[tail][2]]=true;
			pos[tail][3]=pos[head][3]+1;
			if(pos[tail][3]=1)
				pos[tail][4]=i;
			else
				pos[tail][4]=pos[head][4];
			if(pos[tail][1]==x2&&pos[tail][2]==y2)
			{
//				printf("%d\n",pos[tail][3]);
//				if(pos[tail][4]==0)
//					printf("shang");
//				if(pos[tail][4]==1)
//					printf("xia");
//				if(pos[tail][4]==2)
//					printf("zuo");
//				if(pos[tail][4]==3)
//					printf("you");
				return pos[tail][4];
			}
		}
		head++;
	}
	return -1;
}

