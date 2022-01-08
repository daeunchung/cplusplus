// ��������
// ���ӵ� ������ �κ��� �߿� �� ���� S �̻��� �Ǵ� �� ��, ���� ª�� ���� ���̸� ���ϴ� ���α׷�
// ����� �ڵ� (left<right ������ ���� �������� �ʴ�)
// �����غ��� �κ����� �׻� S�̻��� �����Ϸ��� ���������� left�� right�� �����Ǵ� ���� ������(?)
// => �찭 �ٽ� ���ƾ��ҵ�

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int Data[MAXN + 1];
int main()
{
	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> Data[i];

	int left = 0, right = 0, sum = 0, ans = N + 1;	// ans�� �ʱⰪ�� �ִ�� ��´�
	while (true)
	{
		if (sum >= S)
		{
			ans = min(ans, right - left);
			sum -= Data[left++];
		}
		else if (right == N) break;	// ���� ����
		else
		{
			sum += Data[right++];
		}
	}
	// ���� �׷��� ���� ����� ���� �Ұ����ϴٸ� 0�� ���
	// Data[0] ~ Data[N-1} �� ���ص� sum < S �̸� �׷��� �κ��� ����Ⱑ �Ұ����� ��
	// if(sum>=S) �� �������� ���Ͽ� ans�� �ʱⰪ N+1 �״�� �� ��
	if (ans == N + 1) 
		cout << 0 << '\n';
	else 
		cout << ans << '\n';
}