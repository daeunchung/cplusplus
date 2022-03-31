/*
���ǿ� ��ȸ2  TSP Traveling Salesman Problem
���� �� ���ù���

������ �� N  "2 �� N �� 10" ( N Ŀ���� �����δ� X)
��� �� ���ÿ��� ����� "N���� ���ø� ��� ����" �ٽ� ������ ���÷� ���ƿ��� ��ȸ ���� ���
��, "�� �� ���� ���÷δ� �ٽ� �� �� ����" 
" " => 3���� ���� ������ ������ �ذ��� ����
���� = O(N*N!)

���� ���� O(N*N!) ����
-> O(N!) �� ���� ���� (1234 == 2341 == 3412 == 4123 �ٽ� ���۵��÷� �����ؼ� ��� ���� ���)
���� N*(N-1)! == N!

*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int w[20][20];
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    // ���� ��ȸ ������ ���� ����
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    int ans = 2147000000;
    do {
        bool exists = true;
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (w[p[i]][p[i + 1]] == 0) 
                exists = false;
            else 
                sum += w[p[i]][p[i + 1]];
        }
        if (exists && w[p[n - 1]][p[0]] != 0) {
            sum += w[p[n - 1]][p[0]];
            if (ans > sum) ans = sum;
        }
    } 
 // while (next_permutation(p.begin(), p.end()));     O(N*N!)
    while (next_permutation(p.begin() + 1, p.end()));   // O(N!) ù���ڸ� 1�� ����

    cout << ans << '\n';
	return 0;
}