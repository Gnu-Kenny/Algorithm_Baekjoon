#include <stdio.h>
//양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다.어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.
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