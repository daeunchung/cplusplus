#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {

    int r1 = arr1.size();
    int c1 = arr1[0].size();
    int r2 = arr2.size();
    int c2 = arr2[0].size();    // 연산 가능 => c1 == r2

    vector<vector<int>> answer(r1, vector<int>(c2));

    for (int r = 0; r < r1; r++) {
        for (int c = 0; c < c2; c++) {
            int sum = 0;
            for (int k = 0; k < r2; k++) {
                sum += arr1[r][k] * arr2[k][c];
            }
            answer[r][c] = sum;
        }
    }
    return answer;
}