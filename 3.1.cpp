class String
{
protected : 
	char *m_pBuffer;	// ��Ʈ�� ����
	void _init();		// ���� �Լ���
	void _clear();
	void _copy(const char* lpsz); 		// const char* lpsz : c++ ��Ÿ���� native string 
public : 
	// constructors, destructor
	// operators
	// other member functions
}

void String::_init(){
	m_pBuffer = 0;
}
void String::_clear(){
	if(m_pBuffer) 
		delete[] m_pBuffer;
	_init();
}
void String::_copy(const char* lpsz){
	if(lpsz!=0){
		int len = strlen(lpsz);
		m_pBuffer = new char [len+1];
		if(m_pBuffer)
			strcpy(m_pBuffer, lpsz);
	}
}
