#include <iostream>
using namespace std;
// [0]:배치X [1]:1번칸에배치 [2]:2번칸에배치. D[i][j] = i번째우리 j번째칸에 배치하는 경우의 수
int D[100001][3];
int mod = 9901;
int main()
{
	for(int j = 0; j<3; j++) D[1][j] = 1;
	int n;	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		D[i][0] = (D[i - 1][0] + D[i - 1][1] + D[i - 1][2]) % mod;
		D[i][1] = (D[i - 1][0] + D[i - 1][2]) % mod;
		D[i][2] = (D[i - 1][0] + D[i - 1][1]) % mod;
	}
	cout << (D[n][0] + D[n][1] + D[n][2]) % mod << '\n';
	return 0;
}