#define _CRT_SECURE_NO_WARNINGS

// SWEA ver. with adjacency matrix representation
#include <stdio.h>
//#define MAX_VERTEX 30
int num;	// ������ ����
int map[30][30];
bool visit[30];
int queue[30];
int rear, front;	// pointer for queue

void breathFirstSearch(int vertex)
{
	visit[vertex] = true;	// �ϴ� �湮�ߴٰ� ������
	printf("%d ", vertex);	// ��µ� ���ش�
	queue[rear++] = vertex;	// ť�� �־��ش�
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
				// vertex �� ������ ������ �߿� �湮�� �����°� ���� ť�� �־�
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
	//} // �ʱ�ȭ ����
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



