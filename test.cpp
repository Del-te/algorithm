#include <iostream>
#include <cstring>

using namespace std;

int n, k, a[110000], b[110000];
bool ok(int x)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt += (int(a[i] / x) * int(b[i] / x));
		if (cnt >= k)
			return true;
	}
	return false;
}
int main()
{

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i];
	int l = 0;
	int r = 100004;
	while (r - l > 1)
	{
		int m = (l + r) >> 1;
		if (ok(m))
			l = m;
		else
			r = m;
	}
	cout << l << endl;

	return 0;
}