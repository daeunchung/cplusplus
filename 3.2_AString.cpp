// constructors

String::String()
{
	_init();
}

// 복제생성자 X::X(const X&) 나도메모리만들고 다른객체의 버퍼값을 내게로 복사
String::String(const String& stringSrc)		 
{
	_init();
	_copy(stringSrc.m_pBuffer);
} 

String::String(const char* lpsz)
{
	_init();
	_copy(lpsz);
}

String::String(char* lpsz)
{
	_init();
	_copy(lpsz);
}

String::String(char ch)
{
	char str[2];
	str[0] = ch;
	str[1] = 0;
	
	_init();
	_copy(str);
}

String::String(long l)
{
	_init();
	Format("%d", l);
	// Format 은 String class의 멤버함수, string화된 타입이 설정된다. 
}

String::String(int i)
{
	_init();
	Format("%d", i);
}

String::String(double d)
{
	_init();
	Format("%g", d);
}

String::~String()
{
	_clear();
}

// Assignment Operator 대입연산자
const String& String::operator = (const String& stringSrc)
{
	_clear();
	_copy(stringSrc.m_pBuffer);
	return *this;
}

String String::operator + (const String& str)
{
	String str2;
	str2 = *this;	// 포인터를 역참조 dereference 
	str2.Concat(str);
	return str2;
}

void String::SetAt(int index, char ch)
{
	if(index >= 0 || index < GetLength())
		m_pBuffer[index] = ch;
} 

void String::Concat(const String& str)
{
	if(str.GetLength() == 0)	// 더할게 없으면
		return;
	int len = GetLength() + str.GetLength() + 1; 
	char *ptemp = new char[len];
	if(ptemp == 0) return;	// 메모리 할당 에러
	
	ptemp[0] = 0;			// 빈 스트링으로 설정
	
	if(!IsEmpty()) strcpy(ptemp, m_pBuffer);
	if(!str.IsEmpty()) strcat(ptemp, str.m_pBuffer); 
	
	_clear();				// 기존의 버퍼 지움
	m_pBuffer = ptemp; 		// 새 버퍼 넣어주기 
}

// 뒤에 const는 멤버가 내부에서 변하지 않는다는 것을 의미 
// 반환타입은 너무 당연하게 const char*이기 때문에 생략된 것이다. 
String::operator const char*() const	
{
	return m_pBuffer;
} 
