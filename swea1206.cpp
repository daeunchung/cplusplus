#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int Tc, answer;
int arr[1001];

void clean()
{
	answer = 0;
	memset(arr, 0, sizeof(arr));
}

void setInput()
{
	cin >> Tc;
	for (int i = 0; i < Tc; i++) {
		cin >> arr[i];
	}
}

void solve()
{
	for (int i = 2; i < Tc-2; i++) {
		if (arr[i] - arr[i - 2] < 0 || arr[i] - arr[i - 1] < 0 || arr[i] - arr[i + 1] < 0 || arr[i] - arr[i + 2] < 0) {
			continue;
		}
		answer += min({ arr[i] - arr[i - 2], arr[i] - arr[i - 1], arr[i] - arr[i + 1], arr[i] - arr[i + 2] });
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 10; i++) {
		clean();
		setInput();
		solve();
		cout << "#" << i << " " << answer << "\n";
	}
	return 0;
}