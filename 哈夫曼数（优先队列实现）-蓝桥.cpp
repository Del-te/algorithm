#include<iostream>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > pq; 
int main()
{
	int n, x;
	int ans = 0;
	cin >> n;
	while(n--)
	{
		cin >> x;
		pq.push(x);
	}
	while(true)
	{
		if(pq.size() == 1) 
			break;
		int t = 0;
		for(int i = 0;i < 2;i++)
		{
			t += pq.top();
			pq.pop();
		}
		ans += t;
		pq.push(t);
	}
	cout << ans;
	return 0;
}