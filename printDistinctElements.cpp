/*
유일성 검사 https://www.geeksforgeeks.org/print-distinct-elements-given-integer-array/
예시 Input: arr[] = { 12, 10, 9, 45, 2, 10, 10, 45 }
예시 Output: 12, 10, 9, 45, 2
중복 제거하고 하나씩만 뽑기
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// O(N제곱)
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
// 장점 : keeps same order as the input array
void printDistinct3(int arr[], int n)
{
	// Creates an empty hashset
	unordered_set<int> s;
	for (int i = 0; i < n; i++)
	{
		if (s.find(arr[i]) == s.end())	// s.find(arr[i]) == s.end() : map안에 없으면 / 있으면은 != 
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
set 과 unordered_set 의 차이
set은 정렬 되어있는 상태에서 탐색을 하므로 O(logN) 시간이 걸린다. 평균도 최악도!
hash set은 해시 함수로 탐색을 하므로 평균 O(1) 상수 시간이 걸려 매우 빠르지만 
해시 충돌이 너무 많이 일어나는 최악의 경우 O(n) 로 그냥 set보다 더 오래걸릴 수 있다.
원소의 개수가 많을수록 해시충돌이 일어날 확률도 높아지므로
- 원소의 개수가 적고 빠른 성능을 원할 땐 unordered_set
- 원소의 개수가 많아 안정성을 원할 땐 set
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
/* map tree기반 은 BST 로 O(logn) : <key, value> 정렬하여 저장 자료구조
unordered_map hash 기반 은 해쉬테이블로 O(1) : <key, value> 검색빠른 자료구조

https://ansohxxn.github.io/stl/set/
*/