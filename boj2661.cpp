// ���� ���� - ��Ʈ��ŷ  N�� 1 �̻� 80 ����
// 1~n-1 �� n��° ���� �߰��Ͽ��� �� , �ݺ��� �̷���� �� �ִ� ���� �� �κ� ������ ���̴� n/2 �� 
// ������ �ε����� �������� ���̸� 1���� ������ (������ ����/2)���� ���ϴ� ��

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int N;
string ans;
bool check = false;
bool ok(string str)
{
	int size = str.size();
	for (int i = 1; i <= size / 2; i++) {
		if (str.substr(size - i, i) == str.substr(size - 2 * i, i)) 
			return false;
	}
	return true;
}
void dfs(string str, int cnt)
{
	if (cnt == N) {
		check = true;
		ans = str;
		return;
	}
	for (int k = 1; k <= 3; k++) {
		if (check) break;
		if (ok(str + to_string(k))) {
			dfs(str + to_string(k), cnt + 1);
		}
	}
}

int main() {
	cin >> N;
	dfs("1", 1);
	cout << ans << endl;
}
