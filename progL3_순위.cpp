#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int> > v(n, vector <int>(n, 0));

    for (int i = 0; i < results.size(); i++) {
        v[results[i][0]][results[i][1]] = 1;
        v[results[i][1]][results[i][0]] = -1;
    }

    vector<int> known;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 0) cnt++;
            if (cnt > 1) break;
        }
        if (cnt == 1) known.push_back(i + 1);
    }
    int answer = 0;
    return answer;
}