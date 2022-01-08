// https://boycoding.tistory.com/152 정밀도와 범위 
#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, t = 0, max = -1;
	cin >> n;
	for(int i=0; i<n; i++) {
		int sc;
		cin >> sc;
		if (max < sc) max = sc;
		t += sc;
	}
	cout.precision(16);
	double ans = t / (double)max * 100 / (double)n;
	cout << ans << '\n';
	return 0;
}
