//14501번 [브루트 포스] <재귀>
//정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
#include <iostream>

using namespace std;
int go(int count, int sum, int goal);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int m;
	while (n--)
	{
		cin >> m;
		cout << go(0, 0, m) << '\n';
	}
	return 0;
}

int go(int count, int sum, int goal)
{
	if (sum > goal) return 0;
	if (sum == goal) return 1;
	int now = 0;
	for (int i = 1; i <= 3; i++)
	{
		now += go(count + 1, sum + i, goal);
	}
	return now;
}
//<재귀> 풀이법
//goal을 만들자.
//go(count, sum, goal)
//숫자 count개로 합 sum을 만드는 경우의 수
//합: sum + i
//count -> count +1
//sum -> sum + i
//1. 불가능한 경우 sum > goal
// (1) 아무리 재귀 호출을 계속해도 정답을 구할 수 없는 경우
// (2) 문제의 조건을 위배한 경우
//2. 정답을 찾은 경우 sum == goal
// - 더 이상 함수 호출을 이어나갈 필요가 없는 경우
//3. 다음 경우 호출 go(count + 1, sum + i, goal)
// - 정답을 찾지도, 위배하지도 않은 경우