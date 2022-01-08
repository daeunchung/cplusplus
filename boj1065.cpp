#include <iostream>
using namespace std;
bool func(int a) {
    if (a < 100)
        return true;
    int a1, a2, a3;
    a1 = a / 100;
    a3 = a % 10;
    a2 = a % 100 / 10;
    if (a1 - a2 == a2 - a3)
        return true;
    return false;
}
int main(void) {
    int N, count = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        if (func(i))
            count++;
    }
    cout << count;
}