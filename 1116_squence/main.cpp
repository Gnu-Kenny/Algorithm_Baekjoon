#include <iostream>	
#include <stack>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cin.ignore();
	while (n--)
	{
		string str;
		getline(cin, str);
		str += "\n";
		stack<char> s;
		
		for (char ch : str)
		{
			
				if (ch == ')')
				{
					if (s.empty())
					{
						cout << "NO\n";
						break;
					}
					s.pop();
				}
				else if (ch == '(')
				{
					s.push(ch);
				}
				else if (ch == '\n')
				{
					if (s.empty())
					{
						cout << "YES\n";
					}
					else
					{
						cout << "NO\n";
					}

				}
			

				
		}
		
	}

	return 0;
}