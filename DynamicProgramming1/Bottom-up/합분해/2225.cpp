//2225번
//0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.
//덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1 + 2와 2 + 1은 서로 다른 경우).또한 한 개의 수를 여러 번 쓸 수도 있다.
// 입력: 첫째 줄에 두 정수 N(1 ≤ N ≤ 200), K(1 ≤ K ≤ 200)가 주어진다.
//출력: 첫째 줄에 답을 1, 000, 000, 000으로 나눈 나머지를 출력한다.
#include <iostream>

using namespace std;
long long d[201][201]; //d[i]일때 0부터 i까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수
int mod = 1000000000;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int k, n;

	cin >> n >> k;
	d[0][0] = 1LL;
	//D[K][N] = D[K-1][N-L]의 합 => L은 N번째 항 즉, 마지막 항에 들어가는 수 0<=L<=N
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int l = 0; l <= j; l++)
			{
				d[i][j] += d[i - 1][j - l];
				d[i][j] %= mod;
			}
		}
	}

	cout << d[k][n];
	return 0;
}