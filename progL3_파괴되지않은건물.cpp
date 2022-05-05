#include <string>
#include <vector>

using namespace std;
// type 1 적군(-) /  type 2 아군(+) / 풀이법 : DP

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    int N = board.size();
    int M = board[0].size();
    vector<vector<int>> delta(N + 2, vector<int>(M + 2)); // 변화량 누적합 배열

    for (auto v : skill) {
        int type = v[0];
        int r1 = v[1], c1 = v[2];
        int r2 = v[3], c2 = v[4];
        int degree = v[5];

        if (type == 1) degree = -degree;

        // 변화량 누적
        delta[r1 + 1][c1 + 1] += degree;
        delta[r2 + 2][c1 + 1] -= degree;
        delta[r1 + 1][c2 + 2] -= degree;
        delta[r2 + 2][c2 + 2] += degree;
    }

    // 누적합 계산
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            delta[i][j] = delta[i][j] + delta[i - 1][j] + delta[i][j - 1] - delta[i - 1][j - 1];

    // 건물 파괴 여부 확인
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j] + delta[i + 1][j + 1] > 0)
                answer++;

    return answer;
}