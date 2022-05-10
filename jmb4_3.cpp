#include <bits/stdc++.h>
using namespace std;
// �Ǽ� �迭 A�� �־��� ��, �� ��ġ������ M-�̵� ��� �� ���ϱ�
// constant time M*(N-M+1)
vector<double> movingAverage1(const vector<double>& A, int M)
{
	vector<double> ret;
	int N = A.size();
	for (int i = M - 1; i < N; ++i)	// i�� ������ ����
	{
		double partialSum = 0;
		for (int j = 0; j < M; j++) // �Ź� sum �� �ʱ�ȭ �ϰ� ���� ���ϳ� (�� ���� �̷��� ..)
		{
			partialSum += A[i-j];	// �ڿ������� ���Ѵ� 
			// A[����M�� ����] + A[����M�� �ڿ��� ��ĭ ��] + A[�� ��] + ...
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