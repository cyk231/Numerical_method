#include<bits/stdc++.h>
using namespace std;
//#define n 4
#define n 6 
//double a[n][n]={{1.1348,3.8326,1.1651,3.4017},{0.5301,1.7875,2.5330,1.5435},{3.4129,4.9317,8.7643,1.3142},{1.2371,4.9998,10.6721,0.0147}};
//double b[n]={9.5342,6.3941,18.4231,16.9237};
double a[n][n]={ {4,-1,0,-1,0,0}, {-1,4,-1,0,-1,0}, {0,-1,4,-1,0,-1}, {-1,0,-1,4,-1,0}, {0,-1,0,-1,4,-1}, {0,0,-1,0,-1,4} };
double b[n]={0,5,-2,5,-2,6};
double x[n];// x数组用于存放结果 

void gauss1()// 顺序高斯消元法 
{
	// 1.消元 
	for(int k=0;k<n-1;k++)// 按列消元 
	{
		for(int i=k+1;i<n;i++)// i为当前的行
		{
			double t=a[i][k]/a[k][k];// t为倍数 
			for(int j=k;j<n;j++)// j为当前的列 
			{
				a[i][j]-=t*a[k][j];
			}
			b[i]-=t*b[k];// 更新常数项 
		} 
	}
	
	// 2. 回代求解
	for(int i=n-1;i>=0;i--)// 从最后一行往上回代 
	{
		for(int j=n-1;j>i;j--)
		{
			b[i]-=a[i][j]*x[j];
		}
		x[i]=b[i]/a[i][i];
	} 

	// 3.输出解 
	cout<<"利用顺序高斯消元法，方程组的解为："<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"x"<<i+1<<"="<<x[i]<<endl;
	}
}

void gauss2()// 列主元高斯消元法
{
	// 1. 根据绝对值最大找到列主元
	for(int k=0;k<n-1;k++)// 外层循环按列遍历 
	{
		double maxVal=fabs(a[k][k]);
		int maxIndex=k;
		for(int i=k+1;i<n;i++)// 对行遍历，找列主元 
		{
			if(fabs(a[i][k])>maxVal) 
			{
				maxVal=a[i][k];
				maxIndex=i;
			}
		}
		if(maxIndex!=k)// 如果主元不在对角线上，则交换行
		{
			for(int j=k;j<n;j++) swap(a[maxIndex][j],a[k][j]);
			swap(b[k],b[maxIndex]);
		}
		
		// 2.消元（同顺序高斯消元） 
		for(int i=k+1;i<n;i++)
		{
			double t=a[i][k]/a[k][k];
			for(int j=k;j<n;j++)
			{
				a[i][j]-=t*a[k][j];
			}
			b[i]-=t*b[k];
		} 
	}
	
	// 3. 回代求解
	for(int i=n-1;i>=0;i--)// 从最后一行往上回代 
	{
		for(int j=n-1;j>i;j--)
		{
			b[i]-=a[i][j]*x[j];
		}
		x[i]=b[i]/a[i][i];
	} 

	// 4.输出解 
	cout<<"利用列主元高斯消元法，方程组的解为："<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"x"<<i+1<<"="<<x[i]<<endl;
	}
} 
int main()
{
	gauss1();
//	gauss2(); 
} 
