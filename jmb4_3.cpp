#include <bits/stdc++.h>
using namespace std;
// 실수 배열 A가 주어질 때, 각 위치에서의 M-이동 평균 값 구하기
// constant time M*(N-M+1)
vector<double> movingAverage1(const vector<double>& A, int M)
{
	vector<double> ret;
	int N = A.size();
	for (int i = M - 1; i < N; ++i)	// i는 구간의 끝값
	{
		double partialSum = 0;
		for (int j = 0; j < M; j++) // 매번 sum 을 초기화 하고 새로 구하네 (왜 굳이 이렇게 ..)
		{
			partialSum += A[i-j];	// 뒤에서부터 더한다 
			// A[구간M중 끝값] + A[구간M중 뒤에서 한칸 앞] + A[그 앞] + ...
		}
		ret.push_back(partialSum / M);
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	return 0;
}