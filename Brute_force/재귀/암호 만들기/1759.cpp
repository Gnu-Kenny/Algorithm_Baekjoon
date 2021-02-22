//1759번 [브루트 포스] <재귀>

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool check(string& password);
void go(int n, vector<char>& alpha, string password, int i);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin >> n >> m;
	vector<char> alpha(m);
	for (int i = 0; i < m; i++)
	{
		cin >> alpha[i];
	}
	sort(alpha.begin(), alpha.end());

	go(n, alpha, "", 0);

	return 0;
}

bool check(string& password)
{
	int ja = 0;
	int mo = 0;
	for (char x : password)
	{
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
			mo++;
		else
			ja++;

	}
	return ja >= 2 && mo >= 1;
}
void go(int n, vector<char>& alpha, string password, int i)
{
	/*정답을 찾은 경우*/
	if (password.length() == n)
	{
		if (check(password))
		{
			cout << password << '\n';
		}
		return;
	}
	/*불가능한 경우*/
	if (i == alpha.size()) return;

	/*다음 경우 */
	go(n, alpha, password + alpha[i], i + 1); //1. i번째를 사용  
	go(n, alpha, password, i + 1);	//2. i번째를 사용않음
}