// �̺� �׷���Bipartite Graph : �׷����� ��� ������ ���� ���� �׷� A, �ٸ� ���� ���� �׷� B������ Ȯ��
// 0 == �湮����, 1 == �׷��ȣ1, 2 == �׷��ȣ2
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
using namespace std;
vector<int> a[20001];
int group[20001];

void dfs(int node, int c) {
    group[node] = c;
    for (int i = 0; i < a[node].size(); i++) {
        int next = a[node][i];
        if (group[next] == 0) {
            dfs(next, 3 - c);
        }
    }
}

int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        int n, m;   // n���� m����
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            a[i].clear();
            group[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            if (group[i] == 0) {
                dfs(i, 1);
            }
        }
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            for (int k = 0; k < a[i].size(); k++) {
                int j = a[i][k];
                if (group[i] == group[j]) { // ������ �糡 ������ üũ
                    ok = false;
                }
            }
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}
