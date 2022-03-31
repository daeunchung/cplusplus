/* �� ������Ʈ DFS          �л��� �� (2 �� n �� 100,000)

��� �л��� ���� dfs�� ������ ����Ŭ�� �ϼ��� �л��� dfs�� ���� �ʾҴ�.
O(N ^ 2)�� �ð� ���⵵�� �ƹ��� ����ȭ�ص� 82�ۿ��� �ð� �ʰ�

���� �ذῡ �ʿ��� Ǯ�� : 
���� 1�� �л��� dfs���� ��, 3�� �л��� 5�� �л��� �湮�ߴٸ�, 
3�� �л��� 5�� �л��� dfs�� ���� �ʴ� Ǯ��
��� �л��� ���� �� ������ �湮�ϹǷ� O(N)�� �ð� ���⵵
*/

#include <bits/stdc++.h>
using namespace std;

int T, n, scnt;
int with[100001];		// i -- choose---> with[i]
bool visited[100001];
bool inTeam[100001];
int cnt;

//void dfs(int i)	// �ð� �ʰ� �Լ�
//{
//	visited[i] = true;
//
//	if (with[i] == i) {
//		inTeam[i] = true;
//		return;
//	}
//	else if (!visited[with[i]] && inTeam[with[i]]) {
//		return;
//	}
//	else if (!visited[with[i]] && !inTeam[with[i]]) {
//		visited[with[i]] = true;
//		return dfs(with[i]);
//	}
//	else if (visited[with[i]] && !inTeam[with[i]]) {
//		for (int k = 1; k <= n; k++) {
//			if (visited[k])
//				inTeam[k] = true;
//		}
//	}
//}

void dfs(int i)
{
	visited[i] = true;
	if (!visited[with[i]]) {
		dfs(with[i]);
	}
	else
	{
		if (!inTeam[with[i]]) {
			// �������� cycle �� ���� ��θӸ��� ã�� �� ���� �Ž��� �ö󰡴� ��
			for (int k = with[i]; k != i; k = with[k]) {
				cnt++;
			}
			cnt++;
		}
	}
	inTeam[i] = true;
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> T;
	while (T--) {
		memset(inTeam, 0, sizeof(inTeam));
		memset(visited, 0, sizeof(visited));

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> with[i];
		}
		//for (int i = 1; i <= n; i++) {
		//	if (!inTeam[i]) {
		//		memset(visited, 0, sizeof(visited));		// ���� �ð��ʰ� �ڵ� �� �־��� �κ�
		//		dfs(i);
		//	}
		//}
		//int cnt = 0;
		//for (int i = 1; i <= n; i++) {
		//	if (!inTeam[i]) cnt++;
		//}
		//cout << cnt << '\n';

		cnt = 0;
		for (int i = 1; i <= n; i++) {
			// ���� �湮���� ���� ���
			if (!visited[i]) {
				dfs(i);
			}
		}
		cout << n - cnt << "\n";
	}
	return 0;
}