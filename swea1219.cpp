/* 1219. [S/W 문제해결 기본] 4일차 - 길찾기 D4 */
#include <iostream>
#include <string.h>
using namespace std;
int testCase = 10, answer, a, b, cnt;
int arr[100][2];

void Initialize()
{
	for (int i = 0; i < 100; i++)
	{
		memset(arr[i], 0, sizeof(int) * 2);
	}
}

void Search(int start)
{
	if (arr[start][0] == 99 || arr[start][1] == 99)
	{
		answer = 1;
		return;
	}
	if (!answer && arr[start][0] != 0) Search(arr[start][0]);
	if (!answer && arr[start][1] != 0) Search(arr[start][1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int Tc = 1; Tc <= testCase; Tc++)
	{
		Initialize();
		answer = 0;
		cin >> Tc >> cnt;
		for (int i = 0; i < cnt; i++)
		{
			cin >> a >> b; 
			if (arr[a][0] == 0) arr[a][0] = b;
			else arr[a][1] = b;
		}
		Search(0);
		cout << "#" << Tc << " " << answer << "\n";
	}
	return 0;
}