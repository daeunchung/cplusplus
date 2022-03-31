//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
//
//long long n;  
//long long num;
//bool turn;	// 0 »óÀ± 1 ½Â¿ì
//
//bool isPalindrome(long long x)
//{
//	string str = to_string(x);
//	int len = str.length();
//	if (len == 1) return true;
//
//	len--;
//	for (int i = 0; i < len; i++)
//	{
//		if (str[i] != str[len - i]) return false;
//	}
//	return true;
//}
//
//void search(long long i)
//{
//	if (i <= 0) return;
//	long long newpick = i;
//	while (newpick)
//	{
//		if (isPalindrome(newpick)) {
//			turn = !turn;
//			return search(i - newpick);
//		}
//		newpick--;
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);	cin.tie(nullptr); cout.tie(nullptr);
//
//	cin >> n;
//	//long long tn = n;
//	//int cnt = 0;	// ÀÚ¸´¼ö
//	//while (tn) {
//	//	cnt++;
//	//	tn /= 10;
//	//}
//
//	long long ans = 0;
//	long long div = 11;
//	while (div <= n) {
//		ans += (n / div);
//		div = div * 10 + 1;
//	}
//	cout << ans;
//
//	return 0;
//}
//111111111
//11213132
//11020111
//
//
//111111111 8 
//11 
//1111
//111111
//11111111
//
//111
//
