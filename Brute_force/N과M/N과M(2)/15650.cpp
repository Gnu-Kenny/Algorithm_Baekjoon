//15650�� [���Ʈ����] <���>
//�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
//�� ������ ���������̾�� �Ѵ�.
#include <iostream>
using namespace std;
bool check[10];
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
	/*���� index = 0 ~ m-1 �̹Ƿ� m�϶� ���� ���*/
	if (index == m) {
		for (int i = 0; i < m; i++)
		{
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i <= n; i++)  //start~n����
	{
		if (check[i]) continue;  //��� ���� üũ
		check[i] = true;  //�������
		ans[index] = i;  //index��° i ����
		go(index + 1, i + 1, n, m);  //���� �ϼ��ɶ����� �ݺ�
		check[i] = false;
	}

}