///* 1232. [S/W 문제해결 기본] 9일차 - 사칙연산 D4 */
//// 이진트리를 구성한 다음 후위순회를 하는 문제
//// (9/(6-4))*3   ->  후위순회  9 6 4 - / 3 * 
//#include <iostream>
//using namespace std;
//int testCase = 10, N;
//int lc, rc;
//
//struct Node {
//	int data;
//	int left;
//	int right;
//};
//Node node[1001];
//
////void init() {
////	for (int i = 1; i <= N; i++) {
////		node[i].data = NULL;
////		node[i].left = NULL;
////		node[i].right = NULL;
////	}
////}
//
//int postorder(int v)
//{
//	if (node[v].data < 0)
//	{
//		int a = postorder(node[v].left);
//		int b = postorder(node[v].right);
//		if (node[v].data == -1) return a + b;
//		else if (node[v].data == -2) return a - b;
//		else if (node[v].data == -3) return a * b;
//		else if (node[v].data == -4) return a / b;
//	}else if( )
//	return node[v].data;
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	for (int i = 1; i <= testCase; i++)
//	{
//		cin >> N;	
//		// init();
//		for (int i = 1; i <= N; i++) {
//			char ch;
//			cin >> i >> ch;
//			if (ch >= '0' && ch <= '9')
//			{
//				node[i].data = 0;
//				while (ch >= '0' && ch <= '9') 
//				{ 
//					node[i].data = node[i].data * 10 + ch - '0'; 
//					ch = getchar(); 
//				}
//			}
//			else
//			{
//				if (ch == '+') node[i].data = -1; 
//				else if (ch == '-') node[i].data = -2;
//				else if (ch == '*') node[i].data = -3;
//				else if (ch == '/') node[i].data = -4;
//
//				cin >> lc >> rc;
//				node[i].left = lc;	
//				node[i].right = rc;
//			}
//		}
//		cout << "#" << i << " " << postorder(1) << "\n";
//	}
//	return 0;
//}