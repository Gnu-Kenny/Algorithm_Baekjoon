//6603�� [���Ʈ ����] <����>
//���� �ζǴ�{ 1, 2, ..., 49 }���� �� 6���� ����.
//�ζ� ��ȣ�� �����ϴµ� ���Ǵ� ���� ������ ������ 49���� �� �� k(k > 6)���� ����
//��� ���� S�� ���� ���� �� ���� ������ ��ȣ�� �����ϴ� ���̴�.
//���� S�� k�� �־����� ��, ���� ���� ��� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
#include <iostream>	
#include <algorithm>
using namespace std;

int sequence[13];	//���� S�� �ش��ϴ� �迭
int selected[13];	//���� S�� �� �� ���õ� 6���� ���� ��Ÿ���� �迭
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 1;
	
	while (n)
	{
		cin >> n;	//������ ���� �Է�
		if (!n)
			break;
		for (int i = 0; i < n; i++)
		{
			cin >> sequence[i];	// ���տ� ���ԵǴ� ���� ������������ �Է�
		}
		/*������ �� �� ���� �տ� �ִ� ������ ���ʷ� ����*/
		for (int i = 0; i < n; i++)	
		{
			if (i < 6)
				selected[i] = 1;
			else
				selected[i] = 0;
		}

		int ans[6];	//��µ� �迭�� ������ �迭
		do
		{	
			int index = 0;	//��µ� �迭�� �ε����� ��Ÿ���� ����
			for (int i = 0; i < n; i++)
			{	
				/*���õ� ����� ��µ� �迭�� ����*/
				if (selected[i])
				{
					ans[index] = sequence[i];
					index++;
				}
			}
			
			sort(ans, ans + 6);	//�迭�� ������������ ����
			
			/*���� ���� ����� �ش��ϴ� �迭 ���*/
			for (int i = 0; i < 6; i++)
			{
				cout << ans[i] << ' ';
			}
			cout << '\n';
			
		} while (prev_permutation(selected, selected + n));
		cout << '\n';
	}
	return 0;
}