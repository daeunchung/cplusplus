#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, ans = 0;
	char ch;
	cin >> T;
	while (T--)
	{
		cin >> ch;
		ans += ch - 48;
	}
	cout << ans << '\n';
	return 0;
}

/*
#include <cstdio>
int main(){
	int n, t, s=0;
	scanf("%d ", &n);
	while(~scanf("%1d", &t)) s+=t;
	printf("%d",s);
	return 0;
}
*/