// ��� ������ do while �� ��� ����. ����:�Ϲ� while��ó�� ���� �˻�ÿ� ���������� �Ѿ�� �ʱ⶧��
// ��� ���� N*N!
// ���� : O(N) �� O(N+!) �� ���ٰ� �ĵ������� , O(N!) �� O((N+1)!) �� ���� ���̰� ���⿡ ����
// 1��(100000000) == 1��
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n); 
    for (int i = 0; i < n; i++) {
        a[i] = i+1;
    }
    do {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));
    return 0;
}