#include <iostream>
#include <string>

using namespace std;

int gcd(int a, int b);


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b,GCD,n;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		GCD = gcd(a, b);

		cout << a * b / GCD << "\n";
	}
	

	return 0;
}

int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	else
	{
		return gcd(b, a % b);
	}

}