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


/* DP 
문제에서 DP의 '한단계' 가 될 부분의 정의를 찾고 점화식을 설립

*/





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




/*
그래프 구현 방법 
1. 인접행렬
2. 인접리스트
3. 간선리스트


bfs / dfs 
종만북에 bi-directional BFS 로 15 puzzle 문제 푸는 것 나와있음

ch4/sssp(single source shortest path 최단거리 ) - 벨만포드, 다익스트라, bfs...

*/


// set 이 bst와 유사한 구조로 되어있음
