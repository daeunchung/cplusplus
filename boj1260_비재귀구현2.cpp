/*
* https://www.acmicpc.net/source/share/f020aad01e0c426ca73624bf3580d376
* 비재귀 구현 소스2
*/
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[1001];
bool check[1001];
int start[1001];
void dfs(int node) {
    stack<int> s;
    s.push(node);
    check[node] = true;
    printf("%d ", node);
    while (!s.empty()) {
        int node = s.top();
        s.pop();
        for (int& i = start[node]; i < a[node].size(); i++) {
            int next = a[node][i];
            if (check[next] == false) {
                printf("%d ", next);
                check[next] = true;
                s.push(node);
                s.push(next);
                break;
            }
        }
    }
}
void bfs(int start) {
    queue<int> q;
    memset(check, false, sizeof(check));
    check[start] = true;
    q.push(start);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        printf("%d ", node);
        for (int i = 0; i < a[node].size(); i++) {
            int next = a[node][i];
            if (check[next] == false) {
                check[next] = true;
                q.push(next);
            }
        }
    }
}
int main() {
    int n, m, start;
    scanf("%d %d %d", &n, &m, &start);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        sort(a[i].begin(), a[i].end());
    }
    dfs(start);
    puts("");
    bfs(start);
    puts("");
    return 0;
}
