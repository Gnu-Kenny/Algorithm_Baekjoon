//6603번 [브루트 포스] <순열>
//독일 로또는{ 1, 2, ..., 49 }에서 수 6개를 고른다.
//로또 번호를 선택하는데 사용되는 가장 유명한 전략은 49가지 수 중 k(k > 6)개의 수를
//골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것이다.
//집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오.
#include <iostream>	
#include <algorithm>
using namespace std;

int sequence[13];	//집합 S에 해당하는 배열
int selected[13];	//집합 S의 수 중 선택된 6개의 수를 나타내는 배열
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 1;
	
	while (n)
	{
		cin >> n;	//집합의 길이 입력
		if (!n)
			break;
		for (int i = 0; i < n; i++)
		{
			cin >> sequence[i];	// 집합에 포함되는 수를 오름차순으로 입력
		}
		/*집합의 수 중 가장 앞에 있는 수부터 차례로 선택*/
		for (int i = 0; i < n; i++)	
		{
			if (i < 6)
				selected[i] = 1;
			else
				selected[i] = 0;
		}

		int ans[6];	//출력될 배열을 저장할 배열
		do
		{	
			int index = 0;	//출력될 배열의 인덱스를 나타내는 변수
			for (int i = 0; i < n; i++)
			{	
				/*선택된 수라면 출력될 배열에 저장*/
				if (selected[i])
				{
					ans[index] = sequence[i];
					index++;
				}
			}
			
			sort(ans, ans + 6);	//배열을 오름차순으로 정렬
			
			/*수를 고르는 방법에 해당하는 배열 출력*/
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