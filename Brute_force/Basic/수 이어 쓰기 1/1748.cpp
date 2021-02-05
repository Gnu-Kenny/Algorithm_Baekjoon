//1748번 [브루트 포스]

#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	long long ans = 0;
	for (int start = 1, len = 1; start <= N; start *= 10, len++)
	{
		int end = start * 10 - 1;
		if (end > N)
		{
			end = N;
		}
		ans += (long long)(end - start+1) * len;
	}
	cout << ans << '\n';
	return 0;
}
