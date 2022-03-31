#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	int n1, n2, n3, ans = 1;
	cin >> n1 >> n2 >> n3;
	
	while (ans > 0)
	{
		if ((ans - n1) % 15 == 0 && (ans - n2) % 28 == 0 && (ans - n3) % 19 == 0) {
			break;
		}
		ans++;
	}
	cout << ans << '\n';
	return 0;
}

/*
중국인의 나머지 정리로 풀이 방법
#include <iostream>
using namespace std;
int main() {
	int e,s,m;
	cin >> e >> s >> m;
	cout << (6916*e + 4845*s + 4200*m - 1) % (15*28*19) + 1 << '\n';
	return 0;
}
*/