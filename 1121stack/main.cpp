#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<char> s_l,s_r;
	string str;
	int n;
	getline(cin, str);
	for (char ch : str)
		s_l.push(ch);
	cin >> n;
	
	while (n--)
	{
		char input;
		cin >> input;
		if (input == 'L')
		{
			if (!s_l.empty())
			{
				s_r.push(s_l.top());
				s_l.pop();
			}
		}
		else if (input == 'D')
		{
			if(!s_r.empty())
			{
				s_l.push(s_r.top());
				s_r.pop();
			}
		}
		else if (input == 'B')
		{
			if (!s_l.empty())
				s_l.pop();
		}
		else if (input == 'P')
		{
			char alpha;
			cin >> alpha;
			s_l.push(alpha);
		}
		
	}
	while (!s_l.empty())
	{
		s_r.push(s_l.top());
		if (!s_l.empty())
			s_l.pop();
	}
	while (!s_r.empty())
	{
		cout << s_r.top();
		if (!s_r.empty())
			s_r.pop();
	}
	return 0;
}