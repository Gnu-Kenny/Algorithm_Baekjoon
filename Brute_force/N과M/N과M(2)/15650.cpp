//15650번 [브루트포스] <재귀>
//자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
//1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
//고른 수열은 오름차순이어야 한다.
#include <iostream>
using namespace std;
bool check[10];
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
	/*순열 index = 0 ~ m-1 이므로 m일때 순열 출력*/
	if (index == m) {
		for (int i = 0; i < m; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++)  //start~n까지
	{
		if (check[i]) continue;  //사용 유무 체크
		check[i] = true;  //사용했음
		ans[index] = i;  //index번째 i 저장
		go(index + 1, i + 1, n, m);  //순열 완성될때까지 반복
		check[i] = false;
	}

}