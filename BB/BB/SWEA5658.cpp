//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//int N, K, oneSide, ans;
//vector<char> v[4];
//vector<int> result;
//
//void Initialize()
//{
//	for (int i = 0; i < 4; i++)
//		v[i].clear();
//	result.clear();
//	ans = 0;
//}
//
//void Input()
//{
//	cin >> N >> K;
//	string instr;
//	cin >> instr;
//	oneSide = N / 4;
//	int idx = 0, cnt = 0;
//
//	for (int i = 0; i < N; i++) {
//		char tmp = instr[i];
//
//		v[idx].emplace_back(tmp);
//		cnt++;
//		if (cnt == oneSide) {
//			idx++;	cnt = 0;
//		}
//	}
//}
//
//void Rotate()
//{
//	/* 보물 상자를 시계 방향으로 회전시켜 보는 함수 */
//	char head = v[0].at(0);
//	char tail = v[3].at(oneSide - 1);
//
//}
//
//bool DuplicationCheck(int num)
//{
//	for (int i = 0; i < result.size(); i++) {
//		if (result[i] == num) return true;
//	}
//	return false;
//}
//
//void ConvertToDecimal()
//{
//	
//
//}
//
//void Solve() {
//	int Tc; cin >> Tc;
//	for (int T = 1; T <= Tc; T++)
//	{
//		Initialize();
//		Input();
//		Solution();
//
//		cout << "#" << T << " " << ans << "\n";
//	}
//}
//
//int main(void)
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	freopen("input.txt", "rt", stdin);
//	Solve();
//
//	return 0;
//}