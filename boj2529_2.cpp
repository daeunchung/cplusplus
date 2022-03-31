// 2. 백트래킹 (4ms)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n;
char a[10];         // 입력받은 부등호 저장
vector<string> ans; // 만든 정수를 문자열로 보관
bool check[10];     // 0 ~ 9 숫자사용여부check

bool good(char x, char y, char op)
{
    if (op == '<') {
        if (x > y) return false;
    }
    else if (op == '>') {
        if (x < y) return false;
    }
    return true;    // 부틍호 틀리는거 없으면 true 
}
void go(int index, string num)
{
    // 부등호 다 채웠을때 수열을 답 후보로 넣어준다
    if (index == n + 1) {
        ans.push_back(num);
        return;
    }
    // 부등호 다 못 채웠으면
    for (int i = 0; i <= 9; i++) {
        if (check[i]) continue; // 이미 사용한 숫자면 pass
        // 첫부등호가 나오기 전(첫숫자) or 여태뽑은 수들이 부등호 만족시에
        if (index == 0 || good(num[index-1], i+'0', a[index-1])) {
            check[i] = true;
            go(index + 1, num + to_string(i));
            check[i] = false;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    go(0, "");
    auto p = minmax_element(ans.begin(), ans.end());
    cout << *p.second << '\n';  // 최대
    cout << *p.first << '\n';   // 최소
    return 0;
}