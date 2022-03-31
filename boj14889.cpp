// dfs 로 중복없는 조합 
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
// idx번 선수를 스타트 팀으로 뽑는다, cnt : 뽑은 명수
void dfs(int idx, int cnt)
{
	// 조건만족시 return 시키는 if문
	if (cnt == n / 2)
	{
		vector<int> start, link;
		// team[]  : 1이면 start, 0이면 link
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
			for (int j = i + 1; j < start.size(); j++)	// ** 이중for문 조건이 어렵
			{
				start_s += a[start[i]][start[j]] + a[start[j]][start[i]];
				link_s += a[link[i]][link[j]] + a[link[j]][link[i]];
			}
		}
		int tmp = abs(start_s - link_s);
		if (ans > tmp) ans = tmp;
		return;
	}

	// 완전탐색
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
// for문이 n까지 돌때

// https://kyunstudio.tistory.com/235
// https://wjdgus2951.tistory.com/82
// for 문이 n/2 까지 돌때
// 
// 이해가 잘 안됌 . 나는 백트래킹을 제일 못하는듯
// 링크의 코드들 꼭 다시한번 보기

// https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-14889-%EC%8A%A4%ED%83%80%ED%8A%B8%EC%99%80-%EB%A7%81%ED%81%AC
// 1.재귀 2.순열 3.비트마스크로 구현하신 블로그