#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std; 

int arr[500001];

int find(int start, int end, int target) {
    
    if (start == end) return 0;
    
    int mid = (start + end) / 2;
    if (arr[mid] == target) 
        return 1;
    else if (target < arr[mid])
        return find(start, mid, target);
    else 
        return find(mid + 1, end, target);
}

int main() {
    ios::sync_with_stdio(false);    cin.tie(NULL);  cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        cout << find(0, n, num) << ' ';
    }
    return 0;
}
