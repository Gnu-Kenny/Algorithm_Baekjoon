//Date: 2020.12.31 BaekJoonNum: #2609
#include <iostream>
#include <string>

using namespace std;

int GCD(int a, int b);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;

	cin >> a >> b;

	cout << GCD(a, b) << "\n";

	cout << a * b / GCD(a, b);
	return 0;
}

int GCD(int a, int b)
{
	if (a % b == 0)
		return b;

	return GCD(b, a % b);
}