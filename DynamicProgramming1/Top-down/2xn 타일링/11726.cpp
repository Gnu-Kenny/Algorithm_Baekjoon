//11726번 문제 <Top-down 방식>
//2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
#include <iostream>

using namespace std;
int makesquare(int n);
int d[1000];		//1<=n<=1000
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	
	cin >> n;
	cout << makesquare(n);

	return 0;
}

int makesquare(int n)
{
	
	d[1] = 1;		//점화식에 포함되지 않는 최소의 경우
	d[2] = 2;		//점화식에 포함되지 않는 최소의 경우
	
	if (d[n] > 0)	//메모이제이션 : 이전에 구한 값들을 저장함
		return d[n];
	d[n] = makesquare(n - 1) + makesquare(n - 2);	//d[n-1] -> 2x1 타일을 끝에 붙이는 경우 d[n-2] -> 2x2 타일을 두개 붙이는 경우
	
	return d[n] % 10007;		
}

/*
*탑 다운 방식
 1. 큰 문제를 작은 문제로 나눈다.
 2. 작은 문제를 푼다.
 3. 작은 문제를 풀었으니, 이제 큰 문제를 푼다.
*/