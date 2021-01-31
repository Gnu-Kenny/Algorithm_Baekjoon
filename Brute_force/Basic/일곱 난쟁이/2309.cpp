//2309번 [브루트 포스]
//뛰어난 수학적 직관력을 가지고 있던 백설공주는, 다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 기억해 냈다.
//아홉 개의 줄에 걸쳐 난쟁이들의 키가 주어진다.주어지는 키는 100을 넘지 않는 자연수이며, 
//아홉 난쟁이의 키는 모두 다르며, 가능한 정답이 여러 가지인 경우에는 아무거나 출력한다.
//일곱 난쟁이의 키를 오름차순으로 출력한다.일곱 난쟁이를 찾을 수 없는 경우는 없다.
#include <iostream>	
#include <algorithm>
using namespace std;
int hobbit[9];	//hobbit[i]일때 i번째 난쟁이 키
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	

	int sum = 0;	//9명의 난쟁이 키 합
	/*hobbit 초기화*/
	for (int i = 0; i < 9; i++)
	{
		cin >> hobbit[i];	//i번째 난쟁이 키 입력
		/*예외처리*/
		if (hobbit[i] > 0 && hobbit[i] <= 100)	// 0< 난쟁이의 키 <=100 일때만 저장
		{
			for (int j = 0; j < i; j++)	//이전의 난쟁이 키와 같은 값이 들어오면 재 입력
			{
				if (hobbit[i] == hobbit[j])
				{
					i--;
					break;
				}
			}
		}
		else
			i--;

		sum += hobbit[i];	//9명의 난쟁이 키 합에 값 합침
	}
	int flag = 0;	//해당 조건 충족시 첫번째 for문을 탈출하기 위한 flag 변수
	/*sum - hobbit[i] - hobbit[j] == 100*/
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (sum - hobbit[i] - hobbit[j] == 100)
			{
				/*제외 대상에 예외의 값 입력 -> 정렬시 출력 범위에서 제외시키기 위함*/
				hobbit[i] = 101;
				hobbit[j] = 101;
				sort(hobbit, hobbit + 9);
				flag = 1;
				break;
			}
			
		}
		if (flag)
			break;
	}

	for (int i = 0; i < 7; i++)
		cout << hobbit[i] << '\n';
	
	return 0;
}

