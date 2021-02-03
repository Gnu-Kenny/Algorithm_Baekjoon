//14500번 [브루트 포스]
//아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다.종이는 1×1 크기의 칸으로 나누어져 있으며, 
//각각의 칸에는 정수가 하나 쓰여 있다. 테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 
//합을 최대로 하는 프로그램을 작성하시오.테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 
//하며, 회전이나 대칭을 시켜도 된다.
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
	//NxM 격자 초기화
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
			// ㅡ
			if (j < M - 3)
			{
				int temp = tetromino[i][j] + tetromino[i][j + 1] + tetromino[i][j + 2] + tetromino[i][j + 3];
				if (ans < temp) ans = temp;
			}
			//ㅣ
			if(i < N - 3)
			{
				int temp = tetromino[i][j] + tetromino[i + 1][j] + tetromino[i + 2][j] + tetromino[i + 3][j];
				if (ans < temp) ans = temp;
			}
			// ㅁ
			if(i < N-1 && j < M-1)
			{
				int temp = tetromino[i][j] + tetromino[i + 1][j] + tetromino[i][j + 1] + tetromino[i + 1][j + 1];
				if (ans < temp) ans = temp;
			}
			// ㅗ
			if (i < N - 1 && j < M - 2)
			{
				int temp = tetromino[i][j+1] + tetromino[i + 1][j] + tetromino[i + 1][j + 1] + tetromino[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			// ㅜ
			if (i < N - 1 && j < M - 2)
			{
				int temp = tetromino[i][j] + tetromino[i][j + 1] + tetromino[i][j + 2] + tetromino[i + 1][j + 1];
				if (ans < temp) ans = temp;
			}
			// ㄱ_
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
			// ㄴ
			if (i < N - 1 && j < M - 2)
			{
				int temp = tetromino[i][j] + tetromino[i + 1][j] + tetromino[i + 1][j + 1] + tetromino[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			// ㄴ reverse
			if (i < N - 1 && j < M - 2)
			{
				int temp = tetromino[i + 1][j] + tetromino[i + 1][j + 1] + tetromino[i + 1][j + 2] + tetromino[i][j + 2];
				if (ans < temp) ans = temp;
			}
			// ㄱ
			if (i < N - 1 && j < M - 2)
			{
				int temp = tetromino[i][j] + tetromino[i][j + 1] + tetromino[i][j + 2] + tetromino[i + 1][j + 2];
				if (ans < temp) ans = temp;
			}
			// ㄱ reverse
			if (i < N - 1 && j < M - 2)
			{
				int temp = tetromino[i][j] + tetromino[i + 1][j] + tetromino[i][j + 1] + tetromino[i][j + 2];
				if (ans < temp) ans = temp;
			}
			// ㅏ
			if (i < N - 2 && j < M - 1)
			{
				int temp = tetromino[i][j] + tetromino[i + 1][j] + tetromino[i + 2][j] + tetromino[i + 1][j + 1];
				if (ans < temp) ans = temp;
			}
			// ㅓ
			if (i < N - 2 && j < M - 1)
			{
				int temp = tetromino[i + 1][j] + tetromino[i][j + 1] + tetromino[i + 1][j + 1] + tetromino[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			// ㄱ
			if (i < N - 2 && j < M - 1)
			{
				int temp = tetromino[i][j] + tetromino[i][j + 1] + tetromino[i + 1][j + 1] + tetromino[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			// ㄱ reverse
			if (i < N - 2 && j < M - 1)
			{
				int temp = tetromino[i][j] + tetromino[i][j + 1] + tetromino[i + 1][j] + tetromino[i + 2][j];
				if (ans < temp) ans = temp;
			}
			// ㄴ
			if (i < N - 2 && j < M - 1)
			{
				int temp = tetromino[i][j] + tetromino[i + 1][j] + tetromino[i + 2][j] + tetromino[i + 2][j + 1];
				if (ans < temp) ans = temp;
			}
			// ㄴ reverse
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
