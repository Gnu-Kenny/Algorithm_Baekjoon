//10972�� [���Ʈ ����] <����>
//1���� N������ ���� �̷���� ������ �ִ�.�̶�, ���������� ������ ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//���� ������ ���� �ռ��� ������ ������������ �̷���� �����̰�, ���� �������� ���� ������
//������������ �̷���� �����̴�. N(1 �� N �� 10,000)
//��½�, ���������� �������� ���� ������ ��쿡�� -1�� ����Ѵ�.
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
	/*������ ���� ó���� ���� �迭�� ���� �Է¹޴´�.*/
	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}
	//���� ������ ���ϰ� true ��ȯ
	if (next_permutation(sequence, sequence + n))
	{
		for (int i = 0; i < n; i++)
		{
			cout << sequence[i] << ' ';
		}
	}
	else  //���� ������ ���ٸ�
		cout << -1;
	return 0;
}
