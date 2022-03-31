/*
수학 - 나머지 연산
최종정답에서 나머지 연산수행 X, 갱신해줄 때마다 나머지 연산 수행O
곱하기는 더하기의 연속이라 동일 적용
(A + B)mod M = ((A mod M) + (B mod M)) mod M
(A * B)mod M = ((A mod M) * (B mod M)) mod M
(A - B)mod M = ((A mod M) - (B mod M) + M) mod M

수학 - 최대공약수 GCD (1.그냥, 2.유클리드호제법)


수학 - 최소공배수 LCM
A * B = GCD * LCM 을 이용

수학 - 소수 알고리즘 2개
1. 어떤 수 N 의 소수 여부 판별
2. N보다 작거나 같은 모든 자연수 중 소수 찾기


dp - Top down 재귀호출
dp - Bottom up 반복문


int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

int gcdEuclid(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

bool prime1(int n) 
{
	if (n < 2) return false;
	for (int i = 2; i <= n - 1; i++) {
		if (n % i == 0) return false;
	}
	return true;
} // => O(N)

// N의 약수 중에서 가장 큰 것은 N/2보다 작거나 같기 때문에 개선 가능
bool prime2(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= n/2; i++) {
		if (n % i == 0) return false;
	}
	return true;
} // => O(N/2) = O(N)

// 더욱 개선 : 컴퓨터에서 실수는 근사값이기에 i*i<=n 표현이 적절
bool prime3(int n)
{
	if (n < 2) return false;
	for (int i = 2; i*i<=n; i++) {
		if (n % i == 0) return false;
	}
	return true;
} // => O(루트N)
*/


/* 에라토스테네스의 체 Sieve of Eratosthenes (소수구하기 알고리즘 중에 가장 중요 아주 중요 매우 중요)
  => O(NloglogN) for문N번 * if문(loglogN상당히복잡)
  안쪽for문의 j 는 N의 크기에 따라서, j = i*i보다는 i+i 또는 i*2 로 바꾸는 것이 좋다.
  왜냐하면 i=백만인 경우 i*i는 1조가 되는데 int가 2백만정도 까지 이기 때문 (overflow발생)

  모든 소수는 6n+1또는 6n+5 의 꼴을 띈다.

void Eratosthenes()
{
	int prime[100];	// 소수 저장
	int pn = 0;		// 소수의 개수
	bool check[101];	// 지워졌으면 true(소수가 아니다), 남아있으면 false(소수)
	int n = 100;
	for (int i = 2; i <= n; i++)
	{
		if (check[i] == false)	// 지워지지 않았으면
		{
			prime[pn++] = i;
			for (int j = i * i; j <= n; j += i) {
				check[j] = true;
			}
		}
	}
} //=> O(NloglogN) for문N번 * if문(loglogN상당히복잡)

//  prime 저장용 배열을 따로 만들지 말고 
int check[] 로 해서 check[i] = i 로 초기화 하는 방법이 시간초과 피하기 적합할듯
*/

/* 골드바흐의 추측 Goldbach's conjecture 
2 보다 큰 모든 짝수는 두 소수의 합으로 표현이 가능하다. --+3--> 5보다 큰 모든 홀수는 세 소수의 합으로 표현 가능하다.
check[N-b] == false 인지 확인
*/

/* 팩토리얼 Factorial 부르트포스때 중요 10!=3백만, 20!=int범위벗어남
 nCm = n!/((n-m)!m!) : 2의 갯수 > 5의 갯수 일 수 도 있기에 둘다 세어보고 더 적은것의 갯수 알아야함
*/





/* 자료형
char
signed char	1바이트, 8비트 - 128 ~ 127

unsigned char	1바이트, 8비트	0 ~ 255

short
short int	2바이트, 16비트 - 32,768 ~ 32,767	int 생략 가능

unsigned short
unsigned short int	2바이트, 16비트	0 ~ 65,535	int 생략 가능

int
signed int	4바이트, 32비트 - 2,147,483,648 ~ 2,147,483,647

unsigned
unsigned int	4바이트, 32비트	0 ~ 4,294,967,295	int 생략 가능

long
long int
signed long
signed long int	4바이트, 32비트 - 2,147,483,648 ~ 2,147,483,647	int 생략 가능

unsigned long
unsigned long int	4바이트, 32비트	0 ~ 4,294,967,295	int 생략 가능

long long
long long int
signed long long
signed long long int	8바이트, 64비트 - 9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807	int 생략 가능

unsigned long long
unsigned long long int	8바이트, 64비트	0 ~ 18,446,744,073,709,551,615	int 생략 가능

*/


