#include <iostream>
using namespace std;
long long arr[91] = { 0,1, };
long long fibo(int N)
{
    if (N == 0 || N == 1)
        return arr[N];
    else if (arr[N] == 0)
        arr[N] = fibo(N - 1) + fibo(N - 2);
    return arr[N];
}
int main() {
    int N;
    cin >> N;
    cout << fibo(N);
}