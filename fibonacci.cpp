#include <iostream>
using namespace std;
int fib(int n) // 计算第n个斐波那契数
{
	if (n <= 2)
		return 1;
	return (fib(n - 1) + fib(n - 2));
}
int main()
{
	int n;
	cin >> n;
	for (size_t i = 1; i <= n; i++)
		cout << fib(i) << " ";
	cout << endl;
	system("pause");
	return 0;
}