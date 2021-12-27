/* 플로이드 와샬 : 거쳐가는 정점 k 을 기준으로 알고리즘을 수행 */

#include <iostream>
#include <vector>
using namespace std;
int arr[101][101];
int N, M, a, b, c;
int INF = 100000000; // 작게 잡아주면 하나의 거리에 최대 10만의 값이 나올 수 있기 때문에 틀렸습니다

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			arr[i][j] = INF;

	for (int i = 1; i <= M; i++)
	{
		cin >> a >> b >> c;
		if (!arr[a][b])
			arr[b][c] = c;
		else //이미 경로가 있는 경우 최소값 선택
			arr[a][b] = min(arr[a][b], c);
	}

	for (int i = 1; i <= N; i++) arr[i][i] = 0;

	// 플로이드 와샬
	for (int k = 1; k <= N; k++) // 거쳐가는 노드
	{
		for (int i = 1; i <= N; i++) // 출발하는 노드
		{
			for (int j = 1; j <= N; j++) // 도착하는 노드
			{
				if (arr[i][k] == 0 || arr[k][j] == 0 || i == j)
					continue;
				if (arr[i][j] == 0 || arr[i][k] + arr[k][j] < arr[i][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == INF) cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}