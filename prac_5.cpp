#include<iostream>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
using namespace std;
void Move(int j, int h, int &x, int &y)
{
	if(j==1)
	y-=h;
	else if (j==2)
	x+=h;
	else if(j==3)
	y+=h;
	else if(j==4)
	x-=h;
	lineto(x,y);
}
void hilbert(int r, int d, int l, int u ,int i, int h, int &x, int &y)
{
	if(i>0)
	{
		i--;
	hilbert(d,r,u,l,i,h,x,y);
	Move(r,h,x,y);
	hilbert(r,d,l,u,i,h,x,y);
	Move(d,h,x,y);
	hilbert(r,d,l,u,i,h,x,y);
	Move(l,h,x,y);
	hilbert(u,l,d,r,i,h,x,y);
	}
}


int main()
{
	int n,x1,y1;
	int x0=50,y0=150,x,y,h=10,r=2,d=3,l=4,u=1;
	cout<<"give the vallue of n:";
	cin>>n;
	x=x0;
	y=y0;
	int gm,gd=DETECT;
	initgrph(&gd,&gm,NULL);
	Move(x,y);	
	hilbert(r,d,l,u,n,h,x,y);
	delay(10000);
	closegraph();
	return 0;
		
}
