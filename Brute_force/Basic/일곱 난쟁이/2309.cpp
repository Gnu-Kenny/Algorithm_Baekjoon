//2309�� [���Ʈ ����]
//�پ ������ �������� ������ �ִ� �鼳���ִ�, ���ེ���Ե� �ϰ� �������� Ű�� ���� 100�� ���� ����� �´�.
//��ȩ ���� �ٿ� ���� �����̵��� Ű�� �־�����.�־����� Ű�� 100�� ���� �ʴ� �ڿ����̸�, 
//��ȩ �������� Ű�� ��� �ٸ���, ������ ������ ���� ������ ��쿡�� �ƹ��ų� ����Ѵ�.
//�ϰ� �������� Ű�� ������������ ����Ѵ�.�ϰ� �����̸� ã�� �� ���� ���� ����.
#include <iostream>	
#include <algorithm>
using namespace std;
int hobbit[9];	//hobbit[i]�϶� i��° ������ Ű
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	

	int sum = 0;	//9���� ������ Ű ��
	/*hobbit �ʱ�ȭ*/
	for (int i = 0; i < 9; i++)
	{
		cin >> hobbit[i];	//i��° ������ Ű �Է�
		/*����ó��*/
		if (hobbit[i] > 0 && hobbit[i] <= 100)	// 0< �������� Ű <=100 �϶��� ����
		{
			for (int j = 0; j < i; j++)	//������ ������ Ű�� ���� ���� ������ �� �Է�
			{
				if (hobbit[i] == hobbit[j])
				{
					i--;
					break;
				}
			}
		}
		else
			i--;

		sum += hobbit[i];	//9���� ������ Ű �տ� �� ��ħ
	}
	int flag = 0;	//�ش� ���� ������ ù��° for���� Ż���ϱ� ���� flag ����
	/*sum - hobbit[i] - hobbit[j] == 100*/
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (sum - hobbit[i] - hobbit[j] == 100)
			{
				/*���� ��� ������ �� �Է� -> ���Ľ� ��� �������� ���ܽ�Ű�� ����*/
				hobbit[i] = 101;
				hobbit[j] = 101;
				sort(hobbit, hobbit + 9);
				flag = 1;
				break;
			}
			
		}
		if (flag)
			break;
	}

	for (int i = 0; i < 7; i++)
		cout << hobbit[i] << '\n';
	
	return 0;
}

