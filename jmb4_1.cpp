#include <bits/stdc++.h>
using namespace std;

// 주어진 배열에서 가장 많이 등장하는 숫자 반환
// 두개 이상이면 아무거나 반환
// Time Complexity N^2
int majority1(const vector<int>& A)
{
	int N = A.size();
	int majority = -1, majorityCount = 0;	
	// 최댓값의 초기세팅을 -1 로 잡은걸 보면 입력배열에 음이 아닌 정수만 있나보다(?) 
	for (int i = 0; i < N; ++i)
	{
		int V = A[i], count = 0;
		for (int j = 0; j < N; j++) {
			if (A[j] == V) ++count;
		}
		if (count > majorityCount) {
			majorityCount = count;
			majority = V;
		}
	}
	return majority;
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	vector<int> v;
	v.push_back(5);
	v.push_back(5);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);
	v.push_back(5);

	cout << majority1(v) << '\n';
	return 0;
}