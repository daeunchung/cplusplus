#include <iostream>
#include <queue>
using namespace std;
//const int MAX = 200000;	// 백준님은 이렇게 잡는데 이유를 알고싶음
const int MAX = 100000;
bool check[MAX + 1];
int dist[MAX + 1];

int main()
{
	int N, K;
	cin >> N >> K;
	check[N] = true;
	dist[N] = 0;
	queue<int> q;
	q.push(N);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now - 1 >= 0)
		{
			if (!check[now - 1])
			{
				q.push(now - 1);
				check[now - 1] = true;
				dist[now - 1] = dist[now] + 1;
			}
		}
		if (now + 1 < MAX+1)
		{
			if (!check[now + 1])
			{
				q.push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
			}
		}
		if (now * 2 < MAX + 1)
		{
			if (!check[now * 2])
			{
				q.push(now * 2);
				check[now * 2] = true;
				dist[now * 2] = dist[now] + 1;
			}
		}
	}
	cout << dist[K] << '\n';
	return 0;
}

/*
* bfs 는 그래프라서 정점, 간선 필요
* now, now-1, now+1, now*2 와 같은 위치가 정점
* 이동하는데 걸리는 시간은 전부 1로 간선은 시간을 의미하며 가중치는 전부 1이다
* 
now -> next 로 가려면
if(check[next] == false)
{
	q.push(next);
	check[next] = true;
	dist[next] = dist[now] + 1;
}
*/