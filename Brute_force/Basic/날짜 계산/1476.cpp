//1476번 [브루트 포스]
//지구를 나타내는 수를 E, 태양을 나타내는 수를 S, 달을 나타내는 수를 M이라고 했을 때,
//이 세 수는 서로 다른 범위를 가진다. (1 ≤ E ≤ 15, 1 ≤ S ≤ 28, 1 ≤ M ≤ 19)
//우리가 알고있는 1년은 준규가 살고있는 나라에서는 1 1 1로 나타낼 수 있다.
//1년이 지날 때마다, 세 수는 모두 1씩 증가한다.만약, 어떤 수가 범위를 넘어가는 경우에는 1이 된다.
//E, S, M이 주어졌고, 1년이 준규가 사는 나라에서 1 1 1일때, 
//준규가 사는 나라에서 E S M이 우리가 알고 있는 연도로 몇 년인지 구하는 프로그램을 작성하시오.
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int ESM[3];		//E S M 값 저장할 변수
	int ESM_ans[3]; //ESM와 비교할 변수
	int Year = 0;	//연도를 나타내는 변수
	
	//E, S, M 값 입력
	for (int i = 0; i < 3; i++)
	{
		cin >> ESM[i];
		ESM_ans[i] = 0;
	}
	//E, S, M 각각 1년씩 증가하면서 입력된 값과 비교
	while (1)
	{
		for (int i = 0; i < 3; i++)
		{
			ESM_ans[i]++;
			if (i == 0 && ESM_ans[i] > 15)
				ESM_ans[0] = 1;
			if (i == 1 && ESM_ans[i] > 28)
				ESM_ans[1] = 1;
			if (i == 2 && ESM_ans[i] > 19)
				ESM_ans[2] = 1;
		}
		Year++;
		//조건 성립시 while문 탈출
		if (ESM[0] == ESM_ans[0] && ESM[1] == ESM_ans[1] && ESM[2] == ESM_ans[2])
			break;
	}
	
	cout << Year;


	return 0;
}