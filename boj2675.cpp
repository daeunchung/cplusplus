#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int r;
        string p;
        cin >> r;
        cin >> p;
        for(int j = 0;j < p.length();j++){
            for(int k = 0;k < r;k++){
                cout << p[j];
            }
        }
        cout << endl;
    }
    return 0;
}
