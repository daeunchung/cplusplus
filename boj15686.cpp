// 치킨배달 - brute force N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
#define INF 2147480000
int map[51][51];
int cntH, cntCK, N, M; // 폐업시키지 않을 치킨집 M개
int ans = INF;
vector<pair<int, int> > H;
vector<pair<int, int> > CK;
vector<pair<int, int> > selectedCK;

// 강사님은 이렇게 setting
//struct stPos
//{
//	int r, c;
//};
//
//int N, M, Ans;
//int Top, HouseCnt, ChickenCnt;
//stPos House[2 * MAXN + 1];//집의 개수는 2N
//stPos Chicken[MAXM + 1];//치킨집
//int Selected[MAXM + 1];//선택된 치킨집의 index

void calc()
{
	int sum = 0;
	for (int i = 0; i < cntH; i++) {
		int dist = 0, minDist = INF;
		for (int j = 0; j < selectedCK.size(); j++) {
			dist = abs(H[i].first - selectedCK[j].first) + abs(H[i].second - selectedCK[j].second);
			minDist = min(dist, minDist);
		}
		sum += minDist;
	}
	ans = min(ans, sum);
}

// 조합 경우의 수 구하기
void backtrack(int start)
{
	// base condition
	if (selectedCK.size() == M) {
		calc();
		return;
	}

	// iteration
	for (int i = start; i < cntCK; i++) {
		if (cntCK - i < M - selectedCK.size()) break; // 가지치기 Pruning
		selectedCK.push_back(CK[i]);
		backtrack(i + 1);
		selectedCK.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				H.push_back(make_pair(i, j));
				cntH++;
			}
			else if (map[i][j] == 2) {
				CK.push_back(make_pair(i, j));
				cntCK++;
			}
		}
	}
	backtrack(0);
	cout << ans << '\n';
	return 0;
}