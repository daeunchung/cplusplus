/* D[i] = 3*i 를 채우는 방법의 수
최백준님이 별로 바람직한 문제 아니라고 하심 (추가되는 타일마다 가능한 경우가 더 존재할 수 있는데 이를 찾아내야한다)
D[i] = 3 * D[i-2] + 2 * D[i-4] + 2 * D[i-6] + ...

의문 : N이 홀수는 절대 될 수 없는건가?
*/
#include <iostream>
using namespace std;
long long d[31];
int main()
{
	int n;	cin >> n;
	d[0] = 1;	// d[2] = 3;
	for (int i = 2; i <= n; i += 2) {
		d[i] += 3 * d[i - 2];
		for (int j = i - 4; j >= 0; j -= 2) {
			d[i] += 2 * d[j];
		}
	}
	cout << d[n] << '\n';
	return 0;
}