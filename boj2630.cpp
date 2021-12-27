/* 분할 정복 */
#include <iostream>
using namespace std;
int N, WHITE, BLUE;
bool map[129][129];

void DivideAndConquer(int ys, int xs, int ye, int xe)
{
	int check = map[ys][xs];
	for (int i = ys; i < ye; i++) {
		for (int j = xs; j < xe; j++) {
			if (check == 0 && map[i][j])  check = 2;
			else if (check && !map[i][j]) check = 2;
			if (check == 2) {
				DivideAndConquer(ys, xs, (ys + ye) / 2, (xs + xe) / 2);
				DivideAndConquer(ys, (xs + xe) / 2, (ys + ye) / 2, xe);
				DivideAndConquer((ys + ye) / 2, xs, ye, (xs + xe) / 2);
				DivideAndConquer((ys + ye) / 2, (xs + xe) / 2, ye, xe);
				return;
			}
		}
	}
	if (check == 0) ++WHITE;
	else if (check == 1) ++BLUE;
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	DivideAndConquer(0, 0, N, N);
	cout << WHITE << '\n' << BLUE << '\n';
	return 0;
}