#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string raser;
	
		cin >> raser;

		stack<char> a;
		for (char x : raser)
		{
			if (x == ')')
				a.push(x);
		}
		
		int cnt = 0;
		bool check = true;
		for (char x : raser)
		{
			cnt++;
			if (x == '(')
			{
				if (!a.empty())
					a.pop();
				else
					check = false;
			}
			if (cnt == raser.length() && !a.empty())
				check = false;
			

		}
		if(!check)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
		
	


	return 0;
}


