#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<iostream>
#include<math.h>
using namespace std;
float m,c;
void myline(int x1,int y1,int x2,int y2);
main()
{
	int x1,y1,x2,y2;
   	int gd = DETECT, gm, x, y, color, angle = 0;
   	struct arccoordstype a, b;
	cout<<"Enter x1,y1,x2,y2\n";
	cin>>x1>>y1>>x2>>y2;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	circle(x1,y1,10);
	circle(x2,y2,10);
	printf("%d   %d        %d  %d\n\n",x1,y1,x2,y2);
	if(x1==x2)                        //vertical line; Slope is inifinty;
	{
		if(y1>y2)
		{
			swap(x1,x2);
			swap(y1,y2);
		}	
		for(int i=y1;i<=y2;i++)
		{
			putpixel(x1,i,WHITE);
			delay(20);
		}
		getch();
		exit(0);
	}
	else
	{	
		//Calculate Slope and Y-intercept
		m=(float)(y2-y1)/(x2-x1);
		c=y1-m*x1;
		cout<<"\n Slope="<<m<<" y-intercept "<<c;
		myline(x1,y1,x2,y2);	   //call to function that draws line
	}
   	getch();
   	closegraph();
}
void myline(int x1,int y1,int x2,int y2)
{
	cout<<"\n\n\nx   y\n";
	float b;
	int k;
	if(x1>x2)
	{
		swap(x1,x2);
		swap(y1,y2);
	}
	for(int i=x1;i<=x2;i++)
	{
		b=m*i+c;
		k=ceil(b);
		cout<<i<<"   "<<b<<"   "<<k<<endl;
		putpixel(i,k,WHITE);       
		delay(20);
	}
	
	delay(5000);
	
	cout<<"\n\n\n\n\n";
	if(y1>y2)
	{
		swap(y1,y2);
		swap(x1,x2);
	}
	for(int i=y1;i<=y2;i++)
	{
		float b=(i-c)/m;
		int k=ceil(b);
		cout<<i<<"   "<<b<<"   "<<k<<endl;
		putpixel(k,i,WHITE);
		delay(20);
	}
}
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
