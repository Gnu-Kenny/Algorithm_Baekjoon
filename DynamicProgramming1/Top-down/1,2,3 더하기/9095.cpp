//9095번 문제 <Top-down 방식>
//정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.
#include <iostream>

using namespace std;
int add(int n);
int d[10000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int testCase, input;
	cin >> testCase;	//테스트 케이스의 갯수
	for(int i=0;i<testCase;i++)		//입력 받은 테스트 갯수 만큼 반복
	{
		cin >> input;		// 정수 입력
		if (input > 0 && input < 11)
			cout << add(input) << "\n";		//1,2,3의 합으로 나타내는 방법의 갯수 출력 (1+2, 2+1은 다른 방법으로 취급)
		else	//예외 처리
			i--;
	}

	return 0;
}

int add(int n)
{
	d[1] = 1;	//점화식 표현을 위한 최소값
	d[2] = 2;	//점화식 표현을 위한 최소값
	d[3] = 4;	//점화식 표현을 위한 최소값
	if (d[n] > 0)		//메모이제이션
		return d[n];
	d[n] = add(n - 1) + add(n - 2) + add(n - 3);	//+1로 만드는 방법의수/ +2로 만드는 방법의수/ +3로 만드는 방법의수

	return d[n];
}

//탑 다운 방식
//1. 큰 문제를 작은 문제로 나눈다.
//2. 작은 문제를 푼다.
//3. 작은 문제를 풀었으니, 큰 문제를 푼다.
