#include<bits/stdc++.h>
using namespace std;
double f(double x)// 迭代函数f(x) 
{
	return (2-exp(x))/10;
}
double iteration(double x)// 迭代法 
{
	while(abs(f(x)-x)>=0.0005)
	{
		x=f(x);
	}
	return f(x);
}
int main()
{
	double x=0;
	double ans=iteration(x);
	cout<<ans<<endl;
}
