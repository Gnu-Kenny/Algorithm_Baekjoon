//10819�� [���Ʈ����] <����>
//N���� ������ �̷���� �迭 A�� �־�����. �̶�, �迭�� ����ִ� ������ ������ ������ �ٲ㼭 
//���� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|
//ù° �ٿ� N (3 �� N �� 8)�� �־�����. ��° �ٿ��� �迭 A�� ����ִ� ������ �־�����. 
//ù° �ٿ� �迭�� ����ִ� ���� ������ ������ �ٲ㼭 ���� �� �ִ� ���� �ִ��� ����Ѵ�.
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int sequence[8];	//�Է� ���� �迭
int calculate(int* sequence, int n);	//�迭�� �� ������ ���� ��ȯ�ϴ� �Լ�
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;	//�迭�� ���� ������ ����
	cin >> n;	//�迭�� ���� �� ����
	/*�迭 �ʱ�ȭ*/
	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}
	/*��� ����� ���� ����ϱ� ���� �迭�� �������� ����*/
	sort(sequence, sequence + n);

	int ans=0;	//������ �ִ밪�� ������ ����
	do {
		int temp = calculate(sequence,n);	//�ӽ÷� �迭�� �� ������ ���� ������ ����
		ans = max(ans, temp);		// ���簪�� ���Ͽ� �� ū ���� ����
	} while (next_permutation(sequence, sequence + n));	//���� �迭�� �����Ѵٸ� ���� �迭�� �����ϰ� true���� ��ȯ�ϴ� �Լ�

	cout << ans;	//������ �ִ� �� ���
	return 0;
}

int calculate(int* sequence,int n)
{
	int sumOfDifference = 0;	//������ ���� ������ ����
	for (int i = 0; i+1 < n; i++)
	{
		int difference = 0;
		if ((sequence[i] - sequence[i + 1]) < 0)	//���̰� �������
			difference = -(sequence[i] - sequence[i + 1]);
		else  //���̰� ������
			difference = sequence[i] - sequence[i + 1];
		sumOfDifference += difference;
	}
	return sumOfDifference;
}