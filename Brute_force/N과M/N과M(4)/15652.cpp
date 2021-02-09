//15652번 [브루트 포스] <순서>
//자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
//1부터 N까지 자연수 중에서 M개를 고른 수열
//같은 수를 여러 번 골라도 된다.
//고른 수열은 비내림차순이어야 한다. (수열 A가 A1 ≤ A2 ≤ ... ≤ AK - 1 ≤ AK를 만족)
#include <iostream>	
using namespace std;
int ans[10];
void go(int index, int start, int n, int m);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;

	cin >> n >> m;

	go(0, 1, n, m);

	return 0;
}

void go(int index, int start, int n, int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << ans[i] << ' ';

		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++)
	{
		ans[index] = i;
		go(index + 1, i, n, m);

	}
}