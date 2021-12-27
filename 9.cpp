/*
9.1 ������ ����

9.2 ���� ���� : ���ĵ��� ���� �κп��� �ּڰ��� ã�� ���ĵ� �κ��� �ڿ� ���� 
SelectionSort(�迭, �迭ũ��)
{
	while (���ĵ� �κ��� ũ�� < �迭ũ��)
	{
		min = ���ĵ��� ���� �κ��� �ּڰ�;
		���ĵ��� ���� �κ��� ó������ min�� ��ȯ;
		���ĵ� �κ��� ũ�� 1����;
	}
}

���������Ÿ���� ��� : 
	�ݵ�� �ʿ��� Default Constructor, Copy Constructor, Operator=, Operator==, 
	Operator> �񱳷� gt�� ���. ������ ������� b>a, a>b||a==b, b>a||a==b, !(a==b)

9.3 ���� ���� : ���� ���ڵ带 �Ϻ� ���ĵ� �κ��� ������ ��ġ�� �ű�. ������ ��ġ�� ���� ã�°��� �ӵ��� ����. BinarySearch �� �̿��� ��������
InsertionSort(�迭, �迭ũ��)
{
	while(���ĵ� �κ��� ũ�� < �迭ũ��)
	{
		t = ���ĵ��� ���� �κ��� �� ��;
		���ĵ� �κп��� t�� ������ ��ġ ã�� ����;
		���ĵ� �κ��� ũ�� 1����;
	}
}

9.4 ���� ���� : ��������� ��/��ȯ�� ���� �ִ��� ���� �ڷ� ������ ����
BubbleSort(�迭, �迭ũ��)
{
	while(���ĵ� �κ��� ũ�� < �迭ũ��)
	{
		for(j=1; j<���ĵ� �κ� ũ��; j++)
		{
			�迭[j-1]�� �迭[j]���� ũ�� �ΰ� ��ȯ;
		}
		���ĵ� �κ��� ũ�� 1 ����;
	}
}
	
	
	*/
template <class TYPE> 
void SelectionSort(TYPE a[], int n)
{
	TYPE min;		// �ּڰ� ����
	int min, index;	// �ּڰ� �ε��� ����
	int i, j;
	for (i = 0; i < n; i++)
	{
		minindex = i;	// �ּڰ��� �ʱ⼳��
		min = a[i];
		for (j = i + 1; j < n; j++)
		{
			if (min > a[j])
			{
				min = a[j];
				minindex = j;
			}
		}
		a[minindex] = a[i];
		a[i] = min;
	}
}

class MyClass
{
public:
	MyClass();
	MyClass(const MyClass& c);
	MyClass& operator=(const MyClass& c);
	bool operator==(const MyClass& c) const;
	bool operator>(const MyClass& c) const;
	// other member functions
private:
	// member variables
};

template <class TYPE> 
void InsertionSort(TYPE a[], int n)
{
// ù��°�� ���ĵǾ��ִٰ� ����


}
template <class TYPE> 
void BubbleSort(TYPE a[], int n)
{

}

template <class TYPE>
void BubbleSort2(TYPE a[], int n)	// ����ver
{
	int i, j;
	TYPE t;
	bool sorted;
	for (i = 0; i < n - 1; i++) {
		sorted = true;
		for (j = 1; j < n - 1; j++) {
			if (a[j-1] > a[j]){
				t = a[j - 1];
				a[j - 1] = a[j];
				a[j] = t;	// ���Կ�����3�� ��ȿ����
				sorted = false;
		}
	}
		if (sorted) break;
}

/*
�˰��� ����ð� �м�
GetTickCount�� msec��� 
worst case ���� 
average case ����
best case ���ĵ�
*/