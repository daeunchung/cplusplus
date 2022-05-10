#include <bits/stdc++.h>
using namespace std;

// �־��� �迭���� ���� ���� �����ϴ� ���� ��ȯ
// �ΰ� �̻��̸� �ƹ��ų� ��ȯ
// Time Complexity N^2
int majority1(const vector<int>& A)
{
	int N = A.size();
	int majority = -1, majorityCount = 0;	
	// �ִ��� �ʱ⼼���� -1 �� ������ ���� �Է¹迭�� ���� �ƴ� ������ �ֳ�����(?) 
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