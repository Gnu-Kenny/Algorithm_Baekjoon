//11053�� <Bottom-up> <LIS : Longest Increasing Subsequence>
//���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//���� ���, ���� A = { 10, 20, 10, 30, 20, 50 } �� ��쿡 ���� �� �����ϴ� �κ� ������ A = { 10, 20, 10, 30, 20, 50 } �̰�, ���̴� 4�̴�.
//�Է�
//ù° �ٿ� ���� A�� ũ�� N(1 �� N �� 1, 000)�� �־�����.
//��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1, 000)
//���
//ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.
#include <iostream>
#include <algorithm>
using namespace std;
int squence[1001];	// ���� �ʱ�ȭ	
int d[1001];		// d[i] => ���̰� i�� ���� �� ���� �� �����ϴ� �κ� ������ ����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int squenceLength;	// ������ ���� ���� ����
	int length=0;	//d[1]~d[i] �� ���� ���̰� �� ��츦 ���Ͽ� �����ϱ� ���� ����.

	cin >> squenceLength;		//���� ���� �Է�

	for (int i = 1; i <= squenceLength; i++)
	{
		cin >> squence[i];		//
	}
	for (int i = 1; i <= squenceLength; i++)
	{
		d[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (squence[j] < squence[i] && d[i] < d[j] + 1) //1,2, ... j, i .. i�� �ٷ� ������ �� j���� ũ��, d[i]�� d[1]~d[j]���� ���� ���ؼ� d[i]�� �۴ٸ�
			{
				d[i] = d[j] + 1;
			}
			
		}
		length = max(length, d[i]);
	}

	cout << length;

	return 0;
}

//LIS (Longest Increasing Subsquence)
//Bottom-up