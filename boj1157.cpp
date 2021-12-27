#include <iostream>
#include <string>
using namespace std;
int arr[26];
int cnt, idx;

int main() { 
	int k, max=-1;
	string st;
	cin >> st;
	for (int i = 0; i < st.size(); i++) {
		if (65 <= st[i] && st[i] <= 90)
			k = st[i] - 65;
		else
			k = st[i] - 97;
		arr[k]++;
		if (arr[k] >= max) {
			max = arr[k];
			idx = k;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] == max) cnt++;
	}
	if (cnt != 1) cout << "?";
	else cout<< (char)(idx + 65);

	return 0;
}