///*
//모듈러 연산의 속성
//1. (a + b) mod n = {(a mod n) + (b mod n)} mod n
//2. (a - b) mod n = {(a mod n) - (b mod n)} mod n
//3. (a * b) mod n = {(a mod n) * (b mod n)} mod n
//*/
//#include <iostream>
//#include <string>
//
//using namespace std;
//const int MOD = 1234567891;
//
//int pow(int a, int b) {	// 일반적으로 O(n) => 고찰해서 O(logn)으로 만듬
//	if (b == 0) return 1;
//	else if (b % 2 == 0) {
//		int n = pow(a, b / 2);
//		return n * n;
//	}
//	else {
//		int n = pow(a, (b-1) / 2);
//		return a * n * n;
//	}
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);	cin.tie(NULL);
//	int n, r = 1;
//	int ans = 0;
//	string str;
//	cin >> n >> str;
//	for (int i = 0; i < n; i++) {
//		ans += ((str[i] - 'a' + 1) * r) % MOD;
//		r = r * 31 % MOD;
//	}
//	cout << ans << '\n';
//	return 0;
//}