#include<bits/stdc++.h>
using namespace std;

#define n 6

double A[n][n]={ {4,-1,0,-1,0,0}, {-1,4,-1,0,-1,0}, {0,-1,4,-1,0,-1}, {-1,0,-1,4,-1,0}, {0,-1,0,-1,4,-1}, {0,0,-1,0,-1,4} };
double b[n]={0,5,-2,5,-2,6};

double B[n][n];
double f[n];

double x[n];// 迭代前的结果：X(k)
double x_next[n];// 迭代后的结果：X(k+1)


void jacobi()
{
	for(int i=0;i<n;i++)// 初始化用于迭代的矩阵： B[n][n]和f[n]
	{
		double m=A[i][i];
		for(int j=0;j<n;j++) 
		{
			if(j==i) B[i][j]=0;
			else 
			{
				B[i][j]=-A[i][j]/m;
			}
		}
		f[i]=b[i]/m;
		x[i]=0;
	}
	
	int iteration=0;// 迭代次数 
	while(true)
	{
		iteration++;
		for(int i=0;i<n;i++)
		{
			double sum=0;
			for(int j=0;j<n;j++)
			{
				sum+=B[i][j]*x[j];
			}
			x_next[i]=sum+f[i];// 迭代公式：X(k+1)=B*X(k)+f 
		}
		
		double error=0;
		for(int i=0;i<n;i++)
		{
			error+=(x_next[i]-x[i])*(x_next[i]-x[i]);
		}
		error=sqrt(error);
		if(error<=0.001) break;// 判断相对误差 
		else 
		{
			for(int i=0;i<n;i++) x[i]=x_next[i];
		}
	}
	
	cout<<"迭代次数为："<<iteration<<endl<<endl; 
	cout<<"利用雅可比迭代法，方程组的解为："<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"x"<<i+1<<"="<<x_next[i]<<endl;
	}
}

int main()
{
	jacobi();
}
