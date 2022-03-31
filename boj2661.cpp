// 좋은 수열 - 백트래킹  N은 1 이상 80 이하
// 1~n-1 에 n번째 수를 추가하였을 때 , 반복이 이루어질 수 있는 가장 긴 부분 수열의 길이는 n/2 라서 
// 마지막 인덱스를 기준으로 길이를 1부터 시작해 (수열의 길이/2)까지 비교하는 것

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
