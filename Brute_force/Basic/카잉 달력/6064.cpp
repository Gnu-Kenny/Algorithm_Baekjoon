//6064번 [브루트 포스]

#include <iostream>

using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		int M, N, x, y;	//<M:N>은 마지막 해 , <x:y> 년도로 계산하고 싶은 해
		cin >> M >> N >> x >> y;
		x -= 1;		//나머지 연산을 위해 -1
		y -= 1;
		bool flag = false; //<x:y>의 유효성을 나타내는 플래그 변수
		//<M,N>일때 <x,y> = <i%M,i%N>
		for (int j = x; j < (M * N); j += M)	//j+M -> 앞자리 수 나머지 값 고정
		{
			if (j % N == y)
			{
				cout << j + 1 << '\n';
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << -1 << '\n';
	}

	return 0;
}