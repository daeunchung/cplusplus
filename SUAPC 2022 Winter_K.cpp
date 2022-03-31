//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
////vector<char> v;
//char v[100000];
//int s;
//bool check(int idx)
//{
//	int a = 0;
//	for (int j = 0; j < s; ++j)
//	{
//		if (j == idx) continue;
//		if (v[j] == '(') a++;
//		else if (v[j] == ')') a--;
//		if (a < 0) return false;
//	}
//	if (a == 0) return true;
//	else return false;
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);	cin.tie(nullptr); cout.tie(nullptr);
//	string str;
//	cin >> str;
//	s = str.size();
//	int cnt = 0;
//	for (int i = 0; i < str.size(); i++)
//		v[i] = str[i];
//	
//	for (int i = 0; i < str.size(); i++) {
//		if (check(i)) cnt++;
//	}
//	cout << cnt << '\n';
//	return 0;
//}