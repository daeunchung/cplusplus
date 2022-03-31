// dfs OR bfs + ��������
// �������ͷ� ���� minV, maxV ��� dfs������ ������������ �ɾ���� dfs �� ���鼭 �������� �������ϸ� �糢�� ������

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int N, startX, startY, cnt = 0, HouseCnt = 0, maxHouse = -1, minHouse = 1000000, maxHIdx, minHIdx;
char Map[51][51];
int MapV[51][51];
bool V[51][51];	// 0 (false) �� �ʱ�ȭ
int Data[51 * 51];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
void dfs(int x, int y, int& minV, int& maxV, int& visitHcnt)
{
	// ���� ���̰ų� �̹� �湮������ dfs Ż�� (Ż�������� ���� ���� ����)
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

	// ��� ĭ�� ���� �����ϴ� Data �迭�� �����Ͽ� �ߺ��� ����
	sort(Data, Data + cnt);
	int uniqueCnt = 1;
	for (int i = 1; i < cnt; i++) {
		if (Data[i - 1] != Data[i]) Data[uniqueCnt++] = Data[i];
	}
	for (int i = 0; i < uniqueCnt; i++) {
		if (Data[i] == maxHouse) maxHIdx = i;
		if (Data[i] == minHouse) minHIdx = i;
	}
	// ������ �����ϰ� ���� Data[]�� 
	// .���ּҰ� ~ minHouse(minHIdx) ~ maxHouse(maxHIdx) ~ .���ִ밪 
	// ���°� �ȴ�. ���� �������� ����
	//for (int i = 0; i <= minHIdx; i++) {
	//	for (int j = maxHIdx; j < uniqueCnt; j++) {
	//		if (canGo(Data[i], Data[j])) {
	//			ans = min(Data[j] - Data[i], ans);
	//		}
	//	}
	//}
	int minIdx = 0, maxIdx = maxHIdx;//maxIdx ��ü��/�� �ִ���� Idx���� �۾��� �� ����.
	int ans = 1000000;
	while (maxIdx < uniqueCnt)
	{
		while (minIdx <= minHIdx)
		{
			if (!canGo(Data[minIdx], Data[maxIdx])) break;
			ans = min(ans, Data[maxIdx] - Data[minIdx]);
			//�����ϸ� minIdx�� ���� ������ ������.
			minIdx++;
		}
		//������ �� ������ maxIdx�� ���� ������ �ø���.
		maxIdx++;
	}
	cout << ans << '\n';
	return 0;
}