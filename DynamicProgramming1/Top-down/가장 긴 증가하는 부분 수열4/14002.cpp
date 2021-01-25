//14002번, <bottom-up> <Top-down> <역추적>
//수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
//예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
//첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
//둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1, 000)
//첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
//둘째 줄에는 가장 긴 증가하는 부분 수열을 출력한다.그러한 수열이 여러가지인 경우 아무거나 출력한다.
#include <iostream>
#include <algorithm>
using namespace std;
void go(int p);
int d[1001];	// d[i] => 수열의 길이가 i일때, 가장 긴 증가하는 부분 수열의 길이
int sequence[1001];	//수열 초기화
int v[1001];		//v[i] sequence[i] 앞에 와야하는 수의 인덱스 -> 역추적을 통해 수열의 값들을 순차적으로 나열
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int sequenceLength;
	int maxLength=0;

	cin >> sequenceLength;		//수열 길이 입력

	//수열 초기화
	for (int i = 1; i <= sequenceLength; i++)	
	{
		cin >> sequence[i];
	}

	//d[i] = d[j] + 1 현재 증가하는 부분 수열의 길이는 그 전까지의 부분 수열 +1
	for (int i = 1; i <= sequenceLength; i++)
	{
		d[i] = 1;	//현재 수열의 길이 초기화
		v[i] = 0;	//이전 수열의 길이 초기화
		for (int j = 1; j < i; j++)
		{
			if (sequence[j] < sequence[i] && d[i] < d[j] + 1)	//수열이 증가하는 형태일때 길이가 최대인 부분수열 저장
			{
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}

	int ans = d[0];
	int p = 0;	//부분 수열의 길이 저장
	for (int i = 1; i <= sequenceLength; i++) {
		if (ans < d[i]) {
			ans = d[i];
			p = i;
		}
	}
	cout << ans << '\n';
	go(p);
	return 0;
}

void go(int p)		//go(p) -> sequence[p]까지 출력
{
	if (p == 0)
		return;
	go(v[p]);
	cout << sequence[p] << ' ';
}