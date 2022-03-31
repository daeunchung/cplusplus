//  http://codeplus.codes/304dc84b3eb04e1b9832505dae72a0fc 
// 간선 리스트 소스 코드  정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000)
// https://www.acmicpc.net/source/share/304dc84b3eb04e1b9832505dae72a0fc
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int from, to;
};
Edge edge[20001];
int cnt[1001];
bool check[1001];
bool cmp(const Edge& u, const Edge& v) {
    if (u.from == v.from) {
        return u.to < v.to;
    }
    else {
        return u.from < v.from;
    }
}

void dfs(int node)
{
    check[node] = true;
    cout << node << ' ';
    for (int i = cnt[node - 1]; i < cnt[node]; i++)
    {
        int next = edge[i].to;
        if (check[next] == false) {
            dfs(next);
        }
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    check[start] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << ' ';
        for (int i = cnt[node - 1]; i < cnt[node]; i++)
        {
            int next = edge[i].to;
            if (check[next] == false) {
                check[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n, m, start, a, b;
    cin >> n >> m >> start;
    for (int i = 0; i < m; i++)
    {
        //scanf("%d %d", &edge[i].from, &edge[i].to);
        //edge[i + m].from = edge[i].to;
        //edge[i + m].to = edge[i].from;
        cin >> a >> b;
        edge[i + m].from = edge[i].to = b;
        edge[i + m].to = edge[i].from = a;

        /*
        * n 정점의 수가 4개, m 간선의 수가 5개 일때
        1 2  ::간선1(1 -> 2)  간선6(2 -> 1)
        1 3  ::간선2(1 -> 3)  간선7(1 -> 1)
        1 4  ::간선3(1 -> 4)  간선8(4 -> 1)
        2 4  ::간선4(2 -> 4)  간선9(4 -> 2)
        3 4  ::간선5(3 -> 4)  간선10(4 -> 3)
        */
    }
    m *= 2;
    //cnt[0] = 0, cnt[1] = 4, cnt[2] = 2, cnt[3] = 1, cnt[4] = 3;
    //cnt = {0, 4, 6, 7, 10} 
    sort(edge, edge + m, cmp);
    for (int i = 0; i < m; i++) {
        cnt[edge[i].from] += 1;
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] += cnt[i - 1];
    }
    dfs(start); cout << '\n';
    bfs(start); cout << '\n';
    return 0;
}