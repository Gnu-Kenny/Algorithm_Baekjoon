//10972번 [브루트 포스] <순열>
//1부터 N까지의 수로 이루어진 순열이 있다.이때, 사전순으로 다음에 오는 순열을 구하는 프로그램을 작성하시오.
//사전 순으로 가장 앞서는 순열은 오름차순으로 이루어진 순열이고, 가장 마지막에 오는 순열은
//내림차순으로 이루어진 순열이다. N(1 ≤ N ≤ 10,000)
//출력시, 사전순으로 마지막에 오는 순열인 경우에는 -1을 출력한다.
#include <iostream>	
#include <algorithm>
using namespace std;
int sequence[10000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	/*순열과 예외 처리를 위한 배열에 값을 입력받는다.*/
	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}
	//다음 순열을 구하고 true 반환
	if (next_permutation(sequence, sequence + n))
	{
		for (int i = 0; i < n; i++)
		{
			cout << sequence[i] << ' ';
		}
	}
	else  //다음 순열이 없다면
		cout << -1;
	return 0;
}
