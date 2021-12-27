// 21-12-25
// 처음에는 어떻게 조세푸스 문제를 큐로 풀지 ? 해서 vector 로 하려고 했으나
// 큐를 사용하라면 이유가 있을꺼이기에 곰곰히 생각해보니 큐를 사용할 수 있었음.
// 해설에서 백준님이 큐 굳이 쓸 필요 없는 문제라고..
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;

	queue<int> q;
	for (int i = 1; i <= n; i++) q.push(i);

	cout << '<';
	int check = 0, cnt = 0;
	while (cnt < n) {
		int tmp = q.front();
		q.pop();
		check++;
		if (check % k == 0) {
			cout << tmp;
			if (cnt != n - 1) cout << ", ";
			cnt++;
		}
		else if (check % k != 0) {
			q.push(tmp);
		}
	}
	cout << '>';
	return 0;
}