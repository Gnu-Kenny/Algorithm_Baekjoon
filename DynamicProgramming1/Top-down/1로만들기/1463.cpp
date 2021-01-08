//1463�� ���� <Top-down ���>
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
	if (n == 1) return 0; //���� ���� ����
	if (d[n] > 0) return d[n]; // �޸������̼�
	
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
*ž �ٿ� ���
 1. ū ������ ���� ������ ������.
 2. ���� ������ Ǭ��.
 3. ���� ������ Ǯ������, ���� ū ������ Ǭ��.
*/