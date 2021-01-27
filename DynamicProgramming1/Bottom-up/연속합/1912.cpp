//1912�� <Bottom-up> <����>

#include <iostream>	
#include <algorithm>
using namespace std;
int d[100001];	// i ��° ���� ������ ���� ū ������
int sequence[100001];	//���� 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int answer=-1001;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> sequence[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			d[i] = sequence[i];
			continue;
		}
			
		d[i] = max(d[i - 1] + sequence[i], sequence[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		answer = max(answer, d[i]);
	}
	cout << answer;
	return 0;
}