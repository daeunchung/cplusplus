/* 5.1 연결리스트 
개념은 알기에 정리하지 않았고, 연결리스트를 알기위해서 선수지식 Class Template, Exception Handling

Class Template : 타입을 파라미터화(매개변수로) 하는 것
연결리스트는 다른 데이터타입을 수용하는 Container 역할. 타입에 따라 재정의하지 않고 사용할 수 있어야한다. 
일반 class 정의시에 앞에 template <class T> 만 추가해주고 
외부에서 함수 정의시 클래스명을 '클래스명<T>'와 같이 파라미터화하여 적어준다. 

Function Template : 받는 매개변수의 타입만 다르고 동작하는 로직은 동일하여 
	함수를 여러개 만들지 않아도 되게끔 한다.
*/
// 구현부 (template은 사용시에 include되어야하는 header부 이다) 
template <class T> class Node{ // T 대신에 int, T, S, X, String... 다 올 수 있다는 소리 
private:
	T data;
	Node* pNext;
public:
	T& GetData(){return data;} 	// 내부에서 함수정의 
	T& SetData(const T& d);		// 외부에서 함수정의 
}
template <class T> T& Node<T>::SetData(const T& d){ // 반환타입T&  클래스명Node<T>  함수명SetData  입력타입const T& d 
	return data = d;
} 

// 실제 사용부 
#include "Node.h"
Node<int> IntNode;
IntNode.SetData(5);

typedef Node<String> StringNodeClass;
StringNodeClass StringNode;
StringNode.SetData("aaa");

// 정의 전체를 객체화 instantiation. 
//	위의 IntNode, StringNode에서 SetData()함수만 사용되었다. 따라서 SetData()함수만 객체화 된다.
//	 사용되지 않는 모든 함수까지 객체화 되는 것이 아니기 때문. 따라서 class 전체를 객체화 해주려면 아래처럼 !!
template Node<double>; 	// class Node<double> 전체가 객체화 되게 하는 방법 







/*
Exception Handling : 
 - Exception을 throw하면 try절에서 catch함
 - 리턴을 하지 못하는 특수한 경우에는 필수 사용 
		Constructor/Destructor, class template에서 파라미터타입을 리턴할 경우 

*/

class MyException{
public:
	int m_nErrorNo;
	String m_strReason;
};
void func(){
	// do something
	if(error_occurred){
		MyException e;
		e.m_nErrorNo = 10;
		e.m_strReason = "Critical";
		throw e;
	}
}
void other_func(){
	try{
		// 에러를 발생시키는 함수는 try-catch문으로 감싸준다. 
		func();
	} catch (MyException e){
		// error process
	} catch (...) {
		// all other errors 위에서 걸리지 않은 모든 exception을 여기서 받아라 
	}
}





