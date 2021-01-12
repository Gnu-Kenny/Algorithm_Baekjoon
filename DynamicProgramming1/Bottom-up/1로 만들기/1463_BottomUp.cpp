//1463번 문제 <Bottom-up 방식>
#define _NO_CRT_SECURE_WARNINGS
#include <iostream>
using namespace std;
int d[1000000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	d[1] = 0;	// 초기화를 통해서만 나타낼수있는 가장 작은 문제
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;		//N -> N-1
		if (i % 2 == 0 && d[i] > d[i / 2] + 1)
		{
			d[i] = d[i / 2] + 1;	// N-> N/2
		}
		if (i % 3 == 0 && d[i] > d[i / 3] + 1)
		{
			d[i] = d[i / 3] + 1;	// N-> N/3
		}
	}
	cout << d[n];
	
}

//Bottom-up
//1. 문제를 크기가 작은 문제부터 차례대로 푼다.
//2. 문제의 크기를 조금씩 크게 만들면서 문제를 점점 푼다.
//3. 작은 문제를 풀면서 왔기 때문에, 큰 문제는 항상 풀 수 있다.
//4. 반복하다 보면 가장 큰 문제를 풀 수 있다.
