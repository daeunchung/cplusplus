/*
���� - ������ ����
�������信�� ������ ������� X, �������� ������ ������ ���� ����O
���ϱ�� ���ϱ��� �����̶� ���� ����
(A + B)mod M = ((A mod M) + (B mod M)) mod M
(A * B)mod M = ((A mod M) * (B mod M)) mod M
(A - B)mod M = ((A mod M) - (B mod M) + M) mod M

���� - �ִ����� GCD (1.�׳�, 2.��Ŭ����ȣ����)


���� - �ּҰ���� LCM
A * B = GCD * LCM �� �̿�

���� - �Ҽ� �˰��� 2��
1. � �� N �� �Ҽ� ���� �Ǻ�
2. N���� �۰ų� ���� ��� �ڿ��� �� �Ҽ� ã��


dp - Top down ���ȣ��
dp - Bottom up �ݺ���


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

// N�� ��� �߿��� ���� ū ���� N/2���� �۰ų� ���� ������ ���� ����
bool prime2(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= n/2; i++) {
		if (n % i == 0) return false;
	}
	return true;
} // => O(N/2) = O(N)

// ���� ���� : ��ǻ�Ϳ��� �Ǽ��� �ٻ簪�̱⿡ i*i<=n ǥ���� ����
bool prime3(int n)
{
	if (n < 2) return false;
	for (int i = 2; i*i<=n; i++) {
		if (n % i == 0) return false;
	}
	return true;
} // => O(��ƮN)
*/


/* �����佺�׳׽��� ü Sieve of Eratosthenes (�Ҽ����ϱ� �˰��� �߿� ���� �߿� ���� �߿� �ſ� �߿�)
  => O(NloglogN) for��N�� * if��(loglogN���������)
  ����for���� j �� N�� ũ�⿡ ����, j = i*i���ٴ� i+i �Ǵ� i*2 �� �ٲٴ� ���� ����.
  �ֳ��ϸ� i=�鸸�� ��� i*i�� 1���� �Ǵµ� int�� 2�鸸���� ���� �̱� ���� (overflow�߻�)

  ��� �Ҽ��� 6n+1�Ǵ� 6n+5 �� ���� ���.

void Eratosthenes()
{
	int prime[100];	// �Ҽ� ����
	int pn = 0;		// �Ҽ��� ����
	bool check[101];	// ���������� true(�Ҽ��� �ƴϴ�), ���������� false(�Ҽ�)
	int n = 100;
	for (int i = 2; i <= n; i++)
	{
		if (check[i] == false)	// �������� �ʾ�����
		{
			prime[pn++] = i;
			for (int j = i * i; j <= n; j += i) {
				check[j] = true;
			}
		}
	}
} //=> O(NloglogN) for��N�� * if��(loglogN���������)

*/

/* �������� ���� Goldbach's conjecture 
2 ���� ū ��� ¦���� �� �Ҽ��� ������ ǥ���� �����ϴ�. --+3--> 5���� ū ��� Ȧ���� �� �Ҽ��� ������ ǥ�� �����ϴ�.
check[N-b] == false ���� Ȯ��
*/

/* ���丮�� Factorial �θ�Ʈ������ �߿� 10!=3�鸸, 20!=int�������
 nCm = n!/((n-m)!m!) : 2�� ���� > 5�� ���� �� �� �� �ֱ⿡ �Ѵ� ����� �� �������� ���� �˾ƾ���
*/





/* �ڷ���
char
signed char	1����Ʈ, 8��Ʈ - 128 ~ 127

unsigned char	1����Ʈ, 8��Ʈ	0 ~ 255

short
short int	2����Ʈ, 16��Ʈ - 32,768 ~ 32,767	int ���� ����

unsigned short
unsigned short int	2����Ʈ, 16��Ʈ	0 ~ 65,535	int ���� ����

int
signed int	4����Ʈ, 32��Ʈ - 2,147,483,648 ~ 2,147,483,647

unsigned
unsigned int	4����Ʈ, 32��Ʈ	0 ~ 4,294,967,295	int ���� ����

long
long int
signed long
signed long int	4����Ʈ, 32��Ʈ - 2,147,483,648 ~ 2,147,483,647	int ���� ����

unsigned long
unsigned long int	4����Ʈ, 32��Ʈ	0 ~ 4,294,967,295	int ���� ����

long long
long long int
signed long long
signed long long int	8����Ʈ, 64��Ʈ - 9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807	int ���� ����

unsigned long long
unsigned long long int	8����Ʈ, 64��Ʈ	0 ~ 18,446,744,073,709,551,615	int ���� ����

*/


/*
// dp topdown ��� + �޸������̼�
int memo[100];
int fibonacci(int n) {
	if (n <= 1) return n;
	else {
		if (memo[n] > 0) return memo[n];
		memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
		return memo[n];
	}
}

// dp bottomup �ݺ���
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
�������� DP�� '�Ѵܰ�' �� �� �κ��� ���Ǹ� ã�� ��ȭ���� ����

*/





/* Tree
Ʈ���� �׷����̴�. ��Ʈ�� ���� ������ �������� �� �ִ�. ����Ŭ�� ���� ���� �׷���.
����(����X) :  ����N��, ����N-1�� 

Ʈ���� ǥ�� 
1. Ʈ���� �θ� �����ϴ� ��� (i, p[i]) 
UnionFind ���� ���
�θ�� �ݹ� ã����, �ڽ��� ã�� ���� N��ŭ �ɸ���.
2. ���� ���� Ʈ���� ��츸 �迭�� ǥ�� (�θ�x�϶�, �ڽ��� 2x, 2x+1)
Heap, SegmentTree �� ���
3. �׳� ���� Ʈ�� : ����ü, Ŭ����
struct Node { Node *left; Node *right; }
preorder : �Ϲ���dfs
inorder : ���ѹ� ���. BST���� ���� ������ �ο���successor ���
postorder : 


*/




/*
�׷��� ���� ��� 
1. �������
2. ��������Ʈ
3. ��������Ʈ


bfs / dfs 
�����Ͽ� bi-directional BFS �� 15 puzzle ���� Ǫ�� �� ��������

ch4/sssp(single source shortest path �ִܰŸ� ) - ��������, ���ͽ�Ʈ��, bfs...

*/


// set �� bst�� ������ ������ �Ǿ�����
