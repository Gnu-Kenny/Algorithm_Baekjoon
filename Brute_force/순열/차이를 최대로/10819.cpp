//10819번 [브루트포스] <순열>

#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int sequence[8];
int calculate(int* sequence, int n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}

	int ans=0;
	do {
		int temp = calculate(sequence,n);
		ans = max(ans, temp);
	} while (next_permutation(sequence, sequence + n));

	cout << ans;
	return 0;
}

int calculate(int* sequence,int n)
{
	for (int i = 0; i < n; i++)
	{
		
	}
}