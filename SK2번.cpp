#include <iostream>
#include <string>
#include <vector>

using namespace std;
int n;

//int main(int money, vector<int> costs) {

int main() {
  
    cin >> n;
    bool clockwise;
    cin >> clockwise;
    vector<vector<int> > arr(n,vector<int>(n,0));

    int answer = 0;
    if (clockwise)
    {
        int num = 1, n1 = 0;
        while (n1 < n / 2 + 1)
        {
            int n2 = n1;
            while (n2 <= n - n1 - 1) {
                arr[n1][n2] = num;
                n2++;
                num++;
            }
            n1++;
        }
    }
}