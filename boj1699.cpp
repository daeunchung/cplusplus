/* 
D[i] = i를 제곱수의 합으로 나타냈을 때, 필요한 항의 최소 개수
D[i] = min(D[i-j*j] + 1) (1 <= i <= j*j) 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> d(n + 1);
	for (int i = 1; i <= n; i++) {
		d[i] = i;	// 최댓값으로 배열초기화 5 = 1+1+1+1+1 
		for (int j = 1; j * j <= i; j++)
			if (d[i] > d[i - j * j] + 1) 
				d[i] = d[i - j * j] + 1;
	}
	cout << d[n] << '\n';
	return 0;
}