/*
* DP 
문제에서 DP의 '한단계' 가 될 부분의 정의를 찾고 점화식을 설립

// dp topdown 재귀 + 메모이제이션
int memo[100];
int fibonacci(int n) {
	if (n <= 1) return n;
	else {
		if (memo[n] > 0) return memo[n];
		memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return memo[n];
	}
}

// dp bottomup 반복문
int d[100];
int fibonacci2(int n) {
	d[0] = 0;	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + d[i - 2];
	}
	return d[n];
}
*/

/*
* 브루트포스 방법 1. 재귀, 2. 순열, 3. 비트마스크 => 1.재귀가 가장 중요 (왜냐, 2,3 은 1.재귀로 만들 수 있기 때문)
* 브루트포스의 재귀는 문제가 2종류 : 순서 / 선택
* 
* 
브루트포스는 경우의 수가 많지 않은 경우에만 사용가능
시도할 방법의 수를 미리 구하여 소요될 시간을 미리 계산해보고 시간초과를 넘지 않을 경우에만 사용가능
대표적으로 그냥 다 해보는 방법 : for문, 재귀, 순열, 비트마스트 ...

문제의 방법의 수 = 경우의 수
브루트포스 문제 시간 복잡도 = O(경우의 수 * 방법 1개를 시도해보는데 걸리는 시간)
*/


/*
순열 reference 
std::next_permutation in <algorithm>
bool next_permutation (iter first, iter last);

#include <algorithm>
#include <iostream>
int a[3] = {1, 2, 3};
int main()
{
	do {
		for (int i = 0; i < 3; i++)
			std::cout << a[i];
		std::cout << '\n';
	} 	while (std::next_permutation(a, a + 3));
}

조합을 구할 때에도 std::next_permutation() 이용이 가능하다
1 2 3 4 에서 수 2개를 순서 없이 뽑는 모든 경우 == {0,0,1,1} 로 next_permutation 실행
5C3 이면 {0,0,0,1,1} 로 두면 된다

#include <algorithm>
#include <iostream>
int a[4] = { 0,0, 1, 1 };
int main()
{
	do {
		for (int i = 0; i < 4; i++) {
			if(a[i] == 0)
				std::cout << i+1;
		}
		std::cout << '\n';
	} while (std::next_permutation(a, a + 4));
}
*/



/*
* 재귀함수를 이용해 브루트 포스를 하다 보면, 더 이상 함수 호출이 의미 없는 경우가 있다
* 이 때, 이런 경우를 제외하고 브루트 포스를 진행하면 백트래킹이라고 한다.
* 
https://blog.encrypted.gg/945
백트래킹 익히기 : 15649 9663 1182

백트래킹 vs DFS
DFS     -  여러지점을 한 단계씩 거쳐가면서 탐색하고 스택의 개념을 이용해서 이전 단계로 돌아가는 기법이다.
백트래킹 - 이미 지나쳐온 곳을 다시 돌아가서 다른 가능성을 시도해보는 걸 반복하는 기법으로, 
반드시 DFS만으로 가능하지 않고 BFS등으로도 가능한 기법이다.
즉, 정리를 하자면 
백트레킹은 하나의 문제 해결 방법론이고 
이러한 백트레킹을 구현하는 방법론 중 하나가 DFS이다.

백트래킹 vs 브루트포스
브루드 포스 - 모든 경우의 수를 탐색하는 문제 해결 방법론이다.
이와 달리, 백트래킹 - 단계마다 조건을 충족하는지 검사하여 조건을 충족하는 경우에만 계속해서 탐색한다.
즉, 정리를 하자면 
브루트포스 모든 가지를 탐색하는 방법론이고 
백트레킹을 조건을 보고 가지치기를 해나가면서 탐색하는 방법론이다.

백트래킹(backtracking)이란?
솔루션을 찾는 과정에서, 유망(promising)하지 않은 후보해에 대해 대해 빠르게 포기하고 이전 단계로 되돌아(back track)가 다른 후보해를 찾는 알고리즘 기법

DFS와 Backtracking
DFS : 완전 탐색을 기본으로 하는 그래프 순회 기법으로, 모든 노드를 방문하는 것을 목표로 한다.

Back-tracking : 불필요한 탐색을 하지 않고, 이전 단계로 돌아와 다른 후보해를 탐색해 나가는 방법
=> 일단 가보고 후보해가 될 수 없으면 다음 단계로 진행하지 않고 되돌아 나온다.

DFS와 Back-tracking 둘다 재귀 호출 형태로 자주 구현이 되기 때문에 헷갈린다.
두 알고리즘은 사용 목적에 차이가 있다.

DFS : 깊이 우선 탐색하여 모든 노드를 방문하는 것을 목표로 한다.
Backtracking : 불필요한 탐색을 하지 않기 위해, 유망하지 않은 경우의 수를 줄이는 것을 목표로 한다.

DFS는 완전 탐색을 목표로 하는 알고리즘이기 때문에 자원 소모가 굉장히 심하다. 그래서 어떤 제약 조건에 맞는 해답을 찾기 위해서 DFS와 Back-tracking 기법을 혼용해서 사용한다.
=> 가지 치기를 통해서 얻은 그래프에 대해서 다시 DFS 탐색을 하면서 불필요한 탐색을 줄여 나간다.


가지 치기(Pruning)
불필요한 탐색 부분을 제거하는 방법
트리 구조에서 나무 가지를 치듯이 가망성이 없는 부분을 제거해 나가는 것

최종 결정에 영향을 주지 않는 부분을 쳐 내면서, 경우의 수를 줄여 나간다.
ex) 백트래킹, 분기 한정

Backtracking vs Branch-&-Bound
공통점
불필요한 탐색 부분을 제거 하는 방법
차이점
Backtracking : 가보고 더 이상 진행이 되지 않으면 돌아온다
Branch-&-Bound : 최적해를 찾을 가능성이 없으면 분기는 하지 않는다
*/

