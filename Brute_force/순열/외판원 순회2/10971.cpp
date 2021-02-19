//10971번 [브루트 포스] <순열>
#include <iostream>
#include <algorithm>
using namespace std;
long long metrix[10][10];
int temp[10];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		temp[i] = i;
		for (int j = 0; j < n; j++)
		{
			cin >> metrix[i][j];
		}
	}
	int ans = 5000000;
	do
	{
		bool ok = true;
		int sum = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (metrix[temp[i]][temp[i + 1]] == 0) ok = false;
			else
				sum += metrix[temp[i]][temp[i + 1]];	
		}
		if (ok && metrix[temp[n - 1]][temp[0]] != 0) 
		{
			sum += metrix[temp[n - 1]][temp[0]];
			ans = min(ans, sum);
		}
	} while (next_permutation(temp, temp + n));
	
	cout << ans;
	return 0;
}