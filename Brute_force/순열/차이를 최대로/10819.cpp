//10819번 [브루트포스] <순열>
//N개의 정수로 이루어진 배열 A가 주어진다. 이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 
//다음 식의 최댓값을 구하는 프로그램을 작성하시오.
//|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|
//첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다. 둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 
//첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다.
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int sequence[8];	//입력 받을 배열
int calculate(int* sequence, int n);	//배열의 각 차이의 합을 반환하는 함수
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;	//배열의 길이 저장할 변수
	cin >> n;	//배열의 길이 값 저장
	/*배열 초기화*/
	for (int i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}
	/*모든 경우의 수를 고려하기 위해 배열을 오름차순 정렬*/
	sort(sequence, sequence + n);

	int ans=0;	//차이의 최대값을 저장할 변수
	do {
		int temp = calculate(sequence,n);	//임시로 배열의 각 차이의 합을 저장할 변수
		ans = max(ans, temp);		// 현재값과 비교하여 더 큰 수를 저장
	} while (next_permutation(sequence, sequence + n));	//다음 배열이 존재한다면 다음 배열로 정렬하고 true값을 반환하는 함수

	cout << ans;	//차이의 최대 값 출력
	return 0;
}

int calculate(int* sequence,int n)
{
	int sumOfDifference = 0;	//차이의 합을 저장할 변수
	for (int i = 0; i+1 < n; i++)
	{
		int difference = 0;
		if ((sequence[i] - sequence[i + 1]) < 0)	//차이가 음수라면
			difference = -(sequence[i] - sequence[i + 1]);
		else  //차이가 양수라면
			difference = sequence[i] - sequence[i + 1];
		sumOfDifference += difference;
	}
	return sumOfDifference;
}