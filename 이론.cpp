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

*/

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

/* 에라토스테네스의 체 Sieve of Eratosthenes (소수구하기 알고리즘 중에 가장 중요 아주 중요 매우 중요)
  => O(NloglogN) for문N번 * if문(loglogN상당히복잡)
  안쪽for문의 j 는 N의 크기에 따라서, i*i 또는 i*2 로 바꾸는 것이 좋다.
  왜냐하면 i=백만인 경우 i*i는 1조가 되는데 int가 2백만정도 까지 이기 때문

  모든 소수는 6n+1또는 6n+5 의 꼴을 띈다.
*/
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

/* 골드바흐의 추측 Goldbach's conjecture 
2 보다 큰 모든 짝수는 두 소수의 합으로 표현이 가능하다. --+3--> 5보다 큰 모든 홀수는 세 소수의 합으로 표현 가능하다.
check[N-b] == false 인지 확인
*/

/* 팩토리얼 Factorial 부르트포스때 중요 10!=3백만, 20!=int범위벗어남
 nCm = n!/((n-m)!m!) : 2의 갯수 > 5의 갯수 일 수 도 있기에 둘다 세어보고 더 적은것의 갯수 알아야함
*/