//#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
//using namespace std;

/*
��, 3�� ������ ���� A -> B, B -> C�� A -> C ��Ģ�� ����ϱ� ����, ������ ���� �����Ѵٸ�
4�� ������ 2���� �̱��, 2���� 5���� �̰����� 4���� 5���� ������ �̱�� �ȴ�.
�̷��� ��츦 ã�Ƴ��� graph[4][5] = 1ó�� ������Ŀ� �� ���� ������� �߰�
�� ������ ��� ������ (B�� ���ó��)���İ��� ���������� �̱� ��츦 ã�� ���̴�.
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
// Floyd�ͼ�
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