// 맞춰봐 - 백트래킹    N은 10보다 작거나 같은 자연수
/*
-2 5 -3 1

-+0+  4 ^
 +++  3 |
  --  2 |
   +  1 | 아래에서 위로 backtracking

S[i][j] = A[i] + .. + A[j] (i<=j)

s[1][1]  [1][2]  [1][3]  [1][4]   -    +    -    +
s[2][1]  [2][2]  [2][3]  [2][4]   abs<abs
s[3][1]  [3][2]  [3][3]  [3][4]        abs>abs
s[4][1]  [4][2]  [4][3]  [4][4]             abs>abs

-1  1  -1  1로 시작

-1  3 -2  1 뒤부터 끼워맞춘다


처음부터 끝까지 내 코드 : TLE
정답코드와의 차이는 나는 check() 를 매번[x]~[y] 구간합을 새로구하지만
백준님은 [x]~[y-1] 구간합의 누적값을 유지하면서 [y] 값만 추가해주는 식으로 check
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

// i=N ~ i=1 까지 탐색, base condition : i=0  // 시간초과 
void backtrack(int i)	
{
	if (i == 0) return;

	while (i >= 1) {
		int j = i;
		while (j <= N) {
			// 다음 합value 부호 만족여부 check
			if (check(i, j))
				j++;
			// idx 값을 바꿔
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
	//		//else break; 하고 continue 이게 문법상 표현이 불가능
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

	// vP[1] ~ vP[N] 사용
	for(int i=0; i<=N; i++)	
		vP.push_back(1);

	backtrack(N-1);

	for (int i = 1; i<=N; i++)
		cout << vP[i] * sval[i] << ' ';

	return 0;
}
