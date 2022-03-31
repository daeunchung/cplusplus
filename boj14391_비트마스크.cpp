// 풀이 1 비트마스크  https://regularmember.tistory.com/90
// 가로로 자를 경우0, 세로로 자를 경우1 :: 2가지뿐이라서 비트마스킹 가능
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int arr[5][5];
int N, M;	char ch;
//2 3
//123
//312
//=> 123312 로 간주
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ch;
			arr[i][j] = ch - '0';
		}
	}
 	
	int ans = 0;
	for (int b = 0; b < (1 << (N * M)); b++) {
		int sum = 0;
		
		// 가로 0
		for (int i = 0; i < N; i++) {
			int tmp = 0;
			for (int j = 0; j < M; j++) {
				// 한줄로 이어붙였을 때 인덱스
				int k = i * M + j;
				// k번째 자리값이 0 (가로)
				if ((b & (1 << k)) == 0) {
					tmp = tmp * 10 + arr[i][j];
				}
				else {	// 가로끝, 세로시작 (앞에까지 만들어진 조각만 sum에 더해)
					sum += tmp;
					tmp = 0;
				}
			}
			// 한 행 종료
			sum += tmp;
		}

		// 세로 1
		for (int j = 0; j < M; j++) {
			int tmp = 0;
			for (int i = 0; i < N; i++) {
				// 한줄로 이어붙였을 때 인덱스
				int k = i * M + j;
				// k번째 자리값이 1 (세로)
				if ((b & (1 << k)) != 0) {
					tmp = tmp * 10 + arr[i][j];
				}
				else {	// 세로끝, 가로시작 (앞에까지 만들어진 조각만 sum에 더해)
					sum += tmp;
					tmp = 0;
				}
			}
			// 한 행 종료
			sum += tmp;
		}

		// for(int b...)문의 sum 들 중에 최댓값 저장
		if (ans < sum) ans = sum;
	}

	cout << ans << '\n';
	return 0;
}
