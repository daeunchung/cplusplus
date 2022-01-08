#include <bits/stdc++.h>
using namespace std;

// main���� binarySearch(arr, 0, M - 1, targetValue); ȣ��
void binarySearch(int* arr, int low, int high, int target)	// SWEA
{
	if (low > high)
	{
		printf("-1 ");
		return;
	}
	int mid = (low + high) / 2;
	if (target < arr[mid]) {
		binarySearch(arr, low, mid - 1, target);
	}
	else if (arr[mid] < target) {
		binarySearch(arr, mid + 1, high, target);
	}
	else {
		printf("%d ", mid);
		return;
	}
}

int bS(int arr[], int l, int r, int x)	// geeksforgeeks recursion ver.
{
	if (r >= l) {
		int mid = l + (r - l) / 2;	// code like this to prevent bug
		if (arr[mid] == x) return mid;
		if (arr[mid] > x) return bS(arr, l, mid - 1, x);
		return bS(arr, mid + 1, r, x);
	}
	return -1;
}

int bSIter(int arr[], int l, int r, int x)	// geeksforgeeks iteration ver.
{
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (arr[m] == x) return m;
		if (arr[m] < x) l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}


// code below from https://www.acmicpc.net/blog/view/109
int bs1(int* arr, int size, int key)
{
	int lb = -1, ub = size - 1, m;
	while (lb + 1 < ub)
	{
		m = lb + (ub - lb) / 2;
		if (arr[m] >= key) ub = m;	// �Ʒ��� ���丷���� �̵�
		else lb = m;				// ���� ���丷���� �̵�
	}
}

int bs2(int* arr, int size, int key)
{
	int *p = lower_bound(arr, arr + size, key);

	if (p - arr >= size) return -1;
	else
	{
		if (*p == key) return p - arr;
		else return -1;
	}
	// ���� ���� ���׿����ڷ� �ۼ��� (����)? ���϶�����:(�����϶� (����)? ���϶�:�̰͵������϶�))
	//return (p - arr) >= size ? -1 : *p == key ? (p - arr) : -1;
}
// �⺻������ �̸� ���� �س��� bs ����


/* what are lower_bound and upper_bound and How to Implement them
https://www.geeksforgeeks.org/implementing-upper_bound-and-lower_bound-in-c
*/