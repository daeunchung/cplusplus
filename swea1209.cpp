/* 1209. [S/W 문제해결 기본] 2일차 - Sum D3 */
#include <iostream>
using namespace std;
int arr[100][100];
int Tc, sum, maxx, N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (Tc = 1; Tc <= 10; Tc++)
	{
		cin >> N;
		maxx = 0;
		for (int i = 0; i < 100; i++) 
			for (int j = 0; j < 100; j++) 
				cin >> arr[i][j];

		for (int i = 0; i < 100; i++) {
			sum = 0;
			for (int j = 0; j < 100; j++) {
				sum += arr[i][j];
			}
			if (maxx <= sum) maxx = sum;
		}
		sum = 0;
		for (int i = 0; i < 100; i++) {
			sum = 0;
			for (int j = 0; j < 100; j++)
				sum += arr[j][i];
			if (maxx <= sum) maxx = sum;
		}

		sum = 0;
		for (int i = 0; i < 100; i++)
			sum += arr[i][i];
		if (maxx <= sum) maxx = sum;

		sum = 0;
		for (int i = 0; i < 100; i++)
			sum += arr[99 - i][i];
		if (maxx <= sum) maxx = sum;

		cout << "#" << Tc << " " << maxx << "\n";
	}
	return 0;
}