/*
* 앞서 배운
* 브루트포스는  모든 경우의 수 살펴보아야 해서 여러 방법을 사용해서 전체 경우를 탐색
  dp 는 문제풀이 과정 중에 점화식 설립

* 그래프는 문제를 그래프로 모델링한 후에 여러 알고리즘을 수행하는 방식
* 다른 유형과 느낌이 조금 다르다. 
* 알고리즘은 변하지 않고 문제의 정보를 어떻게 그래프로 표현하냐 에 관건
* 
* 경로 : 일반적으로 단순 경로(같은 정점을 두 번 이상 방문하지 않는 경로, 사이클)
* 사이클 : 일반적으로 단순 사이클(같은 정점을 두 번 이상 방문하지 않는 사이클)
* 
* 그래프 저장할때
* 무방향 그래프는 전부 방향 있는 그래프로 바꾸어서 저장
* 간선의 가중치는 문제에 따라 여러가지를 의미할 수 있음. : 거리, 시간, 비용 등등
* 
* 차수  degree : 정점과 연결되어 있는 간선의 개수
* 방향O 그래프는 in-degree, out-degree 구분
* 
* 
* 2022-01-10	V정점수, E간선수
그래프 구현 방법 
1. 인접행렬		공간복잡도 O(V제곱),		""한 정점 연결된 모든 간선 구하기 O(V)""
2. 인접리스트
				가중치간선일때는 (정점,간선가중치) 로 저장, 가중치없으면 정점과 연결되는 (정점)만 저장
				C++ vector, Java ArrayList, Python []list
				없는 간선을 저장하지 않는다. 인접행렬은 없어도 0으로 채웠었음
				공간복잡도 O(E)
				""한 정점 연결된 모든 간선 구하기 O(차수)"" . 차수는 정점마다 다르다
				시간, 공간 모두 인접리스트가 인접행렬보다 우수

				인접행렬이 인접리스트보다 우수한 경우는 딱 한가지
				: 임의의 두 정점 사이에 (u,v) 간선의 유무 파악시
				인접행렬은 O(1), 인접리스트는 O(차수)

3. 간선리스트	E배열 하나에 모든 간선을 다 넣는다. (from,to) 형태로
				from 정점을 기준으로 정렬. 사용할 경우는 인접리스트 써야하는데 lib사용 금지시에 사용한다
				cnt배열에 앞정점(from) 의 갯수를 각각 세어서 저장
						for(int i = 0; i < m; i++)
							cnt[e[i][0]] += 1;
				cnt 배열을 누적합 구한다
				  i		0  1  2  3  4  5  6  
				cnt[i]  0  2  4  2  4  3  1
 			    누적합   0  2  6  8  12  15  16
						for(int i = 1; i <= n; i++)
							cnt[i] = cnt[i - 1] + cnt[i];
				누적합으로 알 수 있는 점은? 
					1번노드에서 뻗어나가는 간선은 0번 ~ 2번 전까지
					4번노드에서 뻗어나가는 간선은 8번 ~ 12번 전까지 (즉 E[8] E[9] E[10] E[11])
				출발 정점에 붙어있는 간선이 몇번 index 부터 저장되어 있는지를 알 수 있음
				""필요한연산 : 하나의 정점에 붙어있는 모든 간선 찾기 O(차수)""

그래프 탐색
목적 : 임의의 정점에서 시작하여 연결되어있는 모든 정점을 1번씩 방문하는 것 (DFS, BFS - 정점방문순서만 다르다)

구현도중에 실수로
하나의 정점을 두번 방문하게 되면 그 DFS 알고리즘이라고 할 수 없음. 오직 한 정점은 한번만 방문

DFS : 한번에 한놈만 돌아다닌다
BFS : 한번에 인접정점 갯수만큼 복제해서 여러놈이 한번에 돌아다닌다

DFS STACK : 더 이상 갈 정점이 없을때 돌아갈 지점을 기록
정점 방문 YES/NO 기록용 배열 하나 필요
안가봤던 노드 갈때는 stack에 푸시
더이상 갈 노드가 없으면 stack에서 pop한 뒤에 가장 위의 top 정점으로 가면된다
스택이 empty 하면 모든 정점을 순회하였다

DFS 는 재귀함수 이용하여 구현
stack 사용은 ? ""모든언어(C++JavaPython)의 재귀함수는 stack 을 이용해 구현""
dfs(x) 함수는 


DFS (인접 행렬, 재귀)
void dfs(int x)
{
	check[x] = true;
	for(int i=1; i<=n; i++)
	{
		if(a[x][i] == 1 && check[i] == false)
		{
			dfs(i);
		}
	}
}

BFS (인접 행렬)
queue<int> q;
check[1] = true;	q.push(1);	// 큐에 넣을때 방문O 표시
while(!q.empty())
{
	int x = q.front();	q.pop();
	for(int i=1; i<=n; i++)
	{
		if(a[x][i] == 1 && check[i] == false)
		{
			check[i] = true;
			q.push(i);
		}
	}
}

이분 그래프 
- 그래프의 모든 정점이 그룹 A or 그룹 B
- 그래프의 모든 간선이 한 쪽은 그룹 A, 다른 한쪽은 그룹 B




*/





