/*
 브루트포스     애니팡, 주주클럽 같은 게임인가?
 check 함수 O(N제곱) => total O(N의4제곱) : 50의4제곱 = 6250000
 개선된 check2 함수는 O(3N) 이라서 total O(N3제곱) 으로 수행 가능
 O(3N) : 모든 행, 렬 전부 재탐색 X = > swap한 행, 렬만 recheck

 백준 수행 결과 
 check() 사용시 28ms						O(n네제곱)
 check2_row(), check2_col() 사용시 0ms	O(3N세제곱)
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int check(vector<string>&);
int check2_row(vector<string>&, int, int);
int check2_col(vector<string>&, int, int);
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	int n;	cin >> n;	
	int ans = 0;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
			cin >> a[i];
	}
	// 인접한 두칸 고르기 O(N제곱)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j + 1 < n)
			{
				swap(a[i][j], a[i][j + 1]);
				//int tmp = check(a);  // 가장 긴 행 또는 열을 탐색 O(N제곱)
				int tmp = check2_row(a, i, j);
				if (ans < tmp) ans = tmp;
				swap(a[i][j], a[i][j + 1]);	// 원위치
			}
			if (i + 1 < n)
			{
				swap(a[i][j], a[i+1][j]);
				//int tmp = check(a);	// 가장 긴 행 또는 열을 탐색 O(N제곱)
				int tmp = check2_col(a, i, j);
				if (ans < tmp) ans = tmp;
				swap(a[i][j], a[i + 1][j]);	// 원위치
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

int check(vector<string>& a)	// O(N제곱)
{
	int n = a.size();
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;	// 행 탐색 시작
		for (int j = 0; j < n - 1; j++)
		{
			if (a[i][j] == a[i][j + 1]) cnt++;
			else cnt = 1;	// cnt reset 중요

			if (ans < cnt) ans = cnt;
		}

		cnt = 1;
		for (int j = 0; j < n - 1; j++)
		{
			if (a[j][i] == a[j + 1][i]) cnt++;
			else cnt = 1;	// cnt reset 중요

			if (ans < cnt) ans = cnt;
		}
	}
	return ans;
}
	
int check2_row(vector<string>& a, int row, int col)	// O(3N) : 모든 행,렬 전부 재탐색 X => swap한 행,렬만 recheck
{
	int n = a.size();
	int ans = 1;
	int cnt = 1;	
	for (int j = 0; j < n - 1; j++)
	{
		if (a[row][j] == a[row][j + 1]) cnt++;
		else cnt = 1;	
		if (ans < cnt) ans = cnt;
	}
	cnt = 1;
	for (int j = 0; j < n - 1; j++)
	{
		if (a[j][col] == a[j + 1][col]) cnt++;
		else cnt = 1;	
		if (ans < cnt) ans = cnt;
	}
	cnt = 1;
	for (int j = 0; j < n - 1; j++)
	{
		if (a[j][col+1] == a[j + 1][col+1]) cnt++;
		else cnt = 1;
		if (ans < cnt) ans = cnt;
	}
	return ans;
}

int check2_col(vector<string>& a, int row, int col)	// O(3N) : 모든 행,렬 전부 재탐색 X => swap한 행,렬만 recheck
{
	int n = a.size();
	int ans = 1;
	int cnt = 1;
	for (int j = 0; j < n - 1; j++)
	{
		if (a[row][j] == a[row][j + 1]) cnt++;
		else cnt = 1;
		if (ans < cnt) ans = cnt;
	}
	cnt = 1;
	for (int j = 0; j < n - 1; j++)
	{
		if (a[row+1][j] == a[row+1][j+1]) cnt++;
		else cnt = 1;
		if (ans < cnt) ans = cnt;
	}
	cnt = 1;
	for (int j = 0; j < n - 1; j++)
	{
		if (a[j][col] == a[j + 1][col]) cnt++;
		else cnt = 1;
		if (ans < cnt) ans = cnt;
	}
	return ans;
}