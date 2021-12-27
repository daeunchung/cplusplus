#include <map>
#include <iostream>
#include <string>
#include <algorithm>
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
		num = 0;
		cin >> str;
		try {
			num = stoi(str);
		}
		catch (invalid_argument&) {}

		if(num) 
			cout << Pokedex1.find(num)->second << endl;
		else 
			cout << Pokedex2.find(str)->second << endl;
	}
	return 0;
}