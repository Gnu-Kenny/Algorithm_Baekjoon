//11052번 문제	<Bottom-up>
//카드 팩의 가격이 주어졌을 때, N개의 카드를 구매하기 위해 민규가 
//지불해야 하는 금액의 최댓값을 구하는 프로그램을 작성하시오. 
//구매한 카드팩에 포함되어 있는 카드 개수의 합은 N과 같아야 한다. 
//첫째 줄 입력: 구매하려고 하는 카드 개수 N / 둘째 줄 입력: Pi가 P1~Pn까지 주어진다.
#include <iostream>
#include <algorithm>
using namespace std;
int card_Price[10000]; //P1~Pn
int d[10000];	//카드 구매하는 최대 비용

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int card_Num;

	cin >> card_Num;	//구매하려고 하는 카드 개수 N
	
	for (int i=1; i <= card_Num; i++)	//P1~Pi 카드팩 가격 입력
	{
		cin >> card_Price[i];
	}

	//카드 구매하는 최대 비용 d[n] = d[n-i]+P[i]
	for (int i = 1; i <= card_Num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			d[i] = max(d[i], d[i-j] + card_Price[j]);
		}
	}
	
	cout << d[card_Num];
	return 0;
}

//Bottom-up
//1. 문제를 크기가 작은 문제부터 차례대로 푼다.
//2. 문제의 크기를 조금씩 크게 만들면서 문제를 점점 푼다.
//3. 작은 문제를 풀면서 왔기 때문에, 큰 문제는 항상 풀 수 있다.
//4. 반복하다 보면 가장 큰 문제를 풀 수 있다.