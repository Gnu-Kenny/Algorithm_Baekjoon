//1699번 <Bottom-up>
//어떤 자연수 N은 그보다 작거나 같은 제곱수들의 합으로 나타낼 수 있다.
//주어진 자연수 N을 이렇게 제곱수들의 합으로 표현할 때에 그 항의 최소개수를 구하는 프로그램을 작성하시오.
//입력: 첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 100,000)
//출력: 주어진 자연수를 제곱수의 합으로 나타낼 때에 그 제곱수 항의 최소 개수를 출력한다.

#include <iostream>	

using namespace std;
int d[100001];	//d[i] => i를 제곱수의 합으로 나타낼 때에 항의 최소 개수 저장
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num;	

	cin >> num;		//자연수 입력
	d[0] = 0;	//자연수 입력이므로 0일때 항의 개수 0
	//d[i] = d[i - j * j] + 1 
	for (int i = 1; i <= num; i++)
	{
		d[i] = i;
		for (int j = 1; j*j <= i; j++)
		{
			if (d[i] > d[i - j * j] + 1)
				d[i] = d[i - j * j] + 1;
		}

	}
	cout << d[num];


	return 0;
}