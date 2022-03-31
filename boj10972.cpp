// C++98
#include <iostream>
#include <vector>
using namespace std;
/*
1. A[i-1]<A[i]�� �����ϴ� ���� ū i�� ã�´�
2. j>=i �̸鼭 A[j] > A[i-1]�� �����ϴ� ���� ū j�� ã�´�
3. A[i-1]�� A[j]�� swap �Ѵ�
4. A[i]���� ������ �����´�

e.g
7 2 3 6 5 4 1    A[i-1]�� 3 < A[i]�� 6
j>=i �̸鼭 A[j] > A[i-1](3)�� �����ϴ� ���� ū j�� ã�� �̶� A[j]�� 4
A[i-1](3)�� A[j](4)�� swap   7 2 4 6 5 3 1
A[i]���� ������ �����´�   7 2 4 1 3 5 6
*/
bool next_permutation(vector<int>& a, int n) 
{
    // 1. A[i-1] < A[i] �� �����ϴ� ���� ū i ã�� (�ڿ������� ���� �Ҹ����� ��ĭ ������ Ž��)
    int i = n - 1;  
    while (i > 0 && a[i - 1] >= a[i]) {
        i -= 1;
    }
    if (i <= 0) {   // ���� ������ �����̴�. ��������X
        return false;   
    }
    // 2. j>=i �̸鼭 A[j] > A[i-1] �����ϴ� ���� ū j ã�� (�ڿ������� ���� �Ҹ����� ��ĭ ������)
    int j = n - 1;
    while (a[j] <= a[i - 1]) {
        j -= 1;
    }
    // 3. A[i-1] �� A[j] �� swap
    swap(a[i - 1], a[j]);
    // 4. A[i] ���� ������ �����´� ( 4321 -> 1234)
    j = n - 1;
    while (i < j) {
        swap(a[i], a[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

// �������� �Ѱ� ���ϱ� = O(N), ��ü ������ ��� ���ϱ� O(N!*N)
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (next_permutation(a, n)) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
    }
    else {
        cout << "-1";
    }
    cout << '\n';
    return 0;
}