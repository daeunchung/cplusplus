/* B�� ũ�Ⱑ �ִ� 2,147,483,647�ε� �� ���� for���� ����Ͽ� �״�� 2,147,483,647�� �ݺ��Ѵٸ� �뷫 1����� �ݺ��� 1�ʶ� ���������� 21�ʳ� �ɸ��� �Ǿ� ������ �ð������� 2�ʸ� �ξ� �ѱ�� �ǹ����ϴ�.
���� �� ������ for���� ������� �ʰ� �Լ��� ��͸� �̿��ϴ� �������� �˰����� �̿��Ͽ� Ǯ��� O(log n)�� �ð����⵵�� ������ �ǰ� ������ �ִ밪�� ���͵� �ٷ� ������� ��Ÿ���� �ֽ��ϴ�.
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
// ���� ���� �ŵ��������� ����Ѵ�.
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
