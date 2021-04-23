//#include <iostream>
//#include <string>
//#include <vector>
//#include <set>
//#include <math.h>
//using namespace std;
///* 틀린거 겁 나 많 음 */
//int T, N, K, side;
//
//struct compare
//{
//	bool operator()(const string& a, const string& b) {
//		int idx = 0;
//		while (idx < side)
//		{
//			if (a[idx] < b[idx])
//				return a < b;
//			else if(a[idx] > b[idx])
//				return a > b;
//			else {
//				idx++;
//				continue;
//			}
//		}
//	}
//};
//
//vector<char> v;
////set<string, greater<string>> s;		// default : 오름차순 set<string, less<string> >
//set<string, compare> s;
//string str, temp;	int cnt = 0;
//
//void Rotate()
//{
//	char last = v.back();
//	v.pop_back();
//	v.emplace(v.begin(), last);
//}
//
//void InsertToSet()
//{
//	for (int i = 0; i < N; i++) {
//		temp += v[i];
//		cnt++;
//		if (cnt == side) {
//			s.insert(temp);
//			temp = "";	cnt = 0;
//		}
//	}
//}
//
//int HexToDec(const string& str)
//{
//	int answer = 0;
//	for (int i = 0; i<side; i++)
//	{
//		answer += (int)(str[i] * pow(16.0, (double)i));
//	}
//	return answer;
//}
//
//int main() {
//	cin >> T >> N >> K;
//	side = N / 4;
//	for (; T--;)
//	{
//		v.clear();	s.clear();
//		cin >> str;
//		for (int i=0; i<N; i++)
//			v.emplace_back(str[i]);
//		InsertToSet();
//
//		for (int i = 0; i < 2; i++) {
//			Rotate();
//			InsertToSet();
//		}
//		set<string>::iterator iter = s.begin();
//		cnt = 0;
//		while (cnt < K) {
//			++iter; 
//			cnt++;
//		}
//		const string ansstr = *iter;
//		cout << HexToDec(ansstr) << '\n';
//	}
//	return 0;
//}