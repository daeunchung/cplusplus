/* 계속 중복이 발생할때에 공통된 것들끼리 그룹을 형성해 계산하면 시간 save 가능 (백준 : 등비수열합공식만 안썼고 나머지 동일)

내 풀이
일의 자리 개수 = n 개 = n - (1-1)
십의 자리 개수 = n - 9 개 = n - (10-1)
백의 자리 개수 n - 99 - n - (100-1)
n 의 자릿수가 k 일때
k * n - (10^(k-1) + 10^(k-2) + ... + 10^1 + 10^0) + k

답 = k*(n+1) - 1*(10^k - 1)/(10 - 1)
*/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	// N(1 ≤ N ≤ 100,000,000)
	int n;
	long long ans = 0;
	cin >> n;	int tmp = n;
	int k = 0;
	while (tmp) {
		tmp /= 10;
		k++;
	}
	ans = k * (n+1) - (pow(10, k) - 1)/(10 - 1);
	cout << ans << '\n';
	return 0;
}
