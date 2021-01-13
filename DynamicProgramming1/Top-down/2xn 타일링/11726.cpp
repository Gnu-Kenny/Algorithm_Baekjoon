//11726�� ���� <Top-down ���>
//2��n ũ���� ���簢���� 1��2, 2��1 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
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
	
	d[1] = 1;		//��ȭ�Ŀ� ���Ե��� �ʴ� �ּ��� ���
	d[2] = 2;		//��ȭ�Ŀ� ���Ե��� �ʴ� �ּ��� ���
	
	if (d[n] > 0)	//�޸������̼� : ������ ���� ������ ������
		return d[n];
	d[n] = makesquare(n - 1) + makesquare(n - 2);	//d[n-1] -> 2x1 Ÿ���� ���� ���̴� ��� d[n-2] -> 2x2 Ÿ���� �ΰ� ���̴� ���
	
	return d[n] % 10007;		
}

/*
*ž �ٿ� ���
 1. ū ������ ���� ������ ������.
 2. ���� ������ Ǭ��.
 3. ���� ������ Ǯ������, ���� ū ������ Ǭ��.
*/