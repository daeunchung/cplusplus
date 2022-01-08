/*
D[i] = i�ڸ� ��ģ���� ����
������ ��� - 
1. 0���� ������ ���(�տ� 0,1 �ü�����) = D[i-1]
2. 1�� ������ ���(�տ� 0 ���ü�����) = 01�� ���δٰ� ��� = D[i-2]
Ư�� ���̽��� 1���� �迭 dp�� �ذ� ����  D[i] = D[i-1] + D[i-2]
*/
#include <iostream>
using namespace std;
long long d[91];
int main() {
    int n;
    cin >> n;
    d[1] = 1;   // 1
    d[2] = 1;   // 01
    for (int i = 3; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2];
    }
    cout << d[n] << '\n';
    return 0;
}