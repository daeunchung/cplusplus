#include <map>
#include <iostream>
#include <string>
using namespace std;

int n, p, num;
string str;
map<int, string> Pokedex1;
map<string, int> Pokedex2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	cin >> n >> p;

	for (int i = 0; i < n; i++) {
		cin >> str;
		Pokedex1[i + 1] = str;
		Pokedex2[str] = i + 1;
	}
	for (int i = 0; i < p; i++)
	{
		cin >> str;

		if (atoi(str.c_str()) == 0)
			cout << Pokedex2[str] << '\n';
		else
			cout << Pokedex1[atoi(str.c_str())] << '\n';
	}
	return 0;
}

/* 입력이 숫자인지 문자인지를 확인하려면 atoi(s.c_str())를 해서 
0이 라면 그것은 문자열인 셈이 된다. ( 하지만 이 방법으로 0은 체크할 순없다.) 

atoi("문자") : 문자가 맨처음 나왔기 때문에 0을 반환합니다.
atoi("숫자") : 숫자를 반환합니다. */
