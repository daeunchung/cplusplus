/* 삼성 코딩테스트 기출
*
백트래킹 스타트와 링크
백준님 풀이와 생각하는 방법을 외워보자
N명 : 1, 2, 3, ... N-1, N 사람을 각각 스타트팀 or 링크팀으로 배치가 가능 => N(4 ≤ N ≤ 20, N은 짝수) 이라 2^20 = 1048576 시간만족
go(index, first, second) 함수

정답을 찾은 경우 : index == n
다음재귀로 가는 경우 : go(index, first(1번팀일때), second(2번팀일때))
두 경우 모두 호출 전에 배정 받는 팀에 index 를 넣고 , 호출1 후에 빼는 과정이 필요


모든 케이스를 전부 탐색 : 
브루트포스
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int s[20][20];
int n;
int go(int index, vector<int>& first, vector<int>& second) {
    if (index == n) {
        if (first.size() != n / 2) return -1;
        if (second.size() != n / 2) return -1;
        int t1 = 0;
        int t2 = 0;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                if (i == j) continue;
                t1 += s[first[i]][first[j]];
                t2 += s[second[i]][second[j]];
            }
        }
        int diff = t1 - t2;
        if (diff < 0) diff = -diff;
        return diff;
    }
    int ans = -1;
    first.push_back(index);
    int t1 = go(index + 1, first, second);
    if (ans == -1 || (t1 != -1 && ans > t1)) {
        ans = t1;
    }
    first.pop_back();
    second.push_back(index);
    int t2 = go(index + 1, first, second);
    if (ans == -1 || (t2 != -1 && ans > t2)) {
        ans = t2;
    }
    second.pop_back();
    return ans;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    vector<int> first, second;
    cout << go(0, first, second) << '\n';
}