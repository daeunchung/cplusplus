/*
 Binary Search 이진(이분)탐색문제 : 미리 정렬되어있어야함. 그냥풀면 시간초과
 처음부터 끝까지 모두 확인하면 O(N), BinarySearch O(logN)

 C++ STL <algorithm> 에서 제공하는 sort()는 intro sort 정렬 방식
	: quick sort를 기반으로 heap sort와 insertion sort를 섞은 방식
	최악의경우 O(N^2)인 quick sort와 다르게 최악의경우 O(nlogn) 보장
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, num, d;
vector<int> a;

int BinarySearch(int low, int high, int target) {
	if (low > high) return 0;
	else {
		int mid = (low + high) / 2;
		if (a[mid] == target) return 1;
		else if (a[mid] > target) return BinarySearch(low, mid - 1, target);
		else if (a[mid] < target) return BinarySearch(mid + 1, high, target);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		a.push_back(num);
	}
	sort(a.begin(), a.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num;
		//cin.ignore();
		cout << BinarySearch(0, n - 1, num) << '\n';
	}
	return 0;
}

// 엔터없이 입력받기 getche ? 미해결
/* 시간초과
cin >> n;
vector<int> a(n);
for (int i = 0; i < n; i++) cin >> a[i];

cin >> m;
vector<int> b(m);
for (int i = 0; i < m; i++) cin >> b[i];
	
for (int i = 0; i < m; i++) {
	int cnt = 0;
	for (int j = 0; j < n; j++) {
		if (b[i] == a[j]) {
			cout << "1" << '\n';
			break;
		}
		cnt++;
	}
	if(cnt == n) cout << "0" << '\n';
}
return 0;
*/