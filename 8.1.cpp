/*
8.1
재귀호출 : 자기자신을 호출 
	Divide and Conquer 전략 : 문제를 쪼개고 쪼개고 또 쪼갠 후 해결할 수 있는 단위가 나오면 해결 후에 조합(Merge)
	무한히 반복되는 재귀호출은 오류. 함수호출은 시스템스택을 사용하기 때문에 Stack Overflow를 유발 => 프로그램 다운
재귀호출의 요건 : 문제의 크기는 점점 작아져야 하고 재귀호출이 끝나는 종료조건이 있어야 한다
Context(call stack)

8.2
피보나치 수열의 정의
Fn = Fn-1 + Fn-2, (F1=F2=1)

8.3
하노이의 탑

*/

// recursive
int fibonacci(int n) {
	if (n == 1 || n == 2) return 1;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}

// non-recursive (iterative)
int fibo_nr(int n)
{
	int r = 0;
	int a = 1;
	int b = 1;
	if (n == 1 || n == 2) return 1;
	while (n-- > 2) {
		r = a + b;
		a = b;
		b = r;
	}
	return r;
}

/*
8.4
플러드필 FloodFill
*/

void RasterSpace::FloodFill(int x, int y, int nFillColor, int nSelColor)
{
	if (nSelColor < 0)	// 최초 콜이다
		nSelColor = GetPixel(x, y);
}