String some_function(String str)	// str1가 매개변수로 넘어오며 복제생성자 호출 
{
	String strReturn;
	// do something
	return strReturn;				// strReturn이 str2로 넘어올때 복제생성자 호출 
}

int main(){
	String str1 = "Test String";	// (const char*) constructor 동작
	String str2 = str1;				// copy constructor "=" 은 연산자X 생성자호출O. str1으로 str2 객체를 생성
	// C++컴파일러는 위 문장을 String str2(str1); 과 동일하게 해석

	String str3;					// default constructor
	str3 = str1;					// assignment operator "=" 은 equal연산자(대입)로 동작 
	
	str2 = some_function(str1);		// call by value 	str1가 some_function함수의 입력값으로 들어가면서 복제생성자 호출 
}
/*
 복제생성자 (Copy Initializer Constructor) 
 : 같은 타입의 객체로부터 새로운 객체를 생성 X::X(const X&) 
 복제생성자가 사용되는 경우 1. 다른객체로부터 만들어질때 2. 객체를 함수의 인자로 넘길때 3. 함수에서 객체를 리턴할때 
 */
