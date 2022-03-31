#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int arr[100001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	long long ans = -1;
	int minval = -1, minidx = -1;
	for (int i = 0; i < N; i++)
	{
		if (minval < arr[i]) {
			minval = arr[i];
			minidx = i;
		}
		if(ans < minval * (N - i)) 
			ans = minval * (N - i);
	}
	cout << ans << '\n';
	return 0;
}