//14500�� [���Ʈ ����]
//�Ƹ��̴� ũ�Ⱑ N��M�� ���� ���� ��Ʈ�ι̳� �ϳ��� �������� �Ѵ�.���̴� 1��1 ũ���� ĭ���� �������� ������, 
//������ ĭ���� ������ �ϳ� ���� �ִ�. ��Ʈ�ι̳� �ϳ��� ������ ���Ƽ� ��Ʈ�ι̳밡 ���� ĭ�� ���� �ִ� ������ 
//���� �ִ�� �ϴ� ���α׷��� �ۼ��Ͻÿ�.��Ʈ�ι̳�� �ݵ�� �� ���簢���� ��Ȯ�� �ϳ��� ĭ�� �����ϵ��� ���ƾ� 
//�ϸ�, ȸ���̳� ��Ī�� ���ѵ� �ȴ�.
#include <iostream>

using namespace std;
long long tetromino[500][500];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	cin >> N >> M;
	int ans = 0;
	//NxM ���� �ʱ�ȭ
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tetromino[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// ��
			if (j < M - 3)
			{
				int temp = tetromino[i][j] + tetromino[i][j + 1] + tetromino[i][j + 2] + tetromino[i][j + 3];
				if (ans < temp) ans = temp;
			}
			//��
			if(i < N - 3)
			{
				int temp = tetromino[i][j] + tetromino[i + 1][j] + tetromino[i + 2][j] + tetromino[i + 3][j];
				if (ans < temp) ans = temp;
			}
			// ��
			if(i < N-1 && j < M-1)
			{
				int temp = tetromino[i][j] + tetromino[i + 1][j] + tetromino[i][j + 1] + tetromino[i + 1][j + 1];
				if (ans < temp) ans = temp;
			}
			// ��
			if (i < N - 1 && j < M - 2)
			{
				int temp = tetromino[i][j+1] + tetromino[i + 1][j] + tetromino[i + 1][j + 1] + tetromino[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			// ��
			if (i < N - 1 && j < M - 2)
			{
				int temp = tetromino[i][j] + tetromino[i][j + 1] + tetromino[i][j + 2] + tetromino[i + 1][j + 1];
				if (ans < temp) ans = temp;
			}
			// ��_
			if (i < N - 1 && j < M - 2)
			{
				int temp = tetromino[i][j] + tetromino[i][j + 1] + tetromino[i + 1][j + 1] + tetromino[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			// s
			if (i < N - 1 && j < M - 2)
			{
				int temp = tetromino[i+1][j] + tetromino[i+1][j + 1] + tetromino[i][j + 1] + tetromino[i][j + 2];
				if (ans < temp) ans = temp;
			}
			// ��
			if (i < N - 1 && j < M - 2)
			{
				int temp = tetromino[i][j] + tetromino[i + 1][j] + tetromino[i + 1][j + 1] + tetromino[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			// �� reverse
			if (i < N - 1 && j < M - 2)
			{
				int temp = tetromino[i + 1][j] + tetromino[i + 1][j + 1] + tetromino[i + 1][j + 2] + tetromino[i][j + 2];
				if (ans < temp) ans = temp;
			}
			// ��
			if (i < N - 1 && j < M - 2)
			{
				int temp = tetromino[i][j] + tetromino[i][j + 1] + tetromino[i][j + 2] + tetromino[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			// �� reverse
			if (i < N - 1 && j < M - 2)
			{
				int temp = tetromino[i][j] + tetromino[i + 1][j] + tetromino[i][j + 1] + tetromino[i][j + 2];
				if (ans < temp) ans = temp;
			}
			// ��
			if (i < N - 2 && j < M - 1)
			{
				int temp = tetromino[i][j] + tetromino[i + 1][j] + tetromino[i + 2][j] + tetromino[i + 1][j + 1];
				if (ans < temp) ans = temp;
			}
			// ��
			if (i < N - 2 && j < M - 1)
			{
				int temp = tetromino[i + 1][j] + tetromino[i][j + 1] + tetromino[i + 1][j + 1] + tetromino[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			// ��
			if (i < N - 2 && j < M - 1)
			{
				int temp = tetromino[i][j] + tetromino[i][j + 1] + tetromino[i + 1][j + 1] + tetromino[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			// �� reverse
			if (i < N - 2 && j < M - 1)
			{
				int temp = tetromino[i][j] + tetromino[i][j + 1] + tetromino[i + 1][j] + tetromino[i + 2][j];
				if (ans < temp) ans = temp;
			}
			// ��
			if (i < N - 2 && j < M - 1)
			{
				int temp = tetromino[i][j] + tetromino[i + 1][j] + tetromino[i + 2][j] + tetromino[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			// �� reverse
			if (i < N - 2 && j < M - 1)
			{
				int temp = tetromino[i][j + 1] + tetromino[i + 1][j + 1] + tetromino[i + 2][j + 1] + tetromino[i + 2][j];
				if (ans < temp) ans = temp;
			}
			if (i < N - 2 && j < M - 1)
			{
				int temp = tetromino[i][j] + tetromino[i + 1][j] + tetromino[i + 1][j + 1] + tetromino[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			if (i < N - 2 && j < M - 1)
			{
				int temp = tetromino[i][j + 1] + tetromino[i + 1][j + 1] + tetromino[i + 1][j] + tetromino[i + 2][j];
				if (ans < temp) ans = temp;
			}

		}
	}
	cout << ans;

	return 0;
}
