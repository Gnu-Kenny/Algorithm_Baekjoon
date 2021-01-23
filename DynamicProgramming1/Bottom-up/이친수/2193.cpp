// 2193번 문제 <Bottom-up>
// N자리 이친수의 개수를 구하는 프로그램을 작성
//이친수는 특별한 성질을 가진 이진수이다.
//이친수는 0으로 시작하지 않는다.
//이친수에서는 1이 두 번 연속으로 나타나지 않는다.즉, 11을 부분 문자열로 갖지 않는다.
#include <iostream>

using namespace std;

long long d[91][2];	//d[i][j] => i자리의 이친수의 개수를 저장 / 마지막 자리의 수 j를 저장 (i>=1 && i<=90 j=0,1)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int B_length;	// 이친수의 길이 입력

	cin >> B_length;
	//점화식으로 연산되지 않는 최소값 초기화
	d[1][0] = 0;	
	d[1][1] = 1;
	//0으로 끝나는 경우 & 1로끝나는 경우
	for (int i = 2; i <= B_length; i++)
	{
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] += d[i - 1][0];
		
	}

	cout << (d[B_length][0] + d[B_length][1]);	// B_length자리 이친수 개수 출력

	return 0;
}

//Bottom-up
//1. 문제를 크기가 작은 문제부터 차례대로 푼다.
//2. 문제의 크기를 조금씩 크게 만들면서 문제를 점점 푼다.
//3. 작은 문제를 풀면서 왔기 때문에, 큰 문제는 항상 풀 수 있다.
//4. 반복하다 보면 가장 큰 문제를 풀 수 있다.