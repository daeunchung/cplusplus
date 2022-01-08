/*
���ϼ� �˻� https://www.geeksforgeeks.org/print-distinct-elements-given-integer-array/
���� Input: arr[] = { 12, 10, 9, 45, 2, 10, 10, 45 }
���� Output: 12, 10, 9, 45, 2
�ߺ� �����ϰ� �ϳ����� �̱�
*/
#include <bits/stdc++.h>
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
void printDistinct3(int arr[], int n)
{
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{

	}
}


// Driver program to test above function
int main()
{
	int arr[] = { 6, 10, 5, 4, 9, 120, 4, 6, 10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printDistinct2(arr, n);
	return 0;
}