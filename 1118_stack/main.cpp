#include <stdio.h>
//��� A�� N�� ��¥ ����� �Ƿ���, N�� A�� ����̰�, A�� 1�� N�� �ƴϾ�� �Ѵ�.� �� N�� ��¥ ����� ��� �־��� ��, N�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
int main()
{
	int i, j, k=0, n[100000];
	int size = 1000;
	for (i = 3; i < size; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				n[k] = i;
				k++;
				break;
			}

		}
	}
	for (i = 0; i < size; i++)
	{
		if (n[i] != 0)
			break;
		printf("%d ", n[i]);
	}

	return 0;
}