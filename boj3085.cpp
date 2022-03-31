/*
 ���Ʈ����     �ִ���, ����Ŭ�� ���� �����ΰ�?
 check �Լ� O(N����) => total O(N��4����) : 50��4���� = 6250000
 ������ check2 �Լ��� O(3N) �̶� total O(N3����) ���� ���� ����
 O(3N) : ��� ��, �� ���� ��Ž�� X = > swap�� ��, �ĸ� recheck

 ���� ���� ��� 
 check() ���� 28ms						O(n������)
 check2_row(), check2_col() ���� 0ms	O(3N������)
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
	// ������ ��ĭ ���� O(N����)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j + 1 < n)
			{
				swap(a[i][j], a[i][j + 1]);
				//int tmp = check(a);  // ���� �� �� �Ǵ� ���� Ž�� O(N����)
				int tmp = check2_row(a, i, j);
				if (ans < tmp) ans = tmp;
				swap(a[i][j], a[i][j + 1]);	// ����ġ
			}
			if (i + 1 < n)
			{
				swap(a[i][j], a[i+1][j]);
				//int tmp = check(a);	// ���� �� �� �Ǵ� ���� Ž�� O(N����)
				int tmp = check2_col(a, i, j);
				if (ans < tmp) ans = tmp;
				swap(a[i][j], a[i + 1][j]);	// ����ġ
			}
		}
	}
	cout << ans << '\n';
	return 0;
}

int check(vector<string>& a)	// O(N����)
{
	int n = a.size();
	int ans = 1;
	for (int i = 0; i < n; i++)
	{
		int cnt = 1;	// �� Ž�� ����
		for (int j = 0; j < n - 1; j++)
		{
			if (a[i][j] == a[i][j + 1]) cnt++;
			else cnt = 1;	// cnt reset �߿�

			if (ans < cnt) ans = cnt;
		}

		cnt = 1;
		for (int j = 0; j < n - 1; j++)
		{
			if (a[j][i] == a[j + 1][i]) cnt++;
			else cnt = 1;	// cnt reset �߿�

			if (ans < cnt) ans = cnt;
		}
	}
	return ans;
}
	
int check2_row(vector<string>& a, int row, int col)	// O(3N) : ��� ��,�� ���� ��Ž�� X => swap�� ��,�ĸ� recheck
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

int check2_col(vector<string>& a, int row, int col)	// O(3N) : ��� ��,�� ���� ��Ž�� X => swap�� ��,�ĸ� recheck
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