//6064�� [���Ʈ ����]

#include <iostream>

using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int M, N, x, y;	//<M:N>�� ������ �� , <x:y> �⵵�� ����ϰ� ���� ��
		cin >> M >> N >> x >> y;
		x -= 1;		//������ ������ ���� -1
		y -= 1;
		bool flag = false; //<x:y>�� ��ȿ���� ��Ÿ���� �÷��� ����
		//<M,N>�϶� <x,y> = <i%M,i%N>
		for (int j = x; j < (M * N); j += M)	//j+M -> ���ڸ� �� ������ �� ����
		{
			if (j % N == y)
			{
				cout << j + 1 << '\n';
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << -1 << '\n';
	}

	return 0;
}