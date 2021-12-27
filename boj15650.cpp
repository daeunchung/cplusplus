/* BackTracking 조합		{1, 2, 3} == {2, 1, 3}
조합이기에 idx 이전값은 반복문 순회하면 안된다. idx 변수가 필요O . dfs 매개변수 cnt, idx 로 두개 
ex) idx 가 2이면 234, 235, 245 처럼 idx 이후 값만 순회 가능하도록 만들기. idx 앞쪽의 1은 순회X */

#include <iostream>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX] = { 0, };
bool visited[MAX] = { 0, };	// [0]사용안함

void dfs(int idx, int cnt)
{
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = idx; i <= n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			arr[cnt] = i;
			dfs(i + 1, cnt + 1);	// dfs(x)가 실행중일때 cnt는 x-1임을 유의하자
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(1, 0);
}