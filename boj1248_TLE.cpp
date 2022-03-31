// ����� - ��Ʈ��ŷ    N�� 10���� �۰ų� ���� �ڿ���
/*
-2 5 -3 1

-+0+  4 ^
 +++  3 |
  --  2 |
   +  1 | �Ʒ����� ���� backtracking

S[i][j] = A[i] + .. + A[j] (i<=j)

s[1][1]  [1][2]  [1][3]  [1][4]   -    +    -    +
s[2][1]  [2][2]  [2][3]  [2][4]   abs<abs
s[3][1]  [3][2]  [3][3]  [3][4]        abs>abs
s[4][1]  [4][2]  [4][3]  [4][4]             abs>abs

-1  1  -1  1�� ����

-1  3 -2  1 �ں��� ���������


ó������ ������ �� �ڵ� : TLE
�����ڵ���� ���̴� ���� check() �� �Ź�[x]~[y] �������� ���α�������
���ش��� [x]~[y-1] �������� �������� �����ϸ鼭 [y] ���� �߰����ִ� ������ check
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

char schar[11][11];
int sval[11];
int N;
vector<int> vP;	// value Positive

bool check(int x, int y)
{
	int s = 0;
	for (int i = x; i <= y; i++) s += (vP[i] * sval[i]);

	if (s > 0 && schar[x][y] == '+') return true;
	else if (s < 0 && schar[x][y] == '-') return true;
	else if (s == 0 && schar[x][y] == '0') return true;
	return false;
}

// i=N ~ i=1 ���� Ž��, base condition : i=0  // �ð��ʰ� 
void backtrack(int i)	
{
	if (i == 0) return;

	while (i >= 1) {
		int j = i;
		while (j <= N) {
			// ���� ��value ��ȣ �������� check
			if (check(i, j))
				j++;
			// idx ���� �ٲ�
			else {
				vP[i]++;
				return backtrack(i);
			}
		}
		return backtrack(i - 1);
	}
	//for (int i = N; i >= 1; i--) {
	//	bool flag = true;
	//	for (int j = i; j <= N; j++) {
	//		if (check(i, j)) break;
	//		//else break; �ϰ� continue �̰� ������ ǥ���� �Ұ���
	//		else {
	//			flag = false;
	//			break;
	//		}
	//	}
	//	if (!flag) continue;
	//}
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	cin >> N;
	string str;
	cin >> str;
	// Input
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			schar[i][j] = str[cnt++];

			if (i == j) {
				if (schar[i][j] == '-') sval[i] = -1;
				else if (schar[i][j] == '+') sval[i] = 1;
				else sval[i] = 0;
			}
		}
	}

	// vP[1] ~ vP[N] ���
	for(int i=0; i<=N; i++)	
		vP.push_back(1);

	backtrack(N-1);

	for (int i = 1; i<=N; i++)
		cout << vP[i] * sval[i] << ' ';

	return 0;
}
