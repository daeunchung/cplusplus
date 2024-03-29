/*
* 이친수 : 0으로 시작하지 않는다. 1이 두 번 연속으로 나타나지 않는다. (즉, 11을 부분 문자열로 갖지 않는다.)
D[i][j] = 길이가 i이고 마지막에 사용한 수는 j인 이친수의 개수 (마지막 수가j인 i자리 이친수)

D[0][0] = D[0][1] = D[1][0] = 0;    D[1][1] = 1;
D[i][0] = D[i-1][0] + D[i-1][1]
D[i][1] = D[i-1][0]
=> 2차원 배열 dp
이 문제의 경우에는 숫자가 0,1 두개로만 구성되기 때문에 특이케이스로 1차원 배열 dp도 가능하다

*/
#include <iostream>
using namespace std;
long long d[91][2];	// 전부 0으로 초기화
int main()
{
    int n;
    cin >> n;
    d[0][0] = d[0][1] = d[1][0] = 0;    d[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        d[i][0] = d[i - 1][0] + d[i - 1][1];
        d[i][1] = d[i - 1][0];
    }
    cout << d[n][0] + d[n][1] << '\n';
    return 0;
}