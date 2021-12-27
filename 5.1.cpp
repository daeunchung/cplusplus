/* 5.1 ���Ḯ��Ʈ 
������ �˱⿡ �������� �ʾҰ�, ���Ḯ��Ʈ�� �˱����ؼ� �������� Class Template, Exception Handling

Class Template : Ÿ���� �Ķ����ȭ(�Ű�������) �ϴ� ��
���Ḯ��Ʈ�� �ٸ� ������Ÿ���� �����ϴ� Container ����. Ÿ�Կ� ���� ���������� �ʰ� ����� �� �־���Ѵ�. 
�Ϲ� class ���ǽÿ� �տ� template <class T> �� �߰����ְ� 
�ܺο��� �Լ� ���ǽ� Ŭ�������� 'Ŭ������<T>'�� ���� �Ķ����ȭ�Ͽ� �����ش�. 

Function Template : �޴� �Ű������� Ÿ�Ը� �ٸ��� �����ϴ� ������ �����Ͽ� 
	�Լ��� ������ ������ �ʾƵ� �ǰԲ� �Ѵ�.
*/
// ������ (template�� ���ÿ� include�Ǿ���ϴ� header�� �̴�) 
template <class T> class Node{ // T ��ſ� int, T, S, X, String... �� �� �� �ִٴ� �Ҹ� 
private:
	T data;
	Node* pNext;
public:
	T& GetData(){return data;} 	// ���ο��� �Լ����� 
	T& SetData(const T& d);		// �ܺο��� �Լ����� 
}
template <class T> T& Node<T>::SetData(const T& d){ // ��ȯŸ��T&  Ŭ������Node<T>  �Լ���SetData  �Է�Ÿ��const T& d 
	return data = d;
} 

// ���� ���� 
#include "Node.h"
Node<int> IntNode;
IntNode.SetData(5);

typedef Node<String> StringNodeClass;
StringNodeClass StringNode;
StringNode.SetData("aaa");

// ���� ��ü�� ��üȭ instantiation. 
//	���� IntNode, StringNode���� SetData()�Լ��� ���Ǿ���. ���� SetData()�Լ��� ��üȭ �ȴ�.
//	 ������ �ʴ� ��� �Լ����� ��üȭ �Ǵ� ���� �ƴϱ� ����. ���� class ��ü�� ��üȭ ���ַ��� �Ʒ�ó�� !!
template Node<double>; 	// class Node<double> ��ü�� ��üȭ �ǰ� �ϴ� ��� 







/*
Exception Handling : 
 - Exception�� throw�ϸ� try������ catch��
 - ������ ���� ���ϴ� Ư���� ��쿡�� �ʼ� ��� 
		Constructor/Destructor, class template���� �Ķ����Ÿ���� ������ ��� 

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
		// ������ �߻���Ű�� �Լ��� try-catch������ �����ش�. 
		func();
	} catch (MyException e){
		// error process
	} catch (...) {
		// all other errors ������ �ɸ��� ���� ��� exception�� ���⼭ �޾ƶ� 
	}
}





