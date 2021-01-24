//11053번 <Bottom-up> <LIS : Longest Increasing Subsequence>
//수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
//예를 들어, 수열 A = { 10, 20, 10, 30, 20, 50 } 인 경우에 가장 긴 증가하는 부분 수열은 A = { 10, 20, 10, 30, 20, 50 } 이고, 길이는 4이다.
//입력
//첫째 줄에 수열 A의 크기 N(1 ≤ N ≤ 1, 000)이 주어진다.
//둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1, 000)
//출력
//첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
#include <iostream>
#include <algorithm>
using namespace std;
int squence[1001];	// 수열 초기화	
int d[1001];		// d[i] => 길이가 i인 수열 중 가장 긴 증가하는 부분 수열의 길이
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int squenceLength;	// 수열의 길이 저장 변수
	int length=0;	//d[1]~d[i] 중 가장 길이가 긴 경우를 비교하여 저장하기 위한 변수.

	cin >> squenceLength;		//수열 길이 입력

	for (int i = 1; i <= squenceLength; i++)
	{
		cin >> squence[i];		//
	}
	for (int i = 1; i <= squenceLength; i++)
	{
		d[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (squence[j] < squence[i] && d[i] < d[j] + 1) //1,2, ... j, i .. i가 바로 이전의 수 j보다 크고, d[i]를 d[1]~d[j]까지 수로 비교해서 d[i]가 작다면
			{
				d[i] = d[j] + 1;
			}
			
		}
		length = max(length, d[i]);
	}

	cout << length;

	return 0;
}

//LIS (Longest Increasing Subsquence)
//Bottom-up