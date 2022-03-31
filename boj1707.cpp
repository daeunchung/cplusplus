// 이분 그래프Bipartite Graph : 그래프의 모든 간선이 한쪽 끝은 그룹 A, 다른 한쪽 끝은 그룹 B인지를 확인
// 0 == 방문안함, 1 == 그룹번호1, 2 == 그룹번호2
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
        int n, m;   // n정점 m간선
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
                if (group[i] == group[j]) { // 간선의 양끝 정점을 체크
                    ok = false;
                }
            }
        }
        printf("%s\n", ok ? "YES" : "NO");
    }
    return 0;
}
