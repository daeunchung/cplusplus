/*
9.1 정렬의 개념

9.2 선택 정렬 : 정렬되지 않은 부분에서 최솟값을 찾아 정렬된 부분의 뒤에 더함 
SelectionSort(배열, 배열크기)
{
	while (정렬된 부분의 크기 < 배열크기)
	{
		min = 정렬되지 않은 부부의 최솟값;
		정렬되지 않은 부분의 처음값과 min을 교환;
		정렬된 부분의 크기 1증가;
	}
}

사용자정의타입의 사용 : 
	반드시 필요한 Default Constructor, Copy Constructor, Operator=, Operator==, 
	Operator> 비교로 gt만 사용. 나머지 연산들은 b>a, a>b||a==b, b>a||a==b, !(a==b)

9.3 삽입 정렬 : 현재 레코드를 일부 정렬된 부분의 적절한 위치로 옮김. 적절한 위치를 빨리 찾는것이 속도의 관건. BinarySearch 를 이용한 개선가능
InsertionSort(배열, 배열크기)
{
	while(정렬된 부분의 크기 < 배열크기)
	{
		t = 정렬되지 않은 부분의 한 값;
		정렬된 부분에서 t의 적절한 위치 찾아 삽입;
		정렬된 부분의 크기 1증가;
	}
}

9.4 버블 정렬 : 인접요소의 비교/교환을 통해 최댓값을 제일 뒤로 보내는 전략
BubbleSort(배열, 배열크기)
{
	while(정렬된 부분의 크기 < 배열크기)
	{
		for(j=1; j<정렬된 부분 크기; j++)
		{
			배열[j-1]이 배열[j]보다 크면 두값 교환;
		}
		정렬된 부분의 크기 1 증가;
	}
}
	
	
	*/
template <class TYPE> 
void SelectionSort(TYPE a[], int n)
{
	TYPE min;		// 최솟값 저장
	int min, index;	// 최솟값 인덱스 저장
	int i, j;
	for (i = 0; i < n; i++)
	{
		minindex = i;	// 최솟값의 초기설정
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
// 첫번째는 정렬되어있다고 가정


}
template <class TYPE> 
void BubbleSort(TYPE a[], int n)
{

}

template <class TYPE>
void BubbleSort2(TYPE a[], int n)	// 개선ver
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
				a[j] = t;	// 대입연산자3번 비효율적
				sorted = false;
		}
	}
		if (sorted) break;
}

/*
알고리즘 실행시간 분석
GetTickCount로 msec얻고 
worst case 역순 
average case 난수
best case 정렬된
*/