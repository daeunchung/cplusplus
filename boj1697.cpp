/* BFS */
#include <queue>
#include <iostream>
#include <string>
using namespace std;

#define MAX 1000001

int N, K, cnt;
bool visited[MAX];
queue<pair<int, int> > Q;

int BFS(int N, int K)
{
	while (!Q.empty()) {
		int loc = Q.front().first;
		int time = Q.front().second;
		Q.pop();
		if (loc == K) return time;

		if (loc + 1 < MAX && !visited[loc + 1]) {
			Q.push(make_pair(loc + 1, time + 1));
			visited[loc + 1] = 1;
		}
		if (loc - 1 >= 0 && !visited[loc - 1]) {
			Q.push(make_pair(loc - 1, time + 1));
			visited[loc - 1] = 1;
		}
		if (loc * 2 < MAX && !visited[loc * 2]) {
			Q.push(make_pair(loc * 2, time + 1));
			visited[loc * 2] = 1;
		}
	}
}

int main() {
	cin >> N >> K;
	Q.push(make_pair(N, 0));
	visited[N] = 1;
	cout << BFS(N, K) << endl;
	return 0;
}