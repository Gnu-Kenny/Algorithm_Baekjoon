#include <iostream>
#include <string>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,a,pn = 0;
	int flag = 0;
	cin >> n;

	while (n--)
	{
		cin >> a;
		
		if (a == 2)
		{
			pn++;
			
		}
		else if (a > 2)
		{
			for (int i = 2; i < a; i++)
			{
				if (a % i == 0)
				{
					flag = 1;
					break;
				}

			}
			if (!flag)
			{
				pn++;
				
			}
			flag = 0;
			
		}
	}
	cout << pn;
	return 0;
}

