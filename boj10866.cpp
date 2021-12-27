//// 0ms 하지 못했다 4ms 코드임 . 어디가 시간을 잡아먹는걸까
//#include <iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//vector<int> s;
//vector<int>::iterator iter;
//
//void push_front(int x) {
//	iter = s.begin();
//	s.insert(iter, x);
//}
//void push_back(int x) {
//	s.push_back(x);
//}
//int pop_front() {
//	if (s.empty()) return -1;
//	int  x = s[0];
//	s.erase(s.begin());
//	return x;
//}
//int pop_back() {
//	if (s.empty()) return -1;
//	int  x = s[s.size() - 1];
//	s.pop_back();
//	return x;
//}
//int size() {
//	return s.size();
//}
//int empty() {
//	return s.empty();
//}
//int front() {
//	if (s.empty()) return -1;
//	return s[0];
//}
//int back() {
//	if (s.empty()) return -1;
//	return s[s.size() - 1];
//}
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	int n, num;
//	string str;
//	cin >> n;
//	for (; n--;) {
//		cin >> str;
//		if (str == "push_front") {
//			cin >> num;
//			push_front(num);
//		}
//		else if (str == "push_back") {
//			cin >> num;
//			push_back(num);
//		}
//		else if (str == "pop_front")
//			cout << pop_front() << '\n';
//		else if (str == "pop_back")
//			cout << pop_back() << '\n';
//		else if (str == "size")
//			cout << size() << '\n';
//		else if (str == "empty")
//			cout << empty() << '\n';
//		else if (str == "front")
//			cout << front() << '\n';
//		else if (str == "back")
//			cout << back() << '\n';
//	}
//	return 0;
//}