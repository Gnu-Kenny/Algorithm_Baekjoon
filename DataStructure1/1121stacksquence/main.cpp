#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<char> s;
	int n = 0, m = 0, k = 0, i = 1, up_cnt = 0, dn_cnt = 0, out_cnt = 0, flag = 0;
	char output[100];

	scanf("%d", &n);
	while (n > 0)
	{
		scanf("%d", &m);
		if (m > up_cnt)
		{
			for (int i = 0; i < m - k; i++)
			{
				s.push(up_cnt + 1);
				output[out_cnt] = '+';
				out_cnt++;
				up_cnt++;
			}
			output[out_cnt] = '-';
			if (!s.empty())
				s.pop();
			out_cnt++;
		}
		else
		{
			if (m < dn_cnt)
			{
				output[out_cnt] = '-';
				out_cnt++;
				if (!s.empty())
					s.pop();
			}
			else
			{
				flag = 1;
			}
		}
		k = up_cnt;
		dn_cnt = m;
		n--;
	}
	if (flag == 0)
	{
		for (int i = 0; i < out_cnt; i++)
			printf("%c\n", output[i]);
	}
	else
		printf("NO\n");
	
	return 0;
}