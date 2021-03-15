#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int cnt, h, w, n;
	cin >> cnt;
	for (; cnt--;) {
		cin >> h >> w >> n;
		if (n % h == 0) cout << 100 * h + (n / h) << '\n';
		else cout << 100 * (n % h) + (n / h) + 1 << '\n';
	}
	return 0;
}
// '틀렸습니다' 7번 나온 문제 ^^ 결국 해결
// '틀렸습니다' 는 진짜 '출력 결과가 틀렸을 경우에 나오는 결과'이니 내 답이 맞았을꺼라는 확신에 차서 건방 떨지 말고 찬찬히 다시 풀어보자