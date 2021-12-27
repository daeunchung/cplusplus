// constructors

String::String()
{
	_init();
}

// ���������� X::X(const X&) �����޸𸮸���� �ٸ���ü�� ���۰��� ���Է� ����
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
	// Format �� String class�� ����Լ�, stringȭ�� Ÿ���� �����ȴ�. 
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

// Assignment Operator ���Կ�����
const String& String::operator = (const String& stringSrc)
{
	_clear();
	_copy(stringSrc.m_pBuffer);
	return *this;
}

String String::operator + (const String& str)
{
	String str2;
	str2 = *this;	// �����͸� ������ dereference 
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
	if(str.GetLength() == 0)	// ���Ұ� ������
		return;
	int len = GetLength() + str.GetLength() + 1; 
	char *ptemp = new char[len];
	if(ptemp == 0) return;	// �޸� �Ҵ� ����
	
	ptemp[0] = 0;			// �� ��Ʈ������ ����
	
	if(!IsEmpty()) strcpy(ptemp, m_pBuffer);
	if(!str.IsEmpty()) strcat(ptemp, str.m_pBuffer); 
	
	_clear();				// ������ ���� ����
	m_pBuffer = ptemp; 		// �� ���� �־��ֱ� 
}

// �ڿ� const�� ����� ���ο��� ������ �ʴ´ٴ� ���� �ǹ� 
// ��ȯŸ���� �ʹ� �翬�ϰ� const char*�̱� ������ ������ ���̴�. 
String::operator const char*() const	
{
	return m_pBuffer;
} 
