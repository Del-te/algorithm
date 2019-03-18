#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int maxn = 105;
int a[maxn];
int b[maxn];
int c[maxn];
int s = 0, r = 0;
int main()
{
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	string stra, strb;
	cin >> stra >> strb;
	for(int i = 0, j = stra.size() - 1;j >= 0;i++, j--)
	{	
		a[i] = stra[j] - 48;
	}
	for(int i = 0, j = strb.size() - 1;j >= 0;i++, j--)
	{
		b[i] = strb[j] - 48;
	}

	for(int i = 0;i < 100;i++)
	{
		s = a[i] + b[i] + r;
		r = s / 10;
		c[i] = s % 10; 
	}
	
	for(int i = 100;i >= 0;i--)
	{
		if(c[i] != 0)
		{
			for(int j = i;j >= 0;j--)
				printf("%d", c[j]);
			break;
		}
	}
	return 0;
}