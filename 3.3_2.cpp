/*
 3.3 Copy Constructor vs Assignment (���Կ����� equal������ "=") 
�� ���� �����ǰ� �ʿ��Ѱ�? Shallow copy vs Deep copy (Default�� Shallow Copy)
���� ���̴�? 
	�����ڴ� �ʱ���¿��� ����. 					String str1 = str2;
	Assignment�� ���� �����͸� ����� ���� �Ҵ�		str1 = str2;
*/	

 
/* 
str1 = str2; �� �ϴ� ��쿡 
str2�� "Test String"�� ����Ű�� �������̰� ���ڿ��� ����Ǵ� �ΰ����� �޸𸮸� ������ ��������
str1�� �޸𸮸� ���� �Ҵ��ؼ� �������� �ʰ�, 
�ܼ��� ������(�����Ͱ� ����� �ּ�)�� �� ������ ���� ���� Shallow copy ���� ������ �Ѵ�. 
�̶� str2�� life-time�� ���ؼ� �Ҹ�Ǹ� ~Destructor�� ȣ��ǰ� 
�� �������� "Test String"�� ����� �޸𸮸� delete �ϴ� _clear()�� ����ȴ�. �׷� str1�� ������ ����Ű�� �����߻� !!!
(str1 str2�� �����޸𸮸� ����Ű�� ���ʿ��� �޸�delete�ϸ� �ٸ��ʿ��� �����߻�)

���� str1 = str2; �� �Ҷ��� 
str1 �� ������ �����͸� ������ ���ο� �޸𸮸� �Ҵ��� �Ŀ� ������ �������־���Ѵ�. Deep copy
str1�� "Test String"�� �޸𸮹��ۿ� str2�� "Test String"�� �޸𸮹��۴� "������ ����" �̰� �ȴ�. 
�� ������ �߿� �ѳ��� ������ �ٸ��� ������ ����.  

��� : � Ŭ������ ���������� �ܺο� � "�޸𸮸� �Ҵ�"�ϴ� Ŭ������ ���, 
		�ݵ�� Copy Constructor(����������)�� Assignment(=������) �� ������ �Ͽ� 
		�����͸� �����ϴ� ���� �ƴϰ� ������ �޸𸮸� �Ҵ�޾� ������ �޸𸮹��� ���� ��ü�� ������ ������ ������Ѵ�. 
*/		
		
		
/*		
�������� �켱����(Precedemce)�� ���ռ���(Associativity)
�Ҵ翬���ڴ� <- ����, �׿� ��κ� -> ���� 
MSDN Library ���ο� precedence �˻� �ڼ��� �˼��ִ�.  
 
str = String("aaa") + "bbb" + "ccc"; 	
   String("aaa")��ü�� +������ ���ֱ� ���ؼ� 
   "bbb"�� String::String(const char* lpsz) �����ڷ� ��üȭ �ȴ�. 
   ���� String String::operator + (const String& str) �� ���డ���ϴ�. 
   + ������ �ӿ��� Concat()�Լ��� ����־ �� ���ڿ��� �̾��ش�. 
str1 = str2 = str3 = str4; 	
   �Ҵ翬���� �����ʺ��� �� �־��ش�. �ᱹ str1 2 3 ��� str4�� �ȴ�.  
*/


/*
�� Ÿ�԰��� ��ȣ��ȯ
 - �ΰ��� User Defined Class�� ���
 	��ȣ���� classŸ���� ���ڷ� �ϴ� ������ A::A(B) �� B::B(A)
 	
 - �ϳ��� Class�� Primitive Data Type (StringŬ������ const char* ������Ÿ���� ���)
    String <-- const char*			String::String(const char*); �����ڷ� 
    String --> const char*			String::operator const char*(); ����ȯ �����ڸ� �������Ͽ� ��� 
    ����ȯ ������ ����) str2 = (const char*)str1;
*/
