//1107번 [브루트 포스]
//리모컨에는 버튼이 0부터 9까지 숫자, +와 - 가 있다. + 를 누르면 현재 보고있는 채널에서 + 1된 채널로 이동하고,
//-를 누르면 - 1된 채널로 이동한다.채널 0에서 - 를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.
//지금 이동하려고 하는 채널은 N이다.어떤 버튼이 고장났는지 주어졌을 때, 채널 N으로 이동하기 위해서
//버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오.
//지금 보고 있는 채널은 100번이다.
#include <iostream>
using namespace std;
int possible(int c);
bool brokenButton[10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;	//이동하려는 채널
	int brokenNum;	//고장난 버튼의 개수
	cin >> N;	//채널 입력
	cin >> brokenNum;	//고장난 버튼의 개수 출력
	/*고장난 버튼의 해당 인덱스에 true 입력*/
	for (int i = 0; i < brokenNum; i++)
	{
		int x;
		cin >> x;
		brokenButton[x] = true;
	}
	int ans = N - 100;
	if (ans < 0)
		ans = -ans;
	for (int i=0; i <= 1000000; i++)
	{
		int c = i;
		int len = possible(c);
		if (len > 0)
		{
			int press;
			press = c - N;
			if (press < 0)
				press = -press;
			if (ans > len + press)
				ans = len + press;
		}
		
	}
	cout << ans;
	return 0;
}

int possible(int c)
{
	if (c == 0)
	{
		if (brokenButton[0])
			return 0;
		else
			return 1;
	}
	int len = 0;
	while (c > 0) {
		if (brokenButton[c % 10])
			return 0;
		len += 1;
		c /= 10;
	}
	return len;
}