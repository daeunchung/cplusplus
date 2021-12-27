/* dp */
#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dy[501][501];
int t[501][501];

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			cin >> t[i][j];
	dy[0][0] = t[0][0];
	// dy[j][0] 가장 왼쪽 값과 dy[j][i] 가장 오른쪽 값은 각각 하나만 가질 수 있으므로 고정 
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dy[i][j] = dy[i - 1][j] + t[i][j];
            }
            else if (j == i) {
                dy[i][j] = dy[i - 1][j - 1] + t[i][j];
            }
            else {
                dy[i][j] = max(dy[i - 1][j], dy[i - 1][j - 1]) + t[i][j];
            }
        }
    }
    sort(dy[N - 1], dy[N - 1] + N);
    cout << dy[N - 1][N - 1];

	return 0;
}