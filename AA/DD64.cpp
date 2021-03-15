#include <iostream>

using namespace std;

class MyClass {
public:
	MyClass() : num(cnt++), ch('\0') {}
	
	void Check(MyClass *ptr){
		if(ptr+num == this){
			cout << num << endl;
		}
	}
	static int cnt;
private:
	int num;
	char ch;
};

int main(){
	MyClass obj[5];		// 배열 각칸마다 객체하나씩 생성
	
	cout << "Test #1 : " << endl;
	for(int i=0; i<5; i++){
		obj[i].Check(obj); 
	}
		
	cout << "Test #2 : " << endl;
	for(MyClass &i : obj){	// 범위기반 for문 배열의 각칸의 객체를 가리키는 reference 변수 MyClass &i 
		i.Check(obj); 
	}
		
	cout << "cnt = " << MyClass::cnt << endl;
}

/*
i.Check(obj); 하면  void Check(MyClass *ptr){ 에서 
MyClass * ptr = obj; 로 받게 되고 
ptr + num 은 &obj[num] 이 된다. 
this는 자신이 속해있는 객체를 가리키는 포인터 

위의 코드에서 if(ptr+num == this) 조건은 항상 성립하게 된다. 
*/
