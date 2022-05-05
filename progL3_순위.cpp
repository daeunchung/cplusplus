//#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
//using namespace std;

/*
즉, 3번 로직에 따라 A -> B, B -> C면 A -> C 법칙을 사용하기 위해, 선수를 노드로 간주한다면
4번 선수가 2번을 이기고, 2번이 5번을 이겼으니 4번은 5번을 무조건 이기게 된다.
이러한 경우를 찾아내서 graph[4][5] = 1처럼 인접행렬에 더 많은 경기결과를 추가
각 선수가 모든 선수를 (B의 경우처럼)거쳐가서 간접적으로 이길 경우를 찾는 것이다.
*/

//int solution(int n, vector<vector<int>> results) {
//	vector<vector<int> > v(n, vector <int>(n, 0));
//
//	for (int i = 0; i < results.size(); i++) {
//		v[results[i][0]][results[i][1]] = 1;
//		v[results[i][1]][results[i][0]] = -1;
//	}
//
//	vector<int> known;
//	for (int i = 0; i < n; i++) {
//		int cnt = 0;
//		for (int j = 0; j < n; j++) {
//			if (v[i][j] == 0) cnt++;
//			if (cnt > 1) break;
//		}
//		if (cnt == 1) known.push_back(i + 1);
//	}
//	int answer = 0;
//	return answer;
//}


#include <string>
#include <vector>
using namespace std;
// Floyd와샬
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));
    for (auto r : results)  graph[r[0]][r[1]] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (graph[j][i] && graph[i][k]) {
                    graph[j][k] = true;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (graph[i][j] || graph[j][i]) count++;
        }
        if (count == n - 1) answer++;
    }
    return answer;
}