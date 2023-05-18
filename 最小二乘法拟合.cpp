#include<bits/stdc++.h>
using namespace std;

double x[9]={1 ,3, 4, 5, 6, 7, 8, 9, 10};
double y[9]={10,5, 4, 2, 1, 1, 2, 3, 4 };

double f(int x,int i)// 最小二乘法，三次函数拟合 
{
	if(i==0) return 1;
	if(i==1) return x;
	if(i==2) return x*x;
	if(i==3) return x*x*x;
	return -1; 
}

double A[4][4];
double b[4];
double a[4];// 系数矩阵 


int main()
{
	// 矩阵初始化 
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<9;j++) b[i]+=f(x[j],i)*y[j];
	}
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<9;k++) A[i][j]+=f(x[k],i)*f(x[k],j);
		}
	}

	// 高斯消元法 
	
	int n=4; 
	// 1.消元 
	for(int k=0;k<n-1;k++)// 按列消元 
	{
		for(int i=k+1;i<n;i++)// i为当前的行
		{
			double t=A[i][k]/A[k][k];// t为倍数 
			for(int j=k;j<n;j++)// j为当前的列 
			{
				A[i][j]-=t*A[k][j];
			}
			b[i]-=t*b[k];// 更新常数项 
		} 
	}
	
	// 2. 回代求解
	for(int i=n-1;i>=0;i--)// 从最后一行往上回代 
	{
		for(int j=n-1;j>i;j--)
		{
			b[i]-=A[i][j]*a[j];
		}
		a[i]=b[i]/A[i][i];
	} 

	// 3.输出解 
	cout<<"拟合多项式的系数为："<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"a"<<i<<"="<<a[i]<<endl;
	}
} 
