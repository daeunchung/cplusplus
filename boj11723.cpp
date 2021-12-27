#include <iostream>
#include <string>
using namespace std;

bool arr[21];
int M, x;
string str;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (str == "add") {
			cin >> x;
			arr[x] = 1;
		}
		if (str == "remove") {
			cin >> x;
			arr[x] = 0;
		}
		if (str == "check") {
			cin >> x;
			if (arr[x]) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
		if (str == "toggle") {
			cin >> x;
			if (arr[x]) arr[x] = 0;
			else arr[x] = 1;
		}
		if (str == "all") {
			for (int i = 1; i < 21; i++) arr[i] = 1;
		}
		if (str == "empty"){
			for (int i = 1; i < 21; i++) arr[i] = 0;
		}
	}
}