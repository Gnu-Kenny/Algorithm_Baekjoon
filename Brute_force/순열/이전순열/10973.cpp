//10973�� [���Ʈ ����] <����>

#include <iostream>
#include <algorithm>
using namespace std;
int sequence[10000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i=0; i < n; i++)
	{
		cin >> sequence[i];
	}
	if (prev_permutation(sequence, sequence + n))
	{
		for (int i = 0; i < n; i++)
		{
			cout << sequence[i] << ' ';
		}
	}
	else
		cout << -1;
	return 0;
}