//14501�� [���Ʈ ����] <���>

#include <iostream>
using namespace std;
void go(int day, int sum);
int t[21], p[21];
int n;
int ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		cin >> t[i] >> p[i];
	}
	
	go(1, 0);

	cout << ans << '\n';
	return 0;
}

void go(int day, int sum)
{
	if (day == n + 1)
	{
		if (ans < sum)
			ans = sum;
		return;
	}
	if (day > n + 1)
		return;
	go(day + 1, sum);
	go(day + t[day], sum + p[day]);
			
}

//<���> Ǯ�̹�
//goal�� ������.
//go(count, sum, goal)
//���� count���� �� sum�� ����� ����� ��
//��: sum + i
//count -> count +1
//sum -> sum + i
//1. �Ұ����� ��� sum > goal
// (1) �ƹ��� ��� ȣ���� ����ص� ������ ���� �� ���� ���
// (2) ������ ������ ������ ���
//2. ������ ã�� ��� sum == goal
// - �� �̻� �Լ� ȣ���� �̾�� �ʿ䰡 ���� ���
//3. ���� ��� ȣ�� go(count + 1, sum + i, goal)
// - ������ ã����, ���������� ���� ���