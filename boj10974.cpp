// 모든 순열시 do while 문 사용 권장. 이유:일반 while문처럼 조건 검사시에 다음순열로 넘어가지 않기때문
// 모든 순열 N*N!
// 주의 : O(N) 과 O(N+!) 은 같다고 쳐도되지만 , O(N!) 과 O((N+1)!) 은 어마어마한 차이가 나기에 주의
// 1억(100000000) == 1초
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n); 
    for (int i = 0; i < n; i++) {
        a[i] = i+1;
    }
    do {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}