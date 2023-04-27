#include<bits/stdc++.h>
using namespace std;
double f(double x)// f(x) 
{
	return exp(x)+10*x-2;
}
double binary(double a,double b)// [a,b]区间上的二分法 
{
	if(f(a)==0) return a;
	if(f(b)==0) return b; 
	while((b-a)/2>=0.0005)
	{
		double mid=(a+b)/2;
		if(f(mid)==0) return mid;
		else if(f(a)*f(mid)>0) a=mid;
		else  b=mid;
	}
	return (a+b)/2;
}
int main()
{
	double a=0;
	double b=1;
	double ans=binary(a,b);
	cout<<ans<<endl;
}
