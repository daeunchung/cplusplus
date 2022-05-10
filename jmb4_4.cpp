// '�̵� ���' ���ϱ� with sliding window algorithm

#include <bits/stdc++.h>
using namespace std;

vector<double> movingAverageMine(const vector<double>& A, int M)
{
	int N = A.size();
	vector<double> ret;

	int partialSum = 0;
	for (int j = 0; j < M; ++j) partialSum += A[j];
	ret.push_back(partialSum / M);

	for (int i = M; i < N; ++i)
	{
		partialSum += A[i];
		partialSum -= A[i - M];
		ret.push_back(partialSum / M);
	}
	return ret;
}

// ���� �ð��� �̵� ��� ���ϱ�
// ���̰� N�� �Ǽ� �迭 A�� �־��� ��, �� ��ġ������ M-�̵� ��� ���� ���Ѵ�
vector<double> movingAverage2(const vector<double>& A, int M)
{
	int N = A.size();
	vector<double> ret;

	int partialSum = 0;
	for (int i = 0; i < M-1; ++i) 
		partialSum += A[i];

	for (int i = M-1; i < N; ++i)
	{
		partialSum += A[i];
		ret.push_back(partialSum / M);
		partialSum -= A[i - M + 1];
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	return 0;
}