// set 이 bst와 유사한 구조로 되어있음

// bfs / dfs
// 종만북에 bi - directional BFS 로 15 puzzle 문제 푸는 것 나와있음

// ch4 / sssp(single source shortest path 최단거리) - 벨만포드, 다익스트라, bfs...



/* Tree
트리는 그래프이다. 루트는 본래 없으나 지정해줄 수 있다. 사이클이 없는 연결 그래프.
성질(정의X) :  정점N개, 간선N-1개

트리의 표현
1. 트리의 부모만 저장하는 방식 (i, p[i])
UnionFind 에서 사용
부모는 금방 찾으나, 자식을 찾는 것은 N만큼 걸린다.
2. 완전 이진 트리의 경우만 배열로 표현 (부모x일때, 자식은 2x, 2x+1)
Heap, SegmentTree 에 사용
3. 그냥 이진 트리 : 구조체, 클래스
struct Node { Node *left; Node *right; }
preorder : 일반적dfs
inorder : 딱한번 사용. BST에서 삭제 구현시 인오더successor 사용
postorder :


*/


/* 비트 연산  O(1)
* shift left(<<) 와 shift right(>>) 연산이 존재
* A >> B (A를 오른쪽으로 B비트만큼 민다)
* (A + B) / 2 == (A+B) >> 1
* (A + B) * 2 == (A+B) << 1
* A << B = A * 2^B, A >> B = A / 2^B 
* 
* 비트마스크 Bitmask
* 정수로 집합을 나타낼 수 있다
* 집합에는 같은 수가 존재하지 않음
* 장점1 : 공간이 절약된다 
* {1, 3, 4, 5, 9} = 570 = 2^1 + 2^3 + 2^4 + 2^5 + 2^9
* 장점2 : 배열의 인덱스로 사용 가능 (정수이기 때문에 시간이 절약)
* A[570] 으로 사용가능  A[1,3,4,5,7] 은 표현 불가능
* 
* 사용하려고 하는 수가 최대 몇개인지 알아야함
* 집합에 들어가는 수의 최대값을 알아야함
* 보통 0부터 N-1 까지 정수로 이루어진 집합을 나타낼 때 사용한다
* 1부터 N 까지 정수로 이루어진 집합을 사용하는 건 공간이 2배 더 필요
* 또, 각종 연산을 조금 변형해서 사용해야 한다.
* 따라서, 0부터 N-1 까지로 변형해서 사용하는 것이 더 좋다.
* 
*/

// ----------------------------- 여기까지 블로그 작성했음--------------------------------------

