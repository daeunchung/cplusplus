/*
ABCDE
 ��� : ����			ģ������ : ����
 �������, ��������Ʈ, ��������Ʈ ��� Ȱ���ؼ� Ǯ�� ����

 A-B : ��������Ʈ�� ����ִ� ��� ������ ��ȸ�ϸ� A-B �� ���� ã�� �� ����
 C-D : ��������Ʈ�� ����ִ� ��� ������ ��ȸ�ϸ� C-D �� ���� ã�� �� ����
 B-C : ��������� �������. ������ �� ������ ����Ǿ��ִ��� ������ ���� ������ ã�� �� ����
 D-E : ��������Ʈ�� �� ������ ����Ǿ��ִ� ��� ����, �� ������ ����� ������ ã�� ���

=> �׷����� �� �������°� ��� ���꿡 ���������� �� �˰� �־�� ���� �� ���� �ȴ�.


�ڵ忡�� ��������Ʈ�� ����, �����ϴ� �κ��� X
���� : ��� ������ �ʿ��� ��Ȳ O, ������ �� ������ ����� ������ �����ϴ� ���� ��������Ʈ���� ���� ���̱� ����
a[][]�������, g[]��������Ʈ, vector<pair<int, int> >edges��������Ʈ

�������� ģ������� �ֹ�(�����) �̶� 3���� �׷��� ǥ�� �ڷᱸ���� (from,to) �� (to,from) ��� Ǫ����
�׷��� ������ �� = ģ������ * 2


*/
#include <vector>
#include <iostream>
using namespace std;
bool a[2000][2000];				// �������
vector<int> g[2000];			// ��������Ʈ
vector<pair<int, int> > edges;	// ��������Ʈ
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		edges.push_back({ from, to });
		edges.push_back({ to, from });
		a[from][to] = a[to][from] = true;
		g[from].push_back(to);
		g[to].push_back(from);
	}

	// A�� B�� ģ����. - ��������Ʈ ���� ��ȸ
	// B�� C�� ģ����. - ������� : ������ �� ������ ���������� O(1)�� 
	// C�� D�� ģ����. - ��������Ʈ ���� ��ȸ
	// D�� E�� ģ����. - ��������Ʈ : �� ������ ����� ��� ���� ã��
	m *= 2;
	for (int i = 0; i < m; i++)
	{
		int A = edges[i].first;
		int B = edges[i].second;
		for(int j = 0; j < m; j++)
		{
			int C = edges[j].first;
			int D = edges[j].second;
			// A, B, C, D �� ���� �ٸ� �����̴�
			if (A == B || A == C || A == D || B == C || B == D || C == D)
			{
				continue;	// �̹�(i,j) �� ���� �Ҹ��� -> ���� (i,j) �� 
			}
			if (!a[B][C]) continue;
			for (int E : g[D]) {
				// E �� A, B, C, D �� ���� �����̸� �ȵȴ�
				if (A == E || B == E || C == E || D == E)
				{
					continue;
				}
				cout << 1 << '\n';	// ģ������ ����
				return 0;
			}
		}
	}
	cout << 0 << '\n';	// ģ������ �Ҹ���
	return 0;
}