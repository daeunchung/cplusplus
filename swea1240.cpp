///* 1240. [S/W 문제해결 응용] 1일차 - 단순 2진 암호코드 D3 */
//// 시간초과 발생 코드
//#include <iostream>
//#include <string.h>
//using namespace std;
//
////int code[10][7] = {
////	{0,0,0,1,1,0,1}, //0
////	{0,0,1,1,0,0,1}, //1
////	{0,0,1,0,0,1,1}, //2
////	{0,1,1,1,1,0,1}, //3
////	{0,1,0,0,0,1,1}, //4
////	{0,1,1,0,0,0,1}, //5
////	{0,1,0,1,1,1,1}, //6
////	{0,1,1,1,0,1,1}, //7
////	{0,1,1,0,1,1,1}, //8
////	{0,0,0,1,0,1,1}  //9
////};
//string str;
//
//string code[10] = { "0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011" };
//int arr[50][100];
//int num[7];
//int Deci[8];	// 십진수 암호코드
//int testCase, answer, r, c, a, b;
//
//int Decrypt()
//{
//	for (int i = 0; i < 10; i++) {
//		int count = 0;
//		for (int j = 0; j < 7; j++) {
//			if (num[j] == code[i][j]) count++;
//		}
//		if (count == 7) return i;
//	}
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> testCase;
//	for (int Tc = 1; Tc <= testCase; Tc++)
//	{
//		cin >> a >> b;
//		for (int i = 0; i < a; i++) {
//			for (int j = 0; j < b; j++) {
//				cin >> arr[i][j];
//			}
//		}
//
//		r = 0, c = 0;
//		for (int i = a - 1; i >= 0; i--)
//		{
//			if (r != 0 || c != 0) break;
//			for (int j = b - 1; j >= 0; j--)
//			{
//				if (arr[i][j] == 1)
//				{
//					r = i;
//					c = j;
//					break;
//				}
//			}
//		}
//
//		int idx = 0, idxx = 0;
//		for (int i = c - 55; i <= c; i++)
//		{
//			str += arr[r][i]; idx++;
//			//num[idx % 7] = arr[r][i];
//			if (idx % 7 == 6) {
//				Deci[idxx] = Decrypt();
//				idxx++;
//			}
//			idx++;
//		}
//
//		// 올바른 암호인지 검증
//		int n1 = 0, n2 = 0;
//		answer = 0;
//		n1 = Deci[0] + Deci[2] + Deci[4] + Deci[6];
//		n2 = Deci[1] + Deci[3] + Deci[5] + Deci[7];
//
//		if ((3 * n1 + n2) % 10 == 0) 
//			answer = n1 + n2;
//
//		cout << "#" << Tc << " " << answer << "\n";
//	}
//	return 0;
//}
