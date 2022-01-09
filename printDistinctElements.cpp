/*
���ϼ� �˻� https://www.geeksforgeeks.org/print-distinct-elements-given-integer-array/
���� Input: arr[] = { 12, 10, 9, 45, 2, 10, 10, 45 }
���� Output: 12, 10, 9, 45, 2
�ߺ� �����ϰ� �ϳ����� �̱�
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// O(N����)
void printDistinct1(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		bool exists = false;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j]) {
				exists = true;
				break;
			}
		}
		if(!exists) cout << arr[i] << ' ';
	}
}
void printDistinct(int arr[], int n)
{
	// Pick all elements one by one
	for (int i = 0; i < n; i++)
	{
		// Check if the picked element is already printed
		int j;
		for (j = 0; j < i; j++)
			if (arr[i] == arr[j])
				break;

		// If not printed earlier, then print it
		if (i == j)
			cout << arr[i] << " ";
	}
}

// O(nlogn) : first sort the array then check consecutive numbers if they are identical
void printDistinct2(int arr[], int n)
{
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		while (i < n - 1 && arr[i] == arr[i + 1]) i++;
		cout << arr[i] << ' ';
	}
}


// Use Hashing to solve this in O(n) time on average
// traverse the given array from left to right and keep track of visited elements in a hash table
// ���� : keeps same order as the input array
void printDistinct3(int arr[], int n)
{
	// Creates an empty hashset
	unordered_set<int> s;
	for (int i = 0; i < n; i++)
	{
		if (s.find(arr[i]) == s.end())	// s.find(arr[i]) == s.end() : map�ȿ� ������ / �������� != 
		{
			s.insert(arr[i]);
			cout << arr[i] << ' ';
		}
	}
}

// 1. Put all input integers to hashmap's key
// 2. Print keySet outside the loop
void printDistinct4()
{
	int ar[] = { 10, 5, 3, 4, 3, 5, 6 };
	//unordered_map<int, int> hm;
	map<int, int> hm;
	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
	{
		hm.insert({ ar[i], i });
	}
	cout << "[";
	for (auto const& pair : hm)
	{
		cout << pair.first << ", ";
	}
	cout << "]";
}

// with set?
/*
set �� unordered_set �� ����
set�� ���� �Ǿ��ִ� ���¿��� Ž���� �ϹǷ� O(logN) �ð��� �ɸ���. ��յ� �־ǵ�!
hash set�� �ؽ� �Լ��� Ž���� �ϹǷ� ��� O(1) ��� �ð��� �ɷ� �ſ� �������� 
�ؽ� �浹�� �ʹ� ���� �Ͼ�� �־��� ��� O(n) �� �׳� set���� �� �����ɸ� �� �ִ�.
������ ������ �������� �ؽ��浹�� �Ͼ Ȯ���� �������Ƿ�
- ������ ������ ���� ���� ������ ���� �� unordered_set
- ������ ������ ���� �������� ���� �� set
*/
void printDistinct5()
{
	int ar[] = { 10, 5, 3, 4, 3, 5, 6 };
	//set<int> s;
	unordered_set<int> hs;
	for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
	{
		hs.insert(ar[i]);
	}
	cout << "[";
	for (const auto& elem : hs)
	{
		cout << elem << ", ";
	}
	cout << "]";
}


// Driver program to test above function
int main()
{
	int arr[] = { 6, 10, 5, 4, 9, 120, 4, 6, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	//printDistinct2(arr, n);
	printDistinct5();
	return 0;

}
/* map tree��� �� BST �� O(logn) : <key, value> �����Ͽ� ���� �ڷᱸ��
unordered_map hash ��� �� �ؽ����̺�� O(1) : <key, value> �˻����� �ڷᱸ��

https://ansohxxn.github.io/stl/set/
*/