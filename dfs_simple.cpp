#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1050;
int n, m;
vector<int> v[MAX];
bool check_dfs[MAX];

//DFS Search
void DFS(int index) {
    check_dfs[index] = true; //���� �湮 üũ
    printf("%d ", index); //�湮�� ���� ���

    for (int i = 0; i < v[index].size(); i++) {
        int next = v[index][i];

        if (!check_dfs[next]) { //�湮���� �ʾҴٸ� DFS() ȣ��
            DFS(next);
        }
    }
}

int main() {

    scanf("%d %d", &n, &m);

    //�׷��� ������ �Է�
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        v[a].push_back(b);
        v[b].push_back(a);
    }

    DFS(0);

    return 0;
}