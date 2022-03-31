//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
//
//int n;  long long num;
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
//	for(int i=0; i< n; i++)
//	{
//		cin >> num;
//		turn = i % 2;
//		//turn = false;	// ¹«Á¶°Ç »óÀ±¸ÕÀú start
//		search(num);
//		cout << !turn << '\n';
//	}
//	return 0;
//}