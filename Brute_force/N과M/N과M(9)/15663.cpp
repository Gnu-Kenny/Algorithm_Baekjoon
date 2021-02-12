// 15663번 [브루트포스] <순서>

#include <iostream>	
#include <algorithm>
using namespace std;
int num[10];
int ans[10];
int cnt[10];
void go(int index, int n, int m);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;	//N개의 자연수 중 M개를 고른 수열
	
	cin >> n >> m;
	
	int temp[10];
	for (int i = 0; i < n; i++)
	{
		cin >> temp[i];
		//cnt[i] = 0;	//성공시 빼고 해보기
	}
	sort(temp, temp + n);
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		int i_cnt = 0;
		for (int j = i + 1; j <= n; j++)
		{
			if (temp[i] == temp[j])
			{
				i_cnt++;
				num[k] = temp[i];
				cnt[k] = i_cnt + 1;
			}
			else if (temp[i] != temp[j])
			{
				if (cnt[k] == 0)
					cnt[k] = 1;
				num[k] = temp[i];
				k++;
				num[k] = temp[j];
				break;
			}
		}
		if(i_cnt>0)
			i=i+i_cnt;
	}
	go(0, n, m);
	return 0;
}

void go(int index, int n, int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << num[ans[i]] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (cnt[i] > 0)
		{
			cnt[i]-=1;
			ans[index] = i;
			go(index + 1, n, m);
			cnt[i]+=1;
		}
	}

}