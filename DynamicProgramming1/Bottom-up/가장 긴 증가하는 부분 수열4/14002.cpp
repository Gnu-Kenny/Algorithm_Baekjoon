//14002��, <bottom-up> <Top-down> <������>
//���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
//���� ���, ���� A = {10, 20, 10, 30, 20, 50} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {10, 20, 10, 30, 20, 50} �̰�, ���̴� 4�̴�.
//ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.
//��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1, 000)
//ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.
//��° �ٿ��� ���� �� �����ϴ� �κ� ������ ����Ѵ�.�׷��� ������ ���������� ��� �ƹ��ų� ����Ѵ�.
#include <iostream>
#include <algorithm>
using namespace std;
void go(int p);
int d[1001];	// d[i] => ������ ���̰� i�϶�, ���� �� �����ϴ� �κ� ������ ����
int sequence[1001];	//���� �ʱ�ȭ
int v[1001];		//v[i] sequence[i] �տ� �;��ϴ� ���� �ε��� -> �������� ���� ������ ������ ���������� ����
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int sequenceLength;
	int maxLength=0;

	cin >> sequenceLength;		//���� ���� �Է�

	//���� �ʱ�ȭ
	for (int i = 1; i <= sequenceLength; i++)	
	{
		cin >> sequence[i];
	}

	//d[i] = d[j] + 1 ���� �����ϴ� �κ� ������ ���̴� �� �������� �κ� ���� +1
	for (int i = 1; i <= sequenceLength; i++)
	{
		d[i] = 1;	//���� ������ ���� �ʱ�ȭ
		v[i] = 0;	//���� ������ ���� �ʱ�ȭ
		for (int j = 1; j < i; j++)
		{
			if (sequence[j] < sequence[i] && d[i] < d[j] + 1)	//������ �����ϴ� �����϶� ���̰� �ִ��� �κм��� ����
			{
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}

	int ans = d[0];
	int p = 0;	//�κ� ������ ���� ����
	for (int i = 1; i <= sequenceLength; i++) {
		if (ans < d[i]) {
			ans = d[i];
			p = i;
		}
	}
	cout << ans << '\n';
	go(p);
	return 0;
}

void go(int p)		//go(p) -> sequence[p]���� ���
{
	if (p == 0)
		return;
	go(v[p]);
	cout << sequence[p] << ' ';
}