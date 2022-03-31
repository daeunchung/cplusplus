// dfs() ���� cnt �� �����ϸ鼭 �����ϴ� �� �ٸ� ���� ���� �ڵ�
#include <iostream>
#include <vector>
using namespace std;

vector<int> student; //�л��� ����Ű�� �ٸ� �л� ��ȣ
vector<int> first_student; //ù ��°�� dfs�� ������ �л� ��ȣ
vector<int> visited; //�湮 ����

int dfs(int start, int current, int cnt) {

    if (visited[current]) {

        //ù ��°�� dfs�� ������ �л��� �´���, ����Ŭ�� �´���
        if (first_student[current] != start)
            return 0;

        //����Ŭ�� �ش�Ǵ� �л� ��
        return cnt - visited[current];
    }

    first_student[current] = start;
    visited[current] = cnt;
    return dfs(start, student[current], cnt + 1);
}

int main() {

    int T;
    cin >> T;

    int n;
    for (int testCase = 0; testCase < T; testCase++) {

        scanf("%d", &n);

        student = vector<int>(n + 1, 0);
        first_student = vector<int>(n + 1, 0);
        visited = vector<int>(n + 1, 0);

        for (int i = 1; i <= n; i++)
            scanf("%d", &student[i]);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                ans += dfs(i, i, 1);
            }
        }

        printf("%d\n", n - ans);
    }

    return 0;
}

