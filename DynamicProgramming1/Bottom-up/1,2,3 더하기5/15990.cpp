//15990번 
//정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 3가지가 있다.
//합을 나타낼 때는 수를 1개 이상 사용해야 한다. 
//단, 같은 수를 두 번 이상 연속해서 사용하면 안 된다.
//정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
#include <iostream>
#define output 1000000009
#define range 100000
using namespace std;
long long d[100001][4];
/*int 자료형은 약 21억의 수를 저장할 수 있는데 d[n][1] 하나가 최대 10억8정도의 수를 저장할수있다
문제를 풀기 위해선 ~d[n][4]까지 메모리 공간이 필요하므로 대략 30억의 수를 저장할 필요할 공간이 필요해진다.
따라서 자료형을 int -> long long으로 수정할 필요가 있었다. */
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,t;
	
	cin >> t;


	for (int i = 1; i <= range; i++)
	{
		if (i >= 1)
		{
			d[i][1] = d[i - 1][2] + d[i - 1][3];
			if (i == 1)
			{
				d[i][1] = 1;
			}
		}
		if (i >= 2)
		{
			d[i][2] = d[i - 2][1] + d[i - 2][3];
			if (i == 2)
			{
				d[i][2] = 1;
			}
		}
		if (i >= 3)
		{
			d[i][3] = d[i - 3][1] + d[i - 3][2];
			if (i == 3)
			{
				d[i][3] = 1;
			}
		}
		d[i][1] %= output;
		d[i][2] %= output;
		d[i][3] %= output;
	}
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		cout << (d[n][1] + d[n][2] + d[n][3])% output <<"\n";
	}

	


	return 0;
}

//Bottom-up
//1. 문제를 크기가 작은 문제부터 차례대로 푼다.
//2. 문제의 크기를 조금씩 크게 만들면서 문제를 점점 푼다.
//3. 작은 문제를 풀면서 왔기 때문에, 큰 문제는 항상 풀 수 있다.
//4. 반복하다 보면 가장 큰 문제를 풀 수 있다.