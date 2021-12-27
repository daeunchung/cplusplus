/* DP 문제 
DP[N] 은 DP[N-1] 과 DP[N/2] 와 DP[N/3] 에서 한 번의 연산을 더 수행해서 만들 수 있음.
그 중 최소 연산 횟수이기 때문에 DP[N] = min(DP[N-1]+1, DP[N/2]+1, DP[N/3]+1) 
*/
#include <iostream>
#include <algorithm>

using namespace std;
int DP[1000001];
int n;

int main()
{
	cin >> n;
	for(int i=2; i<=n; i++)
	{
		DP[i] = DP[i - 1] + 1;
		if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1);
		if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1);
	}
	cout << DP[n] << endl;
	return 0;
}