/* BackTracking ����		{1, 2, 3} == {2, 1, 3}
�����̱⿡ idx �������� �ݺ��� ��ȸ�ϸ� �ȵȴ�. idx ������ �ʿ�O . dfs �Ű����� cnt, idx �� �ΰ� 
ex) idx �� 2�̸� 234, 235, 245 ó�� idx ���� ���� ��ȸ �����ϵ��� �����. idx ������ 1�� ��ȸX */

#include <iostream>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };	// [0]������

void dfs(int idx, int cnt)
{
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = idx; i <= n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;
			dfs(i + 1, cnt + 1);	// dfs(x)�� �������϶� cnt�� x-1���� ��������
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(1, 0);
}