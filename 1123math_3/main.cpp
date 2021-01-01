#include <iostream>
#include <string>

using namespace std;

int main()
{
	
	int flag = 0;
	int minrty[1000];
	int pn = 0;
	int a, b;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		if (i == 2)
			minrty[pn] = 2;
		else if (i > 2)
		{
			for (int j = 2; j < i; j++)
			{
				if (i % j == 0)
				{
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				minrty[pn] = i;
				pn++;
			}
		}

	}
	for (int i = 0; i < pn; i++)
	{
		cout << minrty[i] << "\n";
	}

	return 0;
}

