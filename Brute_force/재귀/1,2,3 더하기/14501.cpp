//14501�� [���Ʈ ����] <���>
//���� n�� �־����� ��, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <iostream>

using namespace std;
int go(int count, int sum, int goal);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int m;
	while (n--)
	{
		cin >> m;
		cout << go(0, 0, m) << '\n';
	}
	return 0;
}

int go(int count, int sum, int goal)
{
	if (sum > goal) return 0;
	if (sum == goal) return 1;
	int now = 0;
	for (int i = 1; i <= 3; i++)
	{
		now += go(count + 1, sum + i, goal);
	}
	return now;
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