//3085번 [브루트 포스]
//가장 처음에 N×N크기에 사탕을 채워 놓는다.사탕의 색은 모두 같지 않을 수도 있다.
//상근이는 사탕의 색이 다른 인접한 두 칸을 고른다.그 다음 고른 칸에 들어있는 사탕을 서로 교환한다.
//이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.
//사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.
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
	vector<string> a(n);		// NxN 행렬 저장할 객체 //메모리 heap에 생성되며 동적 할당됨
	/*NxN 행렬 초기화*/
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int ans = 0;	//최대 개수 저장할 변수

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j + 1 < n)	//현재 배열 위치에서 오른쪽 값과 비교
			{
				swap(a[i][j], a[i][j + 1]);
				int temp = check(a);
				if (ans < temp) 
					ans= temp;
				swap(a[i][j], a[i][j + 1]);
			}
			if (j + 1 < n)  ////현재 배열 위치에서 아래쪽 값과 비교
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
			/*값이 교환된 뒤 현재값과 오른쪽 값 비교*/
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
		/*값이 교환된 뒤 현재값과 아래쪽 값 비교*/
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