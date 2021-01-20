// 16194�� ���� <Bottom-up>
//ī�� ���� ������ �־����� ��, N���� ī�带 �����ϱ� ����
//�����ؾ� �ϴ� �ݾ��� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
//ù° �ٿ� �α԰� �����Ϸ��� �ϴ� ī���� ���� N�� �־�����. (1 �� N �� 1,000)
//��° �ٿ��� Pi�� P1���� PN���� ������� �־�����.(i�� ī���ѿ� ����ִ� ī�� ��) (1 �� Pi �� 10,000)
#include <iostream>
#include <algorithm>

using namespace std;
int min_Price[10000];	//�����ؾ� �ϴ� �ݾ��� �ּڰ�
int cardpack_Price[10000];	//P1~Pi���� ī������ ���� (1 �� Pi �� 10,000)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int card_Num;

	cin >> card_Num;	//�����Ϸ��� ī���� ����

	for (int i = 1; i <= card_Num; i++)
	{
		cin >> cardpack_Price[i];		//ī�� ���� ���� �Ҵ�
		min_Price[i] = cardpack_Price[i];	//min �Լ��� ���� ���� P1~Pi�� ���� �ʱ�ȭ
	}
	/*min_Price[N]=min_Price[N-i]+cardpack_price[i]*/
	for (int i = 1; i <= card_Num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			min_Price[i] = min(min_Price[i], min_Price[i - j] + cardpack_Price[j]);	//min_Price[i]�� �����ִ� ��� ����� ���� ���Ͽ� �ּҰ� ����
		}
	}
	
	cout << min_Price[card_Num]; //ī�� N���� �� �� �ִ� �ּ� �ݾ� ���

	return 0;
}

//Bottom-up
//1. ������ ũ�Ⱑ ���� �������� ���ʴ�� Ǭ��.
//2. ������ ũ�⸦ ���ݾ� ũ�� ����鼭 ������ ���� Ǭ��.
//3. ���� ������ Ǯ�鼭 �Ա� ������, ū ������ �׻� Ǯ �� �ִ�.
//4. �ݺ��ϴ� ���� ���� ū ������ Ǯ �� �ִ�.