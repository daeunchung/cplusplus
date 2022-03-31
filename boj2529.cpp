/*
* 부등호 - 백트래킹, 브루트포스
1. 수를 다 선택하고 검사
2. 수를 선택'하면서' (매번)검사

1(브루트포스) 보다 2(백트래킹)이 우월 (920ms -> 8ms 어마어마함)
 < < < > < < > < > 일때 앞에서 이미 9 < 8 이면 뒤에꺼 숫자 채우는거 시간낭비 => 그 경우 탐색을 버림

 부등호 개수 2 ≤ k ≤ 9 
각 공백에 올 수 있는 수가 0~9 즉 시간복잡도 : 10^(k+1)

check[] 배열 : 이미 사용한 수인지 check 하는 배열
*/

// 1. 브루트포스 (272ms)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n;
char a[10];         // 입력받은 부등호 저장
vector<string> ans; // 만든 정수를 문자열로 보관
bool check[10];     // 0 ~ 9 숫자사용여부check

bool good(string num)
{
    for (int i = 0; i < n; i++) {
        if (a[i] == '<') {
            if(num[i] > num[i + 1]) return false;
        }
        else if (a[i] == '>') {
            if(num[i] < num[i + 1]) return false;
        }
    }
    return true;    // 부틍호 틀리는거 없으면 true 
}
void go(int index, string num)
{
    // 부등호 다 채웠을때
    if (index == n + 1) {
        if (good(num)) {
            ans.push_back(num);
        }
        return;
    }
    // 부등호 다 못 채웠으면
    for (int i = 0; i <= 9; i++) {
        if (check[i]) continue; // 이미 사용한 숫자면 pass
        check[i] = true;
        go(index + 1, num + to_string(i));
        check[i] = false;
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