/*
* 반복문 이진검색 
* binarySearch(a[], key)
*	start = 0, end = length(a)-1;
*	while(start <= end){
*		mid = start + (end-start)/2;
*		if(a[mid] == key) return true;
*		else if(a[mid] > key) end = mid-1;
*		else start = mid + 1;
*	}
*	return false;
* end binarySearch();
*/

/*
* 재귀함수이용 이진검색
* binarySearch(a[], low, high, key)
*	mid = (low + high) / 2;
*	if(key == a[mid]) return true;
*	else if(key < a[mid]) binarySearch(a[], low, mid-1, key); // 아랫쪽 절반으로 이동
*	else if(key > a[mid]) binarySearch(a[], mid+1, high, key); // 윗쪽 절반으로 이동
*	else return false;
* end binarySearch();
*/

/*
* 선택정렬 오름차순시에
* 최소값 찾아서 가장앞에 수와 교환해서 가장 앞에 짱박아둠.
* 방금 찾은 1번째 최소 숫자 제외하고 2~n 번째 숫자 중 최소값 찾아서 2번 자리와 교환
* 실시간으로 제일 작은 값을 앞으로 짱박아두는 정렬
*/


/*
* Stack 2
* 중위표기법(일반수식)을 stack 을 이용하여 후기표기법(연산자를 피연산자 뒤에 표기, 컴퓨터 수식)으로 변경한다
* 연산자를 stack 에 넣어서 중위->후위로 변경
* 
* 후위표기법으로 표현된 수식을 계산할때는
* 피연산자를 stack 에 넣어서 수식의 값을 계산
* 
* 
* 백트래킹 기법
* 해를 찾는 도중에 막히면(해가 아니면), 되돌아가서 다시 해를 찾아가는 기법 : 최적화 문제, 결정 문제 해결에 사용
* 문제의 조건을 만족하는 해가 존재하는지의 여부를 yes 또는 no 가 답하는 문제 
* E.g. 미로찾기, NQueen, Map coloring, 부분집합의 합(Subset Sum) 등
*  
* Power Set : 어떤 집합의 공집합과 자기자신을 포함한 모든 부분집합 (2의 n제곱)
* 백트래킹 기법으로 Power Set(모든부분집합) 구하기 : 1 또는 0 을 가지는 항목들로 구성된 n개의 배열을 만드는 방법 이용
* 1 이면 해당 원소가 부분집합에 포함되고 , 0 이면 포함되지 않는다.
* 원하는 답에 도달했으면 결과를 출력, 답에 도달 못했으면 재귀 호출
* 
* 백트래킹 vs DFS
* 백트래킹은 중간에 답이 아닌 자식노드의 탐색을 중단 . 즉시 버리고 부모 타고 올라가서 다른 자식 탐색 
* DFS 는 중간에 답이든 아니든 상관없이 모든 자식 노드를 탐색 
* 
* 
*/

//Power Set을 구하는 백트래킹 알고리즘
//void backtrack(int a[], int k, int input)
//{
//	int c[MAXCANDIDATES] = { 0, };
//	int ncandidates = 0;
//	int i = 0;
//
//	if (k == input)
//	{
//		printf("(");
//		for (int i = 0; i <= k; i++)
//			if (a[i] == 1)
//				printf(" %d", i);
//		printf(")\n");
//	}
//	else
//	{
//		k++;
//		construct_candidates(a, k, input, c, &ncandidates);
//		for (i = 0; i < ncandidates; i++)
//		{
//			a[k] = c[i];
//			backtrack(a, k, input);
//		}
//	}
//}
//
//순열을 구하는 백트래킹 알고리즘
