#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<char> s1;
	string str;
	int flag = 0;

	getline(cin, str);
	str += '\n';
	for (char ch : str)
	{
		if ((ch == '<' || flag == 1) &&(ch != '>'))
		{
			
			if (!s1.empty())
			{
				while (!s1.empty())
				{
					cout << s1.top();
					s1.pop();
				}
				
			}
			flag = 1;
			
			cout << ch;
			
		}
		else if (ch == '>')
		{
			while (!s1.empty())
			{
				s1.pop();
			}
			cout << '>';
			flag = 0;
		}
		else if ((ch == ' ' || ch == '\n') && flag == 0)
		{
			while (!s1.empty())
			{
				cout << s1.top();
				if(!s1.empty())
					s1.pop();
			}
			cout << " ";
		}
		else
		{
			s1.push(ch);
		}

		
		

		
		
	}
	
	return 0;
}