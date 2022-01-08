// 투포인터
// 연속된 수들의 부분합 중에 그 합이 S 이상이 되는 것 중, 가장 짧은 것의 길이를 구하는 프로그램
// 강사님 코드 (left<right 조건이 굳이 적혀있지 않다)
// 생각해보면 부분합이 항상 S이상을 유지하려는 성질때문에 left와 right가 교차되는 일은 없을듯(?)
// => 녹강 다시 들어보아야할듯

#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000

int Data[MAXN + 1];
int main()
{
	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++) cin >> Data[i];

	int left = 0, right = 0, sum = 0, ans = N + 1;	// ans의 초기값을 최대로 잡는다
	while (true)
	{
		if (sum >= S)
		{
			ans = min(ans, right - left);
			sum -= Data[left++];
		}
		else if (right == N) break;	// 끝에 도달
		else
		{
			sum += Data[right++];
		}
	}
	// 만일 그러한 합을 만드는 것이 불가능하다면 0을 출력
	// Data[0] ~ Data[N-1} 다 더해도 sum < S 이면 그러한 부분합 만들기가 불가능한 것
	// if(sum>=S) 을 만족하지 못하여 ans는 초기값 N+1 그대로 일 것
	if (ans == N + 1) 
		cout << 0 << '\n';
	else 
		cout << ans << '\n';
}