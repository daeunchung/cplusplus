/* 1217. [S/W �����ذ� �⺻] 4���� - �ŵ� ���� D3 */
#include <iostream>
using namespace std;
char arr[100][100];
int testCase = 10, answer, a,b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int Tc = 1; Tc <= testCase; Tc++)
	{
		answer = 1;
		cin >> Tc >> a >> b;
		for (int i = 0; i < b; i++) answer *= a;
		cout << "#" << Tc << " " << answer << "\n";
	}
	return 0;
}