//1759�� [���Ʈ ����] <���>

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
	/*������ ã�� ���*/
	if (password.length() == n)
	{
		if (check(password))
		{
			cout << password << '\n';
		}
		return;
	}
	/*�Ұ����� ���*/
	if (i == alpha.size()) return;

	/*���� ��� */
	go(n, alpha, password + alpha[i], i + 1); //1. i��°�� ���  
	go(n, alpha, password, i + 1);	//2. i��°�� ������
}