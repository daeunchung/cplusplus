/* 연속합 1912 연속합2 13398
연속합 2
 =>내가 기존에 하려던 하나의 수씩 삭제해 가면서 최댓값을 구하는 방법은 O(N제곱) 이라 시간초과
 실제로 배열에서 수를 삭제하지 않고서도 연속합의 최댓값을 구할 수 있다

 d[i][0] : 삭제하지 않았을 경우, d[i][1] : 삭제한 경우
 d[i][j] = a[1] ~ a[i]까지의 연속합 (해답풀이)
 d[i][j] = a[1] ~ a[i]까지의 i개의 숫자들의 연속합 (내생각)


 d[i][0] = max(d[i-1][0] + a[i], a[i]) 
 d[i][1] = max(d[i-1][1] + a[i], d[i-1][0])	// 이전에 이미 지웠던지, 이번에 나를 지울건지 둘 중 최댓값

*/
#include <iostream>
#include <algorithm>
#define MAXN 1000001
using namespace std;
int a[MAXN], d[MAXN][2];

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);

	int n;	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];

	//d[1][0] = a[1];	
	//d[1][1] = max(0, a[1]);
	//int ans = max(d[1][0], d[1][1]);
	// 위에처럼 해서 틀렸습니다 => d[1][1] 는 1번 또는 그 이전의 수를 삭제해서 d[1][삭제O] 
	// => 숫자가 한개이기 위해서는 삭제될 수 없어서 초기값을 잘 생각해야하는건가? 
	// 그러면 ans 는 왜 a[1]로 초기화해야하지?


	int ans = d[1][0] = d[1][1] = a[1];

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = max(d[i - 1][0] + a[i], a[i]);
		d[i][1] = max(d[i - 1][1] + a[i], d[i - 1][0]);
		ans = max({ ans, d[i][0], d[i][1] });
	}
	cout << ans << '\n';
	return 0;
}