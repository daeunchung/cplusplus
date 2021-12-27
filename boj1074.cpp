#include <iostream>
#include <cmath>
using namespace std;

#define S pow(2,N)
int N, R, C;
int cnt;

int Z(int N, int R, int C)
{
	while (N > 0)
	{
		if (0 <= R && R < S / 2 && 0 <= C && C < S / 2)
		{
		}
		else if (0 <= R && R < S / 2 && S / 2 <= C && C < S)
		{
			cnt = cnt + S * S / 4;
			C -= S / 2;
		}
		else if (S / 2 <= R && R < S && 0 <= C && C < S / 2)
		{
			cnt = cnt + S * S / 4 * 2;
			R -= S / 2;
		}
		else if (S / 2 <= R && R < S && S / 2 <= C && C < S) {
			cnt = cnt + S * S / 4 * 3;
			R -= S / 2;
			C -= S / 2;
		}
		N--;
		return Z(N, R, C);
	}
	return cnt;
}

int main()
{
	cin >> N >> R >> C;
	cout << Z(N, R, C) << '\n';
	return 0;
}