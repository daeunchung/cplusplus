/*
 Binary Search ����(�̺�)Ž������ : �̸� ���ĵǾ��־����. �׳�Ǯ�� �ð��ʰ�
 ó������ ������ ��� Ȯ���ϸ� O(N), BinarySearch O(logN)

 C++ STL <algorithm> ���� �����ϴ� sort()�� intro sort ���� ���
	: quick sort�� ������� heap sort�� insertion sort�� ���� ���
	�־��ǰ�� O(N^2)�� quick sort�� �ٸ��� �־��ǰ�� O(nlogn) ����
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

// ���;��� �Է¹ޱ� getche ? ���ذ�
/* �ð��ʰ�
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