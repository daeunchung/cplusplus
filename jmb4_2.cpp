#include <bits/stdc++.h>
using namespace std;

// �־��� �迭���� ���� ���� �����ϴ� ���ڸ� ��ȯ�ϱ� 2
// linear time
// A �� �� ���Ұ� 0~100 ���̰��� ���
int majority2(const vector<int>& A)
{
	int N = A.size();
	// counting sort �� counting (���Һ� ���� ����) �κи� ����ѵ�?
	vector<int> count(101, 0);	// index�� 0~100���� ����
	for (int i = 0; i < N; ++i)
	{
		count[A[i]]++;
	}

	// ���ݱ��� Ȯ���� ���� �� �󵵼��� ���� ū ���� majority�� ����
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