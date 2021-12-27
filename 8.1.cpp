/*
8.1
���ȣ�� : �ڱ��ڽ��� ȣ�� 
	Divide and Conquer ���� : ������ �ɰ��� �ɰ��� �� �ɰ� �� �ذ��� �� �ִ� ������ ������ �ذ� �Ŀ� ����(Merge)
	������ �ݺ��Ǵ� ���ȣ���� ����. �Լ�ȣ���� �ý��۽����� ����ϱ� ������ Stack Overflow�� ���� => ���α׷� �ٿ�
���ȣ���� ��� : ������ ũ��� ���� �۾����� �ϰ� ���ȣ���� ������ ���������� �־�� �Ѵ�
Context(call stack)

8.2
�Ǻ���ġ ������ ����
Fn = Fn-1 + Fn-2, (F1=F2=1)

8.3
�ϳ����� ž

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
�÷����� FloodFill
*/

void RasterSpace::FloodFill(int x, int y, int nFillColor, int nSelColor)
{
	if (nSelColor < 0)	// ���� ���̴�
		nSelColor = GetPixel(x, y);
}