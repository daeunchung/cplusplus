/*
D[i] = i자리 이친수의 개수
가능한 경우 - 
1. 0으로 끝나는 경우(앞에 0,1 올수있음) = D[i-1]
2. 1로 끝나는 경우(앞에 0 만올수있음) = 01을 붙인다고 취급 = D[i-2]
특이 케이스로 1차원 배열 dp로 해결 가능  D[i] = D[i-1] + D[i-2]
*/
#include <iostream>
using namespace std;
long long d[91];
int main() {
    int n;
    cin >> n;
    d[1] = 1;   // 1
    d[2] = 1;   // 01
    for (int i = 3; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }
    cout << d[n] << '\n';
    return 0;
}