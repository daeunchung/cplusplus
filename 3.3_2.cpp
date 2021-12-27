/*
 3.3 Copy Constructor vs Assignment (대입연산자 equal연산자 "=") 
왜 둘의 재정의가 필요한가? Shallow copy vs Deep copy (Default는 Shallow Copy)
둘의 차이는? 
	생성자는 초기상태에서 시작. 					String str1 = str2;
	Assignment는 기존 데이터를 지우고 새로 할당		str1 = str2;
*/	

 
/* 
str1 = str2; 를 하는 경우에 
str2가 "Test String"을 가리키는 포인터이고 문자열이 저장되는 부가적인 메모리를 가지고 있을때에
str1에 메모리를 새로 할당해서 복사하지 않고, 
단순히 포인터(데이터가 저장된 주소)만 싹 복사해 놓은 것을 Shallow copy 얕은 복사라고 한다. 
이때 str2가 life-time을 다해서 소멸되면 ~Destructor가 호출되고 
그 과정에서 "Test String"이 저장된 메모리를 delete 하는 _clear()가 실행된다. 그럼 str1은 빈통을 가리키고 에러발생 !!!
(str1 str2가 같은메모리를 가리키니 한쪽에서 메모리delete하면 다른쪽에서 에러발생)

따라서 str1 = str2; 를 할때에 
str1 도 동일한 데이터를 저장할 새로운 메모리를 할당한 후에 내용을 복사해주어야한다. Deep copy
str1의 "Test String"의 메모리버퍼와 str2의 "Test String"의 메모리버퍼는 "완전히 별개" 이게 된다. 
두 포인터 중에 한놈을 지워도 다른놈에 영향이 없다.  

결론 : 어떤 클래스가 내부적으로 외부에 어떤 "메모리를 할당"하는 클래스일 경우, 
		반드시 Copy Constructor(복제생성자)와 Assignment(=연산자) 를 재정의 하여 
		포인터만 복사하는 것이 아니고 별도의 메모리를 할당받아 원조의 메모리버퍼 내용 전체를 복사해 오도록 해줘야한다. 
*/		
		
		
/*		
연산자의 우선순위(Precedemce)와 결합순서(Associativity)
할당연산자는 <- 방향, 그외 대부분 -> 방향 
MSDN Library 색인에 precedence 검색 자세히 알수있다.  
 
str = String("aaa") + "bbb" + "ccc"; 	
   String("aaa")객체와 +연산을 해주기 위해서 
   "bbb"가 String::String(const char* lpsz) 생성자로 객체화 된다. 
   따라서 String String::operator + (const String& str) 가 수행가능하다. 
   + 연산자 속에는 Concat()함수가 들어있어서 두 문자열을 이어준다. 
str1 = str2 = str3 = str4; 	
   할당연산자 오른쪽부터 쭉 넣어준다. 결국 str1 2 3 모두 str4가 된다.  
*/


/*
두 타입간에 상호변환
 - 두개의 User Defined Class인 경우
 	상호간의 class타입을 인자로 하는 생성자 A::A(B) 와 B::B(A)
 	
 - 하나의 Class와 Primitive Data Type (String클래스와 const char* 데이터타입일 경우)
    String <-- const char*			String::String(const char*); 생성자로 
    String --> const char*			String::operator const char*(); 형변환 연산자를 재정의하여 사용 
    형변환 연산자 예시) str2 = (const char*)str1;
*/
