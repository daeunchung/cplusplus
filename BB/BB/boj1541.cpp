#include <iostream>
#include <string>
using namespace std;

int solution(string s) {
	int answer = 0;
	bool minus = false;
	string temp = "";

	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
			if (minus)
				answer -= stoi(temp);
			else
				answer += stoi(temp);
			temp = "";
			if (s[i] == '-')
				minus = true;
		}
		else {
			temp += s[i];
		}
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;
	cout << solution(s);

	return 0;
}