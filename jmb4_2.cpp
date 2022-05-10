#include <bits/stdc++.h>
using namespace std;

// 주어진 배열에서 가장 많이 등장하는 숫자를 반환하기 2
// linear time
// A 의 각 원소가 0~100 사이값일 경우
int majority2(const vector<int>& A)
{
	int N = A.size();
	// counting sort 의 counting (원소별 갯수 저장) 부분만 사용한듯?
	vector<int> count(101, 0);	// index가 0~100까지 존재
	for (int i = 0; i < N; ++i)
	{
		count[A[i]]++;
	}

	// 지금까지 확인한 숫자 중 빈도수가 제일 큰 것을 majority에 저장
	int majority = 0;
	for (int i = 0; i <= 100; ++i)
	{
		if (count[i] > count[majority]) 
			majority = i;
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
	v.push_back(99);
	v.push_back(99);
	v.push_back(99);
	v.push_back(99);

	cout << majority2(v) << '\n';
	return 0;
}