/*
* Segment Tree   출처: https://yabmoons.tistory.com/431 [얍문's Coding World..]
* 크기가 N인 배열이 존재할 때 1. 트리의 높이 = ceil(log2(N))
2. 세그먼트 트리의 크기 = (1 << (트리의 높이 + 1) )
세그먼트 트리의 크기 = 주어진 배열의 크기 x 4 로 설정하고 진행해도 무방하다.


int Make_SegmentTree(int Node, int Start, int End)
{
	if (Start == End) return SegmentTree[Node] = Arr[Start];

	int Mid = (Start + End) / 2;
	int Left_Result = Make_SegmentTree(Node * 2, Start, Mid);
	int Right_Result = Make_SegmentTree(Node * 2 + 1, Mid + 1, End);
	SegmentTree[Node] = Left_Result + Right_Result;

	return SegmentTree[Node];
}

int main(void)
{
	int Tree_Height = (int)ceil(log2(N));
	int Tree_Size = (1 << (Tree_Height + 1));
	SegmentTree.resize(Tree_Size);
	Make_SegmentTree(1, 0, N - 1);
}

int Sum(int Node, int Start, int End, int Left, int Right)
{
    if (Left > End || Right < Start) return 0;
    if (Left <= Start && End <= Right) return SegmentTree[Node];
    int Mid = (Start + End) / 2;
    return Sum(Node * 2, Start, Mid, Left, Right) 
			+ Sum(Node * 2 + 1, Mid + 1, End, Left, Right);
}

void Update_SegmentTree(int Node, int Start, int End, int Index, int Diff)
{
	if (Index < Start || Index > End) return;
	SegmentTree[Node] = SegmentTree[Node] + Diff;

	if (Start != End)
	{
		int Mid = (Start + End) / 2;
		Update_SegmentTree(Node * 2, Start, Mid, Index, Diff);
		Update_SegmentTree(Node * 2 + 1, Mid + 1, End, Index, Diff);
	}
}

int main(void)
{
	int Index = 1;
	int Value = 5;
	int Diff = Value - Arr[Index];
	Arr[Index] = Value;
	Update_SegmentTree(1, 0, N - 1, Index, Diff);
}



* 
* BIT Binary Index Tree (Fenwick Tree)
* BIT 로 풀 수 있는 모든 문제는 Segment Tree 로 해결가능
* 
*/


/*
*대표적인 Union Find / 분리집합(disjoint set)
int find(int x)
{
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void uni(int x, int y)
{
	// find() 를 포함하여 경로압축
	parent[find(x)] = find(y);
}
*/

/* MST Minimum Spanning Tree
* 그래프에서 모든 노드를 순환없이 연결하는 최단경로를 구하는 알고리즘
* 
* Spanning Tree 를 만들기 위해서는
* N개의 노드가 있다면, N-1개의 간선으로 모든 노드를 연결해야하며, 할 수 있다
* 간선이 노드의 갯수를 넘어가면 Spanning Tree x -> 순환이 있는 Graph 가 된다
* 
* 크루스칼 알고리즘 (간선 중심으로 체크 ) : Union Find 와 Priority Queue 를 활용
* 간선의 가중치를 오름차순으로 (작->큰) 정렬하고, 순서대로 체크하며
* 서로 순환을 이루지 않는 경우 노드를 서로 연결
* N-1개의 간선을 연결하면 순환을 종료하는 것
* (N개의 노드가 있다면, N-1개의 간선으로 모든 노드를 연결할 수 있기 때문에)
* 오름차순 정렬할 때는 priority queue 를 이용, 순환여부를 체크할 때는 union find 알고리즘 사용
* 
* 프림 알고리즘 (노드 중심으로 체크) : Priority Queue 를 활용
* 각 노드마다 최소 가중치의 간선을 찾아 연결하는 방식
* 노드를 방문하면서 해당 노드와 연결된 간선의 가중치를 오름차순으로 연결된 노드와 함께 저장 
(해당 노드에 붙어있는 간선을 싹 다 priority queue 에 넣어주는 것)
* 가중치가 작은 간선 순으로 연결된 노드의 방문 여부를 체크하여, 
* 방문하지 않았던 경우에는 해당 노드를 다음 탐색 노드로 지정
* - 시작 노드와 무관하게 항상 최적의 해를 도출할 수 있음 (임의의 노드에서 시작해도 항상 같은 결과)
* - 전체 노드를 방문하면 탐색 종료
* 
* 
* 


*/

//6일차 0110 union-find, MST(최소신장트리), 위상정렬(topological)
//7일차 0111 다익스트라, 플로이드 와샬
//8일차 0112
//9일차 0113
//10일차 0114