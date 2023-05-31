// 常微分方程的数值解法

 
#include<bits/stdc++.h>
using namespace std;

#define h 0.1

double x[10];
double y[10];
double res[10];

double f(double x,double y)// f(x,y), x定义域为[0，1] 
{
	return 2.0/3*x/(y*y);
}

double g(double x)
{
	return pow((1+x*x), 3/2.0);
}

void Euler()// 欧拉方法, y_i+1=y_i+h*f(x_i,y_i)
{
	for(int i=0;i<10;i++)
	{
		y[i+1]=y[i]+h*f(x[i],y[i]); 
	} 
	
	cout<<"使用欧拉方法："<<endl;
	for(int i=0;i<10;i++) cout<<fixed<<setprecision(5)<<y[i]<<"   ";
	cout<<endl;
} 

void EulerPro()// 改进欧拉方法, 书 P159页, 公式(6.11)
{
	for(int i=0;i<10;i++)
	{
		y[i+1]=y[i]+h/2*(f(x[i],y[i])+f(x[i+1],y[i]+h*f(x[i],y[i])));
	} 
	cout<<"使用改进欧拉方法："<<endl;
	for(int i=0;i<10;i++) cout<<fixed<<setprecision(5)<<y[i]<<"   ";
	cout<<endl;
}

void RK()// 经典RK法，书 P163页, 公式(6.21) 
{
	for(int i=0;i<10;i++)
	{
		double K1=f(x[i],y[i]);
		double K2=f(x[i]+h/2,y[i]+h/2*K1);
		double K3=f(x[i]+h/2,y[i]+h/2*K2);
		double K4=f(x[i]+h,y[i]+h*K3);
		y[i+1]=y[i]+h/6*(K1+2*K2+2*K3+K4);
	}
	
	cout<<"使用经典R-K法："<<endl;
	for(int i=0;i<10;i++) cout<<fixed<<setprecision(5)<<y[i]<<"   ";
	cout<<endl;
} 

double evaluate()
{
	double error=0;
	for(int i=0;i<10;i++)
	{
		error=error+(res[i]-y[i])*(res[i]-y[i]);
	}
	error=error/10; 
	cout<<"均方误差为"<<error<<endl<<endl;
}

int main()
{
	y[0]=1;
	for(int i=0;i<10;i++) res[i]=g(x[i]);
	
	for(int i=0;i<10;i++)
	{
		x[i]=i*h;
	}
	
	// 欧拉方法 
	Euler();
	evaluate();
	
	// 改进欧拉方法 
	EulerPro();
	evaluate();
	
	// 经典R-K法 
	RK();
	evaluate(); 
	
}
