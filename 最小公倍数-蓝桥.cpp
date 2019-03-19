#include<iostream>
#include<algorithm>
using namespace std;
int abc[3];
int main()
{
	for(int i = 0;i < 3;i++)
		cin >> abc[i];
	sort(abc, abc + 3);
	for(int j = abc[0];j <= abc[0] * abc[1] * abc[2];j++)
	{
		if(j % abc[0] == 0 && j % abc[1] == 0 && j % abc[2] == 0)
		{
			cout << j;
			break;
		}
	}
	return 0;
}