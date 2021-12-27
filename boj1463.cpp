/* DP ���� 
DP[N] �� DP[N-1] �� DP[N/2] �� DP[N/3] ���� �� ���� ������ �� �����ؼ� ���� �� ����.
�� �� �ּ� ���� Ƚ���̱� ������ DP[N] = min(DP[N-1]+1, DP[N/2]+1, DP[N/3]+1) 
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