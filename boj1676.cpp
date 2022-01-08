/* 실제로 N! 의 값을 구하기는 힘들다 C++도 자료형 큰거 써야하고, Java는 BigInteger 사용, Python은 숫자길이 무제한이지만 실제로 구하기는 불가능
숫자가 매우 길면 덧셈의 시간복잡도가 O(1)이라고 할 수 없다. 그냥 하지말고 2*5 쌍의 갯수를 찾는게 해결방법 */

#include <iostream>
using namespace std;
int n, ans;
int main()
{
	cin >> n;
	int d = 5;
	while (d <= n)
	{
		ans += n / d;
		d *= 5;
	}
	cout << ans << '\n';
	return 0;
}