// stringstream巨慢，别用！
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int ans = 0;
int list[9] = {1,2,3,4,5,6,7,8,9};
long div_(int l, int r)
{ 
	long result = 0;
	for(int i = l;i < r;i++)
	{
			result += list[l++];
			result *= 10;
	}
	result /= 10;
	return result;
}
int go(int n){
	long a, b, c;
	for(int num1 = 1;num1 < 9;num1++)
	{
		for(int num2 = num1 + 1;num2 < 9;num2++)
		{
			a = div_(0, num1);
			b = div_(num1, num2);
			c = div_(num2, 9);
			if(n == a + b / c && b % c == 0)
			{
				ans++;
//				cout << ans << endl;
//				cout << a << ' ' << b << ' ' << c << endl;
			}
		}	
	}
	return 0;
}
int main(){
	long n;
	scanf("%ld", &n);
	do{
		go(n);
	}while(next_permutation(list, list + 9));
	cout << ans;
	return 0;
} 