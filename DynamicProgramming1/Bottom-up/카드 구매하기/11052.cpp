//11052�� ����	<Bottom-up>
//ī�� ���� ������ �־����� ��, N���� ī�带 �����ϱ� ���� �α԰� 
//�����ؾ� �ϴ� �ݾ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
//������ ī���ѿ� ���ԵǾ� �ִ� ī�� ������ ���� N�� ���ƾ� �Ѵ�. 
//ù° �� �Է�: �����Ϸ��� �ϴ� ī�� ���� N / ��° �� �Է�: Pi�� P1~Pn���� �־�����.
#include <iostream>
#include <algorithm>
using namespace std;
int card_Price[10000]; //P1~Pn
int d[10000];	//ī�� �����ϴ� �ִ� ���

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int card_Num;

	cin >> card_Num;	//�����Ϸ��� �ϴ� ī�� ���� N
	
	for (int i=1; i <= card_Num; i++)	//P1~Pi ī���� ���� �Է�
	{
		cin >> card_Price[i];
	}

	//ī�� �����ϴ� �ִ� ��� d[n] = d[n-i]+P[i]
	for (int i = 1; i <= card_Num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			d[i] = max(d[i], d[i-j] + card_Price[j]);
		}
	}
	
	cout << d[card_Num];
	return 0;
}

//Bottom-up
//1. ������ ũ�Ⱑ ���� �������� ���ʴ�� Ǭ��.
//2. ������ ũ�⸦ ���ݾ� ũ�� ����鼭 ������ ���� Ǭ��.
//3. ���� ������ Ǯ�鼭 �Ա� ������, ū ������ �׻� Ǯ �� �ִ�.
//4. �ݺ��ϴ� ���� ���� ū ������ Ǯ �� �ִ�.