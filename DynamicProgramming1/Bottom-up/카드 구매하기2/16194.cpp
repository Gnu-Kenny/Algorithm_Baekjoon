// 16194번 문제 <Bottom-up>
//카드 팩의 가격이 주어졌을 때, N개의 카드를 구매하기 위해
//지불해야 하는 금액의 최솟값을 구하는 프로그램을 작성하시오. 
//첫째 줄에 민규가 구매하려고 하는 카드의 개수 N이 주어진다. (1 ≤ N ≤ 1,000)
//둘째 줄에는 Pi가 P1부터 PN까지 순서대로 주어진다.(i는 카드팩에 들어있는 카드 수) (1 ≤ Pi ≤ 10,000)
#include <iostream>
#include <algorithm>

using namespace std;
int min_Price[10000];	//지불해야 하는 금액의 최솟값
int cardpack_Price[10000];	//P1~Pi까지 카드팩의 가격 (1 ≤ Pi ≤ 10,000)
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int card_Num;

	cin >> card_Num;	//구매하려는 카드의 갯수

	for (int i = 1; i <= card_Num; i++)
	{
		cin >> cardpack_Price[i];		//카드 팩의 가격 할당
		min_Price[i] = cardpack_Price[i];	//min 함수를 쓰기 위해 P1~Pi의 가격 초기화
	}
	/*min_Price[N]=min_Price[N-i]+cardpack_price[i]*/
	for (int i = 1; i <= card_Num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			min_Price[i] = min(min_Price[i], min_Price[i - j] + cardpack_Price[j]);	//min_Price[i]에 들어갈수있는 모든 경우의 수를 비교하여 최소값 저장
		}
	}
	
	cout << min_Price[card_Num]; //카드 N개를 살 수 있는 최소 금액 출력

	return 0;
}

//Bottom-up
//1. 문제를 크기가 작은 문제부터 차례대로 푼다.
//2. 문제의 크기를 조금씩 크게 만들면서 문제를 점점 푼다.
//3. 작은 문제를 풀면서 왔기 때문에, 큰 문제는 항상 풀 수 있다.
//4. 반복하다 보면 가장 큰 문제를 풀 수 있다.