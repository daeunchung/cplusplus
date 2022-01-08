#define _CRT_SECURE_NO_WARNINGS
//��������Ʈ�� ��Ÿ������ �迭�̳� ���ͷ� ���� �ǰ� : swea  
//map<int, int> �� �����ȴ�. : �㽺���㽺

// swea dfs reference code down below (adjacent matrix)
// https://swexpertacademy.com/main/code/referenceCode/referenceCodeDetail.do?referenceId=DFS_SEARCHING&category=Algorithm&&
#include <stdio.h>
//#define MAX_VERTEX 30

int vertex; // ������ ����
int map[30][30];
bool visit[30];

void depthFirstSearch(int);

int main()
{
	freopen("dfs_in.txt", "r", stdin);
	int start;
	int v1, v2;

    //for (int i = 0; i < 30; i++)
    //{
    //    for (int j = 0; j < 30; j++)
    //    {
    //        map[i][j] = 0;
    //    }
    //    visit[i] = 0;
    //}
    scanf("%d %d", &vertex, &start);
    while (true)
    {
        scanf("%d %d", &v1, &v2);
        if (v1 == -1 && v2 == -1)
        {
            break;
        }
        map[v1][v2] = map[v2][v1] = 1;
        // if it were vector
        // a[v1].emplace_back(v2); or push_back();
        // a[v2].emplace_back(v1);
    }
    printf("%d ", start);
    depthFirstSearch(start);
    printf("\n");
    return 0;
}

void depthFirstSearch(int v) // swea (adjacent matrix version)
{
    visit[v] = true;
    for (int i = 1; i <= vertex; i++)
    {
        if (map[v][i] == 1 && !visit[i]) {
            printf("%d ", i);   // ���� '��'���� �� �̿��� ���
            depthFirstSearch(i);
        }
    }
}

//void dfs(int v) // by dongbinna (adjacent list with vector)
//{
//    if (visit[v]) return;   // prevents stackoverflow occured by recursion (?)
//    visit[v] = true;
//    printf("%d ", v);   // �̿���ȸ���� ����'��' ���
//    for (int i = 0; i < a[x].size(); i++) {
//        int y = a[x][i];
//        dfs(y);
//    }
//}