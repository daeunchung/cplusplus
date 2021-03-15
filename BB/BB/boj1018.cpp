#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cB, cW, minn = 64;
int main() {
	int a, b;
	cin >> a >> b;
	vector<vector<char> > v(a, vector<char>(b, 0));
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
			cin >> v[i][j];

	for (int i = 0; i < a - 7; i++) {
		for (int j = 0; j < b - 7; j++) {
			cB = 0; cW = 0;

			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if ((i + k + j + l) % 2 == 0 && v[i + k][j + l] == 'W') cB++;
					if ((i + k + j + l) % 2 == 1 && v[i + k][j + l] == 'B') cB++;
				}
			}
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					if ((i + k + j + l) % 2 == 0 && v[i + k][j + l] == 'B') cW++;
					if ((i + k + j + l) % 2 == 1 && v[i + k][j + l] == 'W') cW++;
				}
			}
			if (min(cB, cW) < minn) minn = min(cB, cW);
		}
	}

	cout << minn << '\n';
	return 0;

}