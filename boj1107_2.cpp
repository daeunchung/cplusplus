/*
* 기존의 내 풀이방법은 브루트포스가 아니고
* input n 하나만 버튼 유무에 따라 수행 동작이 달라지는 식으로 구현했다.
* 버튼check 는 문자열 <-> 숫자 변환해가며 검사하는 (1)방식으로 했으나 해결X

* 
* 백준님 풀이 브루트 포스
* 채널의 이동 100(시작) -> C(숫자만사용해서 만든) -> N(C에서+-를사용해서 만든)
 1. 이동할 채널 C를 지정 ( 0<=N<=500,000 이지만 0<=C<=1,000,000 ) 이걸 생각해 내는 것이 까다로운 부분 
 e.g.) 500,000 에 1,5 만 가지고 갈 경우
 2. C에 포함되어 있는 숫자 중에 고장난 버튼이 있는지 확인
	고장난 버튼이 있으면 숫자버튼만 가지고 C를 절대 만들 수 없기에 3.에서 아예 배제
 3. 고장난 버튼이 포함되어 있지 않다면 abs(C-N) 을 계산해 +나 -버튼을 몇 번 눌러야 하는지를 계산


 C에 포함되어있는 숫자 중에 고장난 버튼이 있는지 확인
 (1) 수를 문자열로 바꾼 다음, 한 글자씩 검사하는 방법
 (2) 수를 10으로 계속해서 나누면서 하나씩 검사하는 방법 ( % / % / % /... 을 반복하는 식)

*/

#include <iostream>
using namespace std;
bool broken[10];

int possible(int c)
{
	if (c == 0) {
		if (broken[0])
			return 0;
		else
			return 1;
	}
	int len = 0;
	while (c > 0)
	{
		if (broken[c % 10])
			return 0;
		len += 1;
		c /= 10;
	}
	return len;
}
int main() {
	int n;	cin >> n;
	int m;	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		broken[x] = true;
	}
	int ans = n - 100;
	if (ans < 0) {
		ans = -ans;
	}

	// 모든 0<=C<=1,000,000 에 대해 모두 검사한다 
	// (이 부분이 브루트포스. 이렇게 for문 세울 생각도 안해봐서 당황스러웠음. 
	// '전부 다 해보기' 라는 것은 알고 있었지만 C에 대해 수행해야 한다고 생각을 못했었다 ) 
	for (int i = 0; i <= 1000000; i++) {
		int c = i;
		int len = possible(c);
		if (len > 0) {
			int press = c - n;
			if (press < 0) {
				press = -press;
			}
			if (ans > len + press) {
				ans = len + press;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}