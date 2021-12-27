//// 시간초과 
//// 치킨톤 E
 
//#include <string>
//#include <iostream>
//using namespace std;
//int N, Q;
//bool sg, yw;
//int menu[100000][2];
//int range[5000][4];
//int main()
//{
//	ios_base::sync_with_stdio(false); 
//	cin.tie(nullptr);
//
//	cin >> N >> Q;
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> menu[i][0];
//		cin >> menu[i][1];
//	}
//	for (int i = 1; i <= Q; i++)
//	{
//		cin >> range[i][0];
//		cin >> range[i][1];
//		cin >> range[i][2];
//		cin >> range[i][3];
//	}
//
//	for (int i = 1; i <= Q; i++)
//	{
//		int cnt = 0;
//		for (int j = 1; j <= N; j++) {
//			sg = false;	yw = false;
//			if (range[i][0] <= menu[j][0] && menu[j][0] <= range[i][1]) sg = true;
//			if (range[i][2] <= menu[j][1] && menu[j][1] <= range[i][3]) yw = true;
//			if (sg && yw) cnt++;
//		}
//		cout << cnt << '\n';
//	}
//}
//
