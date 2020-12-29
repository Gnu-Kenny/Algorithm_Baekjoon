#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<char> s;
	string str;
	int char_cnt=0,stick_cnt=0;
	getline(cin, str);

	for (char ch : str)
	{
		if (ch == ')')
		{
			if (!s.empty())
			{
				if (char_cnt == 0)
				{

					s.pop();
					stick_cnt++;

				}
				else
				{
					s.pop();
					stick_cnt += s.size();
					char_cnt = 0;
				}
				
				
			}
			
			
		}
		else if(ch == '(')
		{
			s.push(ch);
			char_cnt++;
		}
	}
	cout << stick_cnt;
	return 0;
}