#include<iostream>
#include<cstring>
using namespace std;
char a[1000], b[1000];
int main()
{
	int cnt = 0;
	scanf("%s", a);
	scanf("%s", b);
	for(int i = 0; i < strlen(a); i++)
	{
		if(a[i] != b[i])
			if(a[i] == '*')
				{
					a[i] = 'o';
					if(a[i+1] == '*')
					{
						a[i+1] = 'o';
						cnt++;
					}
					else 
					{
						a[i+1] = '*';
						cnt++;
					}
				} 
				else
				{
					a[i] = '*';
					if(a[i+1] == '*')
					{
						a[i+1] = 'o';
						cnt++;
					}
					else 
					{
						a[i+1] = '*';
						cnt++;
					}
				}
	}
	cout << cnt;
	return 0;
}