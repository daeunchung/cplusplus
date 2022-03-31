/*
N중 for문
N개 중에 일부를 선택해야 하는 경우에 많이 사용
재귀, 비트마스크를 사용하면 더 간결하고 좋은 코드 라서 거의 사용X

추천X 그냥 _1, _2.cpp 로 풀고 그냥 이런 방법도 있다 ~ 정도만 알아둔다

문제 조건이 N <= 10 라서 브루트 포스 가능한 것
사용할 수 있는 1, 2, 3 의 개수는 10개보다 작거나 같다
1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 10
첫번째 위치에 올 수 있는 1, 2, 3 다 해보고
2번째 위치에 올 수 있는 1, 2, 3 다 해보고
3번째 위치에 올 수 있는 1, 2, 3 다 해보고 ... 10중 for문 돌기
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int ans = 0;
        int n;
        scanf("%d", &n);
        for (int l1 = 1; l1 <= 3; l1++) {
            if (l1 == n) ans += 1;
            for (int l2 = 1; l2 <= 3; l2++) {
                if (l1 + l2 == n) ans += 1;
                for (int l3 = 1; l3 <= 3; l3++) {
                    if (l1 + l2 + l3 == n) ans += 1;
                    for (int l4 = 1; l4 <= 3; l4++) {
                        if (l1 + l2 + l3 + l4 == n) ans += 1;
                        for (int l5 = 1; l5 <= 3; l5++) {
                            if (l1 + l2 + l3 + l4 + l5 == n) ans += 1;
                            for (int l6 = 1; l6 <= 3; l6++) {
                                if (l1 + l2 + l3 + l4 + l5 + l6 == n) ans += 1;
                                for (int l7 = 1; l7 <= 3; l7++) {
                                    if (l1 + l2 + l3 + l4 + l5 + l6 + l7 == n) ans += 1;
                                    for (int l8 = 1; l8 <= 3; l8++) {
                                        if (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 == n) ans += 1;
                                        for (int l9 = 1; l9 <= 3; l9++) {
                                            if (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 == n) ans += 1;
                                            for (int l0 = 1; l0 <= 3; l0++) {
                                                if (l1 + l2 + l3 + l4 + l5 + l6 + l7 + l8 + l9 + l0 == n) ans += 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}