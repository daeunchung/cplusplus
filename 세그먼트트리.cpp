#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

long init(int nums[], long tree[], int node, int start, int end)
{
	if (start == end)
		return tree[node] = nums[start];

	int mid = (start + end) / 2;

	return tree[node] = init(nums, tree, node * 2, start, mid) 
		+ init(nums, tree, node * 2 + 1, mid + 1, end);
}

void update(long tree[], int node, int start, int end, int index, int diff)
{
	if (!(start <= index && index <= end))
		return;
	tree[node] += diff;
	if (start != end)
	{
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

long sum(long tree[], int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];
	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right)
		+ sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	// 숫자 5개 {1,2,3,4,5} 의 구간 합 세그먼트 트리 구할때
	int nums[6] = { 0,1,2,3,4,5 };
	long tree[16] = { 0 };

	int N = 5;	// N = 5 일때 segmentSize = 16
	
	// h-1 < log2^N <= h (Depth)
	int h = (int) ceil(log(N) / log(2)); // log2(N) 
	int segmentSize = (int)pow(2, h + 1);

	init(nums, tree, 1, 1, 5);
	for (int i = 0; i < 16; i++) cout << tree[i] << ' ';	// tree[0] 는 안쓴다
	cout << '\n';

	update(tree, 1, 1, 5, 3, 3);		// 5번 노드 (세번째 숫자를 3 -> 6)
	for (int i = 0; i < 16; i++) cout << tree[i] << ' ';
	cout << '\n';

	cout << sum(tree, 1, 1, 5, 2, 5) << '\n';
	
	return 0;
}

// https://m.blog.naver.com/ndb796/221282210534 모든 함수들에서 tree, nums 인자 빼준 버전