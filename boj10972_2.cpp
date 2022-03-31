//가장 마지막 인접숫자 증가 구간을 찾는다.(< )
//5 2 < 4 3 1 (< 뒤에 숫자중 < 바로앞 2 보다 바로다음으로 큰수를 2자리로 swap + 남은수 정렬)
//5 3 1 2 4
//
//5 2 4 1 < 3
//5 2 4 3 1
//12345
//1<2<3<54
//124 53
//12435
//
//12435
//1<2<4<53
//12534
//12543
//
//21345
//
//54321
//-1
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> v;
	int N, x, num, idx;  

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;

	cin >> x;
	v.push_back(x);
	idx = -1;
	for(int i=1; i<N; i++) {
		cin >> x;
		v.push_back(x);
		if (v[i - 1] < v[i]) {
			num = v[i-1];
			idx = i-1;
		}
	}
	if (idx < 0) {
		cout << -1 << '\n';
		return 0;
	}

	// num 보다 큰 최소 숫자 찾기
	int diff = N - num;
	int find = 0;
	for (int i = idx+1; i < N; i++) {
		if (v[i] > num && v[i] - num <= diff) {
			find = i;
			diff = v[i] - num;
		}
	}
	swap(v[idx], v[find]);
	sort(v.begin() + idx+1, v.end());

	for(auto it = v.begin(); it != v.end(); ++it)
		cout << *it << ' ';
	return 0;
}