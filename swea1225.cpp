/* 1225. [S/W 문제해결 기본] 7일차 - 암호생성기 D3 */
#include <iostream>
#include <queue>
using namespace std;
int testcase = 10, num;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= testcase; i++)
	{
		queue<int> q;
		cin >> i;
		for (int i = 0; i < 8; i++) {
			cin >> num;
			q.push(num);
		}
		bool stop = false;
		while (true)
		{
			for (int i = 1; i <= 5 && !stop; i++)
			{
				int tmp = q.front();
				q.pop();
				if (tmp - i <= 0) {
					stop = true;
					q.push(0);
				} else 
					q.push(tmp - i);
			}
			if (stop) break;
		}
		
		cout << "#" << i << " ";
		while (!q.empty()) {
			cout << " " << q.front();
			q.pop();
		}
		cout << "\n";
	}

	return 0;
}