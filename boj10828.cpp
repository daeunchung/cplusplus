#include <iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> s;

void push(int x) {
	s.push_back(x);
}

int pop() {
	if (s.empty()) return -1;
	int  x = s[s.size()-1];
	s.pop_back();
	return x;
}
int size() {
	return s.size();
}
int empty() {
	return s.empty();
}
int top() {
	if (s.empty()) return -1;
	return s[s.size()-1];
}

int main() {
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, num;
	string str;
	cin >> n;
	for (; n--;) {
		cin >> str;
		if (str == "push") {
			cin >> num;
			push(num);
		}
		else if (str == "pop") 
			cout << pop() << '\n';
		else if (str == "size") 
			cout << size() << '\n';
		else if (str == "empty") 
			cout << empty() << '\n';
		else if (str == "top") 
			cout << top() << '\n';
	}
	return 0;
}