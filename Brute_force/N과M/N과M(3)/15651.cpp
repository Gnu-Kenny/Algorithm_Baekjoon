//15651�� [���Ʈ ����] <���>
//�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
//���� ���� ���� �� ��� �ȴ�.
#include <iostream>

using namespace std;
int ans[10];
void go(int index, int n, int m);
int main()
{
	int n, m;

	cin >> n >> m;
	go(0, n, m);
	return 0;
}

void go(int index, int n, int m)
{
	/*���� index = 0 ~ m-1 �̹Ƿ� m�϶� ���� ���*/
	if (index == m)
	{
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		ans[index] = i;		//index��° i ����
		go(index + 1, n, m);	//���� �ϼ��ɶ����� �ݺ�
	}
}