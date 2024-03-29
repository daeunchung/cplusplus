/*
dp 메모이제이션 시에 필요한 변수가 2개면 배열이 2차원 배열이 되는 것 
D[i][j] = i를 1,2,3의 합으로 나타내는 방법의 수, 마지막에 사용한 수는 j

D[i][1] = i를 1,2,3의 합으로 나타내는 방법의 수, 마지막에 사용한 수는 1 => 바로전에 사용가능한 수 2,3
D[i][2] = i를 1,2,3의 합으로 나타내는 방법의 수, 마지막에 사용한 수는 2 => 바로전에 사용가능한 수 1,3
D[i][3] = i를 1,2,3의 합으로 나타내는 방법의 수, 마지막에 사용한 수는 3 => 바로전에 사용가능한 수 1,2

D[i][1] = D[i-1][2] + D[i-1][3] (i>1), D[1][1] = 1, D[i][1] = 0 (i<1)
D[i][2] = D[i-2][1] + D[i-2][3] (i>2), D[2][2] = 1, D[i][2] = 0 (i<2)
D[i][3] = D[i-3][1] + D[i-3][2] (i>3), D[3][3] = 1, D[i][3] = 0 (i<3)

아무 생각없이 D[0][1] = D[0][2] = D[0][3] = 1 로 초기화하면 중복 발생하기에
위처럼 예외 처리를 해주어야 함
*/

#include <iostream>
using namespace std;
long long D[100001][4];	// 전부 0으로 초기화
const long long mod = 1000000009LL;
const int limit = 100000;
void run(long long (*d)[4])
{
    for (int i = 1; i <= limit; i++) {
        if (i >= 1) {
            d[i][1] = d[i - 1][2] + d[i - 1][3];
            if (i == 1) {
                d[i][1] = 1;
            }
        }
        if (i - 2 >= 0) {
            d[i][2] = d[i - 2][1] + d[i - 2][3];
            if (i == 2) {
                d[i][2] = 1;
            }
        }
        if (i - 3 >= 0) {
            d[i][3] = d[i - 3][1] + d[i - 3][2];
            if (i == 3) {
                d[i][3] = 1;
            }
        }
        d[i][1] %= mod;
        d[i][2] %= mod;
        d[i][3] %= mod;
    }
}
int main()
{
	run(D);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
        cout << (D[n][1] + D[n][2] + D[n][3]) % mod << '\n';
	}
	return 0;
}