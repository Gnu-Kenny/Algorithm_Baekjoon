//14501번 [브루트 포스] <재귀>

#include <iostream>
using namespace std;
void go(int day, int sum);
int t[21], p[21];
int n;
int ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		cin >> t[i] >> p[i];
	}
	
	go(1, 0);

	cout << ans << '\n';
	return 0;
}

void go(int day, int sum)
{
	if (day == n + 1)
	{
		if (ans < sum)
			ans = sum;
		return;
	}
	if (day > n + 1)
		return;
	go(day + 1, sum);
	go(day + t[day], sum + p[day]);
			
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