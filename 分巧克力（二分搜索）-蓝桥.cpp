#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
// 蓝桥的数据量一般都是六位级别
const long maxn = 100005;
long a[maxn];
long b[maxn];
long n, k;
int go(int m)
{
		long cnt = 0;
		for (int i = 0; i < n; i++)
		{
            // 因为要规整，不能直接用面积除
			cnt += int(int(a[i] / m) * int(b[i] / m));
			if(cnt >= k)
			return 1;
		}
		return 0;
}
int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
	}
	long l = 0, r = maxn;
    // 注意l和r不能撞在一起！！！
	while(r > l + 1)
	{
		long m = l + (r - l) / 2;
		if(go(m) == 1)
			l = m;
		else
			r = m;	
	}
	cout << l;
	return 0;
}