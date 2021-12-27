#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> Q;	// ÃÖ´ëÈü

int N, num;
int main() {
	ios_base::sync_with_stdio(NULL);	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> num;
		if (num == 0) {
			if (Q.empty()) {
				cout << "0\n";
			}
			else
			{
				cout << Q.top() << '\n';
				Q.pop();
			}
		}
		else
			Q.push(num);
	}
	return 0;
}
