/*
외판원 순회2  TSP Traveling Salesman Problem
순열 중 선택문제

도시의 수 N  "2 ≤ N ≤ 10" ( N 커지면 순열로는 X)
어느 한 도시에서 출발해 "N개의 도시를 모두 거쳐" 다시 원래의 도시로 돌아오는 순회 여행 경로
단, "한 번 갔던 도시로는 다시 갈 수 없다" 
" " => 3가지 조건 때문에 순열로 해결이 가능
순열 = O(N*N!)

기존 순열 O(N*N!) 에서
-> O(N!) 로 개선 가능 (1234 == 2341 == 3412 == 4123 다시 시작도시로 가야해서 모두 같은 경우)
따라서 N*(N-1)! == N!

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int w[20][20];
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    // 도시 순회 순열을 위한 벡터
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    int ans = 2147000000;
    do {
        bool exists = true;
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (w[p[i]][p[i + 1]] == 0) 
                exists = false;
            else 
                sum += w[p[i]][p[i + 1]];
        }
        if (exists && w[p[n - 1]][p[0]] != 0) {
            sum += w[p[n - 1]][p[0]];
            if (ans > sum) ans = sum;
        }
    } 
 // while (next_permutation(p.begin(), p.end()));     O(N*N!)
    while (next_permutation(p.begin() + 1, p.end()));   // O(N!) 첫숫자를 1로 고정

    cout << ans << '\n';
	return 0;
}