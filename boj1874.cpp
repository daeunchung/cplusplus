// 21-12-21 스택수열 어려웠음
#include <iostream>
#include <string>
#include <stack>
using namespace std;
/* 
* 1 2 3 ... n 순서대로 push한다 
=> 주의 인풋으로 받으려고 하지말고, 어짜피 1씩 증가하는 형태니까 "값을 증가한다, 증가안한다" 변수 값으로 관리

pop 할때마다 수열에 하나의 수를 적어준다
* input m : 1 2 3 4 5 6 7 8 (들어오는 순서와 값이 정해져있으니 인풋으로 받지말고 변수로 관리) 
차례대로 x : 4 3 6 8 7 5 2 1 
수열의 수 a[i]가 만들어지려면 stack 에는 1~a[i]가 모두 push가 되어있는 상태여야 한다
수열의 수 x가 stack의 top보다 작으면 x는 이미 스택에 들어가있는데 바로 뺄 수 없기 때문에 수열 불가능
수열의 수 x가 stack의 top보다 크면 x이전의 수 (x보다 작은 수들)전부 push하고 
*/

string ans = "";
int n, x, m = 0;
bool f = true;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<int> s;
	cin >> n;

	while (n--) {
		cin >> x;
		if (x > m)
		{
			while (x > m) {
				s.push(++m); ans += "+";
			}
			s.pop(); ans += "-";
		}
		else // 이미 x가 스택에 들어가있다
		{
			if (!s.empty())
			{
				if (x == s.top()) {
					s.pop(); ans += "-";
					//continue;
				}
				else {
					f = false;
					cout << "NO" << '\n';
					return 0;
				}
			}
		}
	}
	if (f) {
		for (char ch : ans)
			cout << ch << '\n';
	}
	return 0;
}