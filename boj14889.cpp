// dfs �� �ߺ����� ���� 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define INF 2147480000
int n;
bool team[21];
int a[21][21];
int ans = INF;
// idx�� ������ ��ŸƮ ������ �̴´�, cnt : ���� ���
void dfs(int idx, int cnt)
{
	// ���Ǹ����� return ��Ű�� if��
	if (cnt == n / 2)
	{
		vector<int> start, link;
		// team[]  : 1�̸� start, 0�̸� link
		for (int i = 0; i < n; i++)
		{
			if (team[i]) 
				start.push_back(i);
			else 
				link.push_back(i);
		}
		int start_s = 0, link_s = 0;
		for (int i = 0; i < start.size(); i++)
		{
			for (int j = i + 1; j < start.size(); j++)	// ** ����for�� ������ ���
			{
				start_s += a[start[i]][start[j]] + a[start[j]][start[i]];
				link_s += a[link[i]][link[j]] + a[link[j]][link[i]];
			}
		}
		int tmp = abs(start_s - link_s);
		if (ans > tmp) ans = tmp;
		return;
	}

	// ����Ž��
	for (int i = idx + 1; i < n; i++)
	{
		if (!team[i]) {
			team[i] = true;
			dfs(i, cnt + 1);
			team[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	dfs(0, 0);
	cout << ans << '\n';
	return 0;
}

// https://ongveloper.tistory.com/309
// for���� n���� ����

// https://kyunstudio.tistory.com/235
// https://wjdgus2951.tistory.com/82
// for ���� n/2 ���� ����
// 
// ���ذ� �� �ȉ� . ���� ��Ʈ��ŷ�� ���� ���ϴµ�
// ��ũ�� �ڵ�� �� �ٽ��ѹ� ����

// https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-14889-%EC%8A%A4%ED%83%80%ED%8A%B8%EC%99%80-%EB%A7%81%ED%81%AC
// 1.��� 2.���� 3.��Ʈ����ũ�� �����Ͻ� ��α