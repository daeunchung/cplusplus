#include <iostream>
#include <queue>
using namespace std;
//const int MAX = 200000;	// ���ش��� �̷��� ��µ� ������ �˰����
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
* bfs �� �׷����� ����, ���� �ʿ�
* now, now-1, now+1, now*2 �� ���� ��ġ�� ����
* �̵��ϴµ� �ɸ��� �ð��� ���� 1�� ������ �ð��� �ǹ��ϸ� ����ġ�� ���� 1�̴�
* 
now -> next �� ������
if(check[next] == false)
{
	q.push(next);
	check[next] = true;
	dist[next] = dist[now] + 1;
}
*/