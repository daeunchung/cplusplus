/*
boj9095.cpp, boj9095_2.cpp : bottomup DP
boj9095_3.cpp : N중 for문
boj9095_4.cpp : 재귀

재귀로 브루트포스 사용시 모든 경우 탐색 필요 (불가능경우, 정답찾은 경우, 다음호출경우)

*/
#include <iostream>
using namespace std;
int goal;

int go(int sum)
{
    if (sum > goal) return 0;
    if (sum == goal) return 1;
    int now = 0;
    for (int i = 1; i <= 3; i++)
    {
        now += go(sum + i);
    }
    return now;
}
int main()
{
    ios_base::sync_with_stdio(false);   cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--)
    {
        cin >> goal;
         cout << go(0) << '\n';
    }
}