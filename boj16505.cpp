#include <iostream>
using namespace std;
/*
사용하는 칸수
1-> 2*2
2-> 4*4
3-> 8*8
...
10 -> 1024*1024
 이 방법도 복습 필요 (kks227님 코드) 

Q. cout 출력으로 별찍고 출력커서를 원위치 하는 법은 없을까?
*/
bool map[1024][1024];
int N;

void star(int n, int r, int c)
{
	if (n == 0) {
		map[r][c] = true;
		return;
	}
	int k = 1 << n - 1;
	star(n - 1, r, c);
	star(n - 1, r+k, c);
	star(n - 1, r, c + k);
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	star(N, 0, 0);
	for (int i = 0; i < 1 << N; ++i) {
		for (int j = 0; j < (1 << N) - i; ++j)
			putchar(map[i][j] ? '*' : ' ');
		puts("");
	}
	return 0;
}