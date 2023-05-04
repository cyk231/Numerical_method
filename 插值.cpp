#include<bits/stdc++.h>
using namespace std;

#define n 6
double x[n]={0.0, 0.1, 0.195, 0.3, 0.401, 0.5};// 表格中的原始数据 
double y[n]={0.39894, 0.39695, 0.39142, 0.38138, 0.36812, 0.35206};// 表格中的原始数据 

double linear(double x_input)// 分段线性插值 
{
	int i;// 在区间x[i]与x[i+1]中 
	for(i=n-1;i>0;i--)
	{
		if(x_input>x[i]) break;
	}
	double k=(y[i+1]-y[i])/(x[i+1]-x[i]);// 直线斜率
	double y_output=k*(x_input-x[i])+y[i];// 点差法 
	return y_output;
}

double quadratic(double x_input)// 分段二次插值 
{
	int i;// 为方便起见，使用x[i-1],x[i],x[i+1]三点 
	for(i=n-1;i>0;i--)
	{
		if(x_input>x[i]) break;
	} 
	double sum1=0;
	for(int p=i-1;p<=i+1;p++)// 外层循环累加 
	{
		double sum2=1;
		for(int q=i-1;q<=i+1;q++)// 内层循环累乘 
		{
			if(p==q) continue;
			sum2=sum2*(x_input-x[q])/(x[p]-x[q]);
		}
		sum1=sum1+y[p]*sum2;
	} 
	return sum1;
}

double lagrange(double x_input)// 全区间拉格朗日插值
{
	double sum1=0;
	for(int i=0;i<n;i++)// 外层循环累加 
	{
		double sum2=1;
		for(int j=0;j<n;j++)// 内层循环累乘 
		{
			if(i==j) continue;
			sum2=sum2*(x_input-x[j])/(x[i]-x[j]);
		}
		sum1=sum1+y[i]*sum2;
	} 
	return sum1;// 用书本P82页公式, 两层循环 
}

int main()
{
	// 1. 分段线性插值
	cout<<"使用分段线性插值:"<<endl;
	cout<<"f(0.15)= "<<linear(0.15)<<endl; 
	cout<<"f(0.31)= "<<linear(0.31)<<endl; 
	cout<<"f(0.47)= "<<linear(0.47)<<endl; 
	
	// 2. 分段二次插值
	cout<<endl;
	cout<<"使用分段二次插值:"<<endl;
	cout<<"f(0.15)= "<<quadratic(0.15)<<endl; 
	cout<<"f(0.31)= "<<quadratic(0.31)<<endl; 
	cout<<"f(0.47)= "<<quadratic(0.47)<<endl; 
	
	// 3. 全区间拉格朗日插值
	cout<<endl;
	cout<<"使用全区间拉格朗日插值:"<<endl;
	cout<<"f(0.15)= "<<lagrange(0.15)<<endl; 
	cout<<"f(0.31)= "<<lagrange(0.31)<<endl; 
	cout<<"f(0.47)= "<<lagrange(0.47)<<endl; 
}
