#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    int ans = 0;
    cin >> str;
    for (char ch : str)
    {
        if (ch == 'A' || ch == 'B' || ch == 'C') ans += 3;
        else if (ch == 'D' || ch == 'E' || ch == 'F') ans += 4;
        else if (ch == 'G' || ch == 'H' || ch == 'I') ans += 5;
        else if (ch == 'J' || ch == 'K' || ch == 'L') ans += 6;
        else if (ch == 'M' || ch == 'N' || ch == 'O') ans += 7;
        else if (ch == 'P' || ch == 'Q' || ch == 'R' || ch == 'S') ans += 8;
        else if (ch == 'T' || ch == 'U' || ch == 'V') ans += 9;
        else if (ch == 'W' || ch == 'X' || ch == 'Y' || ch == 'Z') ans += 10;
    }
    cout << ans << '\n';
}