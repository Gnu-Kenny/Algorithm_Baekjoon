//10974�� [���Ʈ ����] <����>
//N�� �־����� ��, 1���� N������ ���� �̷���� ������ ���������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//�Է�: ù° �ٿ� N(1 �� N �� 8)�� �־�����. 
//���: ù° �ٺ��� N!���� �ٿ� ���ļ� ��� ������ ���������� ����Ѵ�.
#include <iostream>
#include <algorithm>
using namespace std;
int sequence[8];	// 1<=N<=8
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;

	cin >> n;

	/*���� �ʱ�ȭ*/
	for (int i = 0; i < n; i++)
	{
		sequence[i] = i + 1;
	}

	do {
		for (int i = 0; i < n; i++)
		{
			cout << sequence[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(sequence, sequence + n));
	return 0;
}