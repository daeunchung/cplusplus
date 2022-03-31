// C++98
#include <iostream>
#include <vector>
using namespace std;
/*
1. A[i-1]<A[i]를 만족하는 가장 큰 i를 찾는다
2. j>=i 이면서 A[j] > A[i-1]를 만족하는 가장 큰 j를 찾는다
3. A[i-1]과 A[j]를 swap 한다
4. A[i]부터 순열을 뒤집는다

e.g
7 2 3 6 5 4 1    A[i-1]는 3 < A[i]는 6
j>=i 이면서 A[j] > A[i-1](3)를 만족하는 가장 큰 j를 찾고 이때 A[j]는 4
A[i-1](3)과 A[j](4)를 swap   7 2 4 6 5 3 1
A[i]부터 순열을 뒤집는다   7 2 4 1 3 5 6
*/
bool next_permutation(vector<int>& a, int n) 
{
    // 1. A[i-1] < A[i] 를 만족하는 가장 큰 i 찾기 (뒤에서부터 조건 불만족시 한칸 앞으로 탐색)
    int i = n - 1;  
    while (i > 0 && a[i - 1] >= a[i]) {
        i -= 1;
    }
    if (i <= 0) {   // 가장 마지막 순열이다. 다음순열X
        return false;   
    }
    // 2. j>=i 이면서 A[j] > A[i-1] 만족하는 가장 큰 j 찾기 (뒤에서부터 조건 불만족시 한칸 앞으로)
    int j = n - 1;
    while (a[j] <= a[i - 1]) {
        j -= 1;
    }
    // 3. A[i-1] 과 A[j] 를 swap
    swap(a[i - 1], a[j]);
    // 4. A[i] 부터 순열을 뒤집는다 ( 4321 -> 1234)
    j = n - 1;
    while (i < j) {
        swap(a[i], a[j]);
        i += 1;
        j -= 1;
    }
    return true;
}

// 다음순열 한개 구하기 = O(N), 전체 순열을 모두 구하기 O(N!*N)
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