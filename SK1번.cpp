#include <iostream>
#include <string>
#include <vector>

using namespace std;
int unit[6] = { 1, 5, 10, 50, 100, 500 };
int d[7][1000001];  // d[0~5] : coin, d[6] : minvalue
int money, val;
vector<int> costs;

//int main(int money, vector<int> costs) {

int main(){
    cin >> money;
    for (int i = 0; i < 6; i++) {
        cin >> val;
        costs.push_back(val);
    }

    int answer = 0;

    for (int i = 1; i < 1000001; i++) {

        int mincost = 2147000000, mincoin = -1;
        for (int j = 0; j < 6; j++) {
            if (i - unit[j] >= 0 && d[6][i - unit[j]] + costs[j] < mincost)
            {
                mincost = d[6][i - unit[j]] + costs[j];
                mincoin = j;
            }
        }
        d[6][i] = mincost;
    }

    return d[6][money];
}