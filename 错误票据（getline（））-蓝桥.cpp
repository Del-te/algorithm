#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
int a[101];
int main()
{
	string line;
	int n;
	int index = 0;
	cin >> n;
	for(int i = 0; i <= n; i++)
	{	
		getline(cin, line);
		stringstream ss(line);
		while(ss >> a[index]) index++;
	}
	sort(a, a + index);
	for(int j = 0; j < index - 1; j++)
	{
		if(a[j] + 1 != a[j + 1])
			if(a[j] + 2 == a[j + 1])
				cout << a[j] + 1 << ' ';
	} 
	for(int k = 0; k < index - 1; k++)
	{
		if(a[k] + 1 != a[k + 1])
			if(a[k] == a[k + 1])
				cout << a[k];
	} 
	return 0;
}