/*
백트랙킹은 N-Queens 문제처럼 여러개의 솔루션을 가진 문제에서 모든 방법을 탐색하는 것이다. 
대표적인 완전 탐색 방법으로는 DFS(깊이 우선 탐색)이 있다.
DFS는 재귀 호출을 이용해서 탐색할 수 있으며, depth가 깊더라도 탐색할 수 있다는 장점이 있다. 
하지만 굳이 목표가 있지 않는 경로까지 탐색하는 것은 비효율적이다. 
그래서 고안된 것이 백트래킹으로 DFS에서 더 이상 유망하지 않은 탐색경로를 배제하여 
비효율적인 탐색을 줄일 수 있다.

해결하지 못해서 
https://chanhuiseok.github.io/posts/baek-1/ 의 코드를 가져온 것 입니다. 
*/

#include <iostream>
using namespace std;

int n, count = 0;
int board[15];

// 유망한지 판단하는 함수
int promising(int cdx) {

	// 같은 열이면 안되고, 대각선상에 있어서도 안 된다.
	for (int i = 0; i < cdx; i++) {
		if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i])) {
			return 0;
		}
	}
	return 1;
}

// nqueen 알고리즘 수행
void nqueen(int cdx) {

	// cdx가 마지막 행까지 수행하고 여기까지 오면, 찾기 완료
	if (cdx == n) {
		::count++;
		return;
	}

	for (int i = 0; i < n; i++) {
		board[cdx] = i; // cdx번째 행, i번째 열에 queen을 놓아본다.	
		// 이후 그 행에 둔 것에 대한 유망성을 판단한다.
		if (promising(cdx)) { // 그 자리에 두어도 괜찮았다면,
			nqueen(cdx + 1); // 그 다음 행에 대해 퀸을 놓는 것을 해 본다.
		}
	}
}

int main() {

	cin >> n;
	nqueen(0);
	cout << ::count << '\n';
	return 0;
}