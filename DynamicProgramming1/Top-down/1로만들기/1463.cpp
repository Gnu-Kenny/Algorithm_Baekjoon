//1463번 문제 <Top-down 방식>
#define _CRT_NO_SECURE_WARNINGS
#include <iostream>

using namespace std;
int go(int n);
int d[1000000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;
	cout << go(n);

	return 0;
}

int go(int n)
{
	if (n == 1) return 0; //가장 작은 문제
	if (d[n] > 0) return d[n]; // 메모이제이션
	
	d[n] = go(n - 1) + 1; // N -> N-1
	if (n % 2 == 0)		  // N -> N/2
	{
		int temp = go(n / 2) + 1;
		if (d[n] > temp) return d[n] = temp;
	}
	if (n % 3 == 0)		 // N-> N/3
	{
		int temp = go(n / 3) + 1;
		if (d[n] > temp) return d[n] = temp;
	}
	return d[n];
}
/*
*탑 다운 방식
 1. 큰 문제를 작은 문제로 나눈다.
 2. 작은 문제를 푼다.
 3. 작은 문제를 풀었으니, 이제 큰 문제를 푼다.
*/