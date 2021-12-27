/* B의 크기가 최대 2,147,483,647인데 이 수를 for문을 사용하여 그대로 2,147,483,647번 반복한다면 대략 1억번의 반복을 1초라 생각했을때 21초나 걸리게 되어 문제의 시간제한인 2초를 훨씬 넘기게 되버립니다.
따라서 이 문제는 for문을 사용하지 않고 함수의 재귀를 이용하는 분할정복 알고리즘을 이용하여 풀어야 O(log n)의 시간복잡도를 가지게 되고 문제의 최대값이 들어와도 바로 결과값을 나타낼수 있습니다.
*/
/* 
& operator: It is a bit-wise AND operator:
Now, if you would AND the number(binary representation) with 1(binary representation) the output would either be 0 or 1.
2.1. For even number: remainder would be 0
example: 4&1=0
0100 (4)
0001 (1)
0000 (Result of bit-wise AND)
2.2. For odd number: remainder would be 1
example: 5&1=1
0101 (5)
0001 (1)
0001 (Result of bit-wise AND)
*/
#include <iostream>
using namespace std;

using ULL = unsigned long long;
// typedef long long ll;
ULL A, B, C;
// 빠른 모듈로 거듭제곱법을 사용한다.
ULL Power(ULL a, ULL b, ULL c)
{
    if (b == 0)
        return 1;
    if (b == 1) 
        return a % c;
    ULL temp = Power(a, b / 2, c);

    if (b & 1) return temp * temp % c * a % c;
    else return temp * temp % c;
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
    cin >> A >> B >> C;
    cout << Power(A, B, C);
    return 0;
}
