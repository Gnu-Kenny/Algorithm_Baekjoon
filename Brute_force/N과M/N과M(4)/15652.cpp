//15652�� [���Ʈ ����] <����>
//�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//1���� N���� �ڿ��� �߿��� M���� �� ����
//���� ���� ���� �� ��� �ȴ�.
//�� ������ �񳻸������̾�� �Ѵ�. (���� A�� A1 �� A2 �� ... �� AK - 1 �� AK�� ����)
#include <iostream>	
using namespace std;
int ans[10];
void go(int index, int start, int n, int m);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;

	cin >> n >> m;

	go(0, 1, n, m);

	return 0;
}

void go(int index, int start, int n, int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << ans[i] << ' ';

		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++)
	{
		ans[index] = i;
		go(index + 1, i, n, m);

	}
}