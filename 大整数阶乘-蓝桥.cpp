#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 100000 + 5;
int A[maxn];
int n;
int main()
{
	memset(A, 0, sizeof(A));
	scanf("%d", &n);
	A[0] = 1;
	int c = 0, s = 0;
	for(int i = 2;i <= n;i++)
	{
		for(int j = 0;j < 100000;j++)
		{
			s = i * A[j] + c;
			A[j] = s % 10; 
			c = s / 10;
		}
	} 
	for(int i = 100000;i >= 0;i--)
	{
		if(A[i] != 0)
		{
			for(int j = i;j >= 0;j--)
				printf("%d", A[j]);
			break;
		}
    }
	return 0;
}