//1107�� [���Ʈ ����]
//���������� ��ư�� 0���� 9���� ����, +�� - �� �ִ�. + �� ������ ���� �����ִ� ä�ο��� + 1�� ä�η� �̵��ϰ�,
//-�� ������ - 1�� ä�η� �̵��Ѵ�.ä�� 0���� - �� ���� ��쿡�� ä���� ������ �ʰ�, ä���� ���Ѵ� ��ŭ �ִ�.
//���� �̵��Ϸ��� �ϴ� ä���� N�̴�.� ��ư�� ���峵���� �־����� ��, ä�� N���� �̵��ϱ� ���ؼ�
//��ư�� �ּ� �� �� �������ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//���� ���� �ִ� ä���� 100���̴�.
#include <iostream>
using namespace std;
int possible(int c);
bool brokenButton[10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;	//�̵��Ϸ��� ä��
	int brokenNum;	//���峭 ��ư�� ����
	cin >> N;	//ä�� �Է�
	cin >> brokenNum;	//���峭 ��ư�� ���� ���
	/*���峭 ��ư�� �ش� �ε����� true �Է�*/
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