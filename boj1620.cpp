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

/* �Է��� �������� ���������� Ȯ���Ϸ��� atoi(s.c_str())�� �ؼ� 
0�� ��� �װ��� ���ڿ��� ���� �ȴ�. ( ������ �� ������� 0�� üũ�� ������.) 

atoi("����") : ���ڰ� ��ó�� ���Ա� ������ 0�� ��ȯ�մϴ�.
atoi("����") : ���ڸ� ��ȯ�մϴ�. */
