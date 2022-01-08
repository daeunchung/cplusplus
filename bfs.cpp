#define _CRT_SECURE_NO_WARNINGS

// SWEA ver. with adjacency matrix representation
#include <stdio.h>
//#define MAX_VERTEX 30
int num;	// 정점의 개수
int map[30][30];
bool visit[30];
int queue[30];
int rear, front;	// pointer for queue

void breathFirstSearch(int vertex)
{
	visit[vertex] = true;	// 일단 방문했다고 찍어놓고
	printf("%d ", vertex);	// 출력도 해준다
	queue[rear++] = vertex;	// 큐에 넣어준다
	while (front < rear)
	{
		vertex = queue[front++];	
		for (int i = 1; i <= num; i++)
		{
			if (map[vertex][i] == 1 && !visit[i])
			{
				visit[i] = true;
				printf("%d ", i);
				queue[rear++] = i;
				// vertex 랑 인접한 정점들 중에 방문한 적없는건 전부 큐에 넣어
			}
		}
	}
}

int main()
{
	freopen("bfs_in.txt", "r", stdin);
	int v1, v2;
	int start;	// vertex starting traverse
	//for (int i = 0; i < 30; i++)
	//{
	//	for (int j = 0; j < 30; j++)
	//	{
	//		map[i][j] = 0;
	//	}
	//	visit[i] = 0;	queue[i] = 0;
	//} // 초기화 과정
	front = 0;
	rear = 0;
	scanf("%d %d", &num, &start);

	while (true)
	{
		scanf("%d %d", &v1, &v2);
		if (v1 == -1 && v2 == -1) break;
		map[v1][v2] = map[v2][v1] = 1;	// filling up the adjacency matrix
	}
	breathFirstSearch(start);
	printf("\n");
}



