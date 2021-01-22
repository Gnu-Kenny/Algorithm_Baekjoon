//10844번 문제
//N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)
//입력 : 첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.
//출력 : 첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

#include <iostream>
#define mod 1000000000 //출력시 나머지 값 계산을 위한 상수

using namespace std;
long long d[100000][10];	//d[i][j] => 길이가 i인 정수 중 계단 수의 개수를 저장 j는 i번째 자리의 수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int numLength;	//정수의 길이
	long long answer = 0;

	cin >> numLength;	//정수의 길이 입력
	//점화식으로 저장될 수 없는 최소 연산 값
	for (int i = 1; i <= 9; i++)
		d[1][i] = 1;
	//d[i][j] = d[i-1][j-1] + d[i-1][j+1]	=> i자리 수의 마지막 수 j 앞의 수는 j-1 이거나 j+1 이다.
	for (int i = 2; i <= numLength; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			d[i][j] = 0;	//초기화
			if (j - 1 >= 0)		// 각 자리수는 일의 자리 수 범위에 존재해야 한다.
				d[i][j] += d[i - 1][j - 1];		
			if (j + 1 <= 9)
				d[i][j] += d[i - 1][j + 1];
			d[i][j] %= mod;
		}
	}
	
	for (int i = 0; i <= 9; i++)
	{
		answer += d[numLength][i];
	}
	cout << answer % mod;

	return 0;
}

//Bottom-up
//1. 문제를 크기가 작은 문제부터 차례대로 푼다.
//2. 문제의 크기를 조금씩 크게 만들면서 문제를 점점 푼다.
//3. 작은 문제를 풀면서 왔기 때문에, 큰 문제는 항상 풀 수 있다.
//4. 반복하다 보면 가장 큰 문제를 풀 수 있다.