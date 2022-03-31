/*
1. 선택 문제
고른 수를 1, 안고른수를 0 => 고른수 6개, 안고른수 k-6개
0을 k-6개, 1을 6개 넣은 다음 next_permu 해도 된다
8개의 수 : 1 2 3 5 8 13 21 34 에 11111100 이면 1 2 3 5 8 13 고름

2. 재귀
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// 고른수를 0, 고르지 않은 수를 1 로 순열저장하였음
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	int n;
	while (cin >> n && n != 0)
	{
		vector<int> v(n);
		for(int i=0; i<n; i++)
			cin >> v[i];	// 입력시 오름차순

		vector<int> idx(n);
		for (int i = 0; i < 6; i++) 
			idx[i] = 0;
		for (int i = 6; i < n; i++) 
			idx[i] = 1;

		do {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				if (idx[i] == 0) {
					cnt++;
					cout << v[i];
					if (cnt == 6) {
						cout << '\n';
						break;
					}
					cout << ' ';
				}
			}
		} while (next_permutation(idx.begin(), idx.end()));
		cout << '\n';
	}
	return 0;
}