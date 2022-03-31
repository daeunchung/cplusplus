// 카잉 달력 : 건너 뛰며 해보기 . 진짜 모든 경우를 다 계산해볼 필요가 없는 경우 중간 중간 스킵하며 연산하는 방법
// 1<=M,N <=40,000 이라서 MN 전부 검사하면 16억 O(N제곱) => 16초 (시간초과)
// 따라서 x,y 중 x 값이 일치할때만 찾아가면서 N번 체크하면 된다 => O(N)
// <백준 풀이 > 나머지 연산을 사용하기 위하여 x, y에서 x-1, y-1 로 미리 1씩 빼준다. 시간 save 
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	int tc, m, n, x, y;	
	cin >> tc;
	while (tc--)
	{
		int ans = 0;
		bool exists = false;

		cin >> m >> n >> x >> y;
		for (int i = x; i <= m*n; i += m)
		{
			if (i % n == y % n) {
				ans = i;
				exists = true;
				break;
			}
		}
		if (!exists) 
			ans = -1;
		cout << ans << '\n';
	}
	return 0;
}