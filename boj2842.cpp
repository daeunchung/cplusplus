// dfs OR bfs + 투포인터
// 투포인터로 먼저 minV, maxV 골라서 dfs돌때의 제어조건으로 걸어놓고 dfs 를 돌면서 제어조건 만족안하면 재끼는 식으로

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N, startX, startY, cnt = 0, HouseCnt = 0, maxHouse = -1, minHouse = 1000000, maxHIdx, minHIdx;
char Map[51][51];
int MapV[51][51];
bool V[51][51];	// 0 (false) 로 초기화
int Data[51 * 51];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
void dfs(int x, int y, int& minV, int& maxV, int& visitHcnt)
{
	// 범위 밖이거나 이미 방문했으면 dfs 탈출 (탈출조건을 가장 위에 기재)
	if (x < 0 || x > N || y < 0 || y > N || V[x][y]
		|| MapV[x][y] < minV || MapV[x][y] >maxV) return;

	V[x][y] = true;
	if (Map[x][y] == 'K') visitHcnt++;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		dfs(nx, ny, minV, maxV, visitHcnt);
	}
	return;
}

bool canGo(int minV, int maxV)
{
	memset(V, 0, sizeof(V));

	int visitHcnt = 0;
	dfs(startX, startY, minV, maxV, visitHcnt);
	if (visitHcnt == HouseCnt) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Map[i][j];
			if (Map[i][j] == 'P') {
				startX = i;
				startY = j;
			}
			if (Map[i][j] == 'K') {
				HouseCnt++;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> MapV[i][j];
			Data[cnt++] = MapV[i][j];
			if (Map[i][j] == 'K' || Map[i][j] == 'P') {
				maxHouse = max(maxHouse, MapV[i][j]);
				minHouse = min(minHouse, MapV[i][j]);
			}
		}
	}

	// 모든 칸의 값을 저장하는 Data 배열을 정렬하여 중복값 제거
	sort(Data, Data + cnt);
	int uniqueCnt = 1;
	for (int i = 1; i < cnt; i++) {
		if (Data[i - 1] != Data[i]) Data[uniqueCnt++] = Data[i];
	}
	for (int i = 0; i < uniqueCnt; i++) {
		if (Data[i] == maxHouse) maxHIdx = i;
		if (Data[i] == minHouse) minHIdx = i;
	}
	// 위까지 수행하고 나면 Data[]는 
	// .중최소값 ~ minHouse(minHIdx) ~ maxHouse(maxHIdx) ~ .중최대값 
	// 상태가 된다. 이제 투포인터 ㄱㄱ
	//for (int i = 0; i <= minHIdx; i++) {
	//	for (int j = maxHIdx; j < uniqueCnt; j++) {
	//		if (canGo(Data[i], Data[j])) {
	//			ans = min(Data[j] - Data[i], ans);
	//		}
	//	}
	//}
	int minIdx = 0, maxIdx = maxHIdx;//maxIdx 우체국/집 최대높이 Idx보다 작아질 수 없다.
	int ans = 1000000;
	while (maxIdx < uniqueCnt)
	{
		while (minIdx <= minHIdx)
		{
			if (!canGo(Data[minIdx], Data[maxIdx])) break;
			ans = min(ans, Data[maxIdx] - Data[minIdx]);
			//만족하면 minIdx를 더해 범위를 좁힌다.
			minIdx++;
		}
		//만족할 수 없으면 maxIdx를 더해 범위를 늘린다.
		maxIdx++;
	}
	cout << ans << '\n';
	return 0;
}