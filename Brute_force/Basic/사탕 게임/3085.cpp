//3085�� [���Ʈ ����]
//���� ó���� N��Nũ�⿡ ������ ä�� ���´�.������ ���� ��� ���� ���� ���� �ִ�.
//����̴� ������ ���� �ٸ� ������ �� ĭ�� ����.�� ���� �� ĭ�� ����ִ� ������ ���� ��ȯ�Ѵ�.
//����, ��� ���� ������ �̷���� �ִ� ���� �� ���� �κ�(�� �Ǵ� ��)�� �� ���� �� ������ ��� �Դ´�.
//������ ä���� ���°� �־����� ��, ����̰� ���� �� �ִ� ������ �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <iostream>
#include <vector>

using namespace std;
int check(vector<string>& a);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<string> a(n);		// NxN ��� ������ ��ü //�޸� heap�� �����Ǹ� ���� �Ҵ��
	/*NxN ��� �ʱ�ȭ*/
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int ans = 0;	//�ִ� ���� ������ ����

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j + 1 < n)	//���� �迭 ��ġ���� ������ ���� ��
			{
				swap(a[i][j], a[i][j + 1]);
				int temp = check(a);
				if (ans < temp) 
					ans= temp;
				swap(a[i][j], a[i][j + 1]);
			}
			if (j + 1 < n)  ////���� �迭 ��ġ���� �Ʒ��� ���� ��
			{
				swap(a[j][i], a[j + 1][i]);
				int temp = check(a);
				if (ans < temp)
					ans = temp;
				swap(a[j][i], a[j + 1][i]);
			}
		}

	}
	cout << ans << '\n';
	return 0;
}

int check(vector<string>& a)
{
	int n = a.size();
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;
		for (int j = 1; j < n; j++)
		{
			/*���� ��ȯ�� �� ���簪�� ������ �� ��*/
			if (a[i][j] == a[i][j - 1])
			{
				cnt++;
			}
			else
			{
				cnt = 1;
			}
			if (ans < cnt)
				ans = cnt;

		}
		cnt = 1;
		/*���� ��ȯ�� �� ���簪�� �Ʒ��� �� ��*/
		for (int j = 1; j < n; j++)
		{
			if (a[j][i] == a[j - 1][i])
			{
				cnt++;
			}
			else
			{
				cnt = 1;
			}
			if (ans < cnt)
			{
				ans = cnt;
			}
			if (ans < cnt)
				ans = cnt;
		}
	}
	return ans;
}