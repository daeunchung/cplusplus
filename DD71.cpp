/*
묵시적(암시적) 형변환 implicit conversion
명시적 형변환 explicit conversion

복사생성자, 이동생성자는 받는 매개변수의 형태부터가 달랐지만
변환생성자는 따로 있기보다는 형변환의 역할을 수행해줄 수 있으면 변환생성자라고 부른다. 

형변환 연산자 앞에 explicit 키워드를 붙여주면 명시적으로 적어주지 않으면 실행불가능 => 명시해줘야만 형변환 
 : 묵시적 형변환으로 인해 원치않는 타입으로 잘못 형변환 되어 에러가 생기는 것을 막기위해 사용 
변환생성자로 묵시적 형변환이 일어나던 것들도 생성자 앞에 explicit 붙여주면 자동변환X 

*/

#include <iostream>
#include <string>

using namespace std;

class Item {
public:
	///// A /////
	Item(int num) : num(num){	// 변환생성자 역할수행 
		// 이 생성자가 int를 Item으로 변환해주는 역할까지 수행해주었던 것 
		cout << "Item(int)" << endl;
	}	
	/////////////
	
	Item(string name) : name(name){ // 변환생성자 역할수행
		cout << "Item(string)" << endl;
	}
	Item(int num, string name) : num(num), name(name){
		cout << "Item(int, string)" << endl;
	}
	void print(){
		cout << num << " : " << name << endl;
	}
	
	// int타입으로의 형변환 연산자 오버로딩 (모양이조금 다르다. 처음에 적는 반환타입을  
	explicit operator int() const {					// 묵시적형변환 금지해놓음 explicit 지우면 됨 
		return num; 
	}
	// string으로의 형변환 연산자 
	explicit operator string() const {	
	// to_string() : <string>함수. 숫자->문자열 
		return to_string(num) + " : " + name;	
	}
	
private:
	int num;
	string name;
};

void println(string s){
	cout << s << endl;
}
void println(int n){
	cout << n << endl;
}

void aaa(double a){
	// a로 aaa(3)처럼 int가 들어와도 묵시적 형변환이 일어나니까 에러X 
} 


int main(){
	Item i1 = Item(1);	// 생성자 호출 		A가 기본생성자로 동작 --- B
	Item i2(2);			// 위와 동일한 표현 
	Item i3 = 3;		// 생성자 호출 
	
	i3 = 3;	// Item = int ? 어떻게 이동대입연산자로 대입이 되는지 ? Item &Item::operator=(Item &&) 호출 
// A가 변환생성자로 동작하여 3이라는 int를 Item 임시객체로 형변환. 이후에 임시객체가 이동생성자(얕은복사)로 i3로 대입되는 것
// => 묵시적 형변환 
	Item i4 = (Item)4;	// 명시적 형변환 	A가 변환생성자로 동작 --- C
	// B와 C는 같은생성자 호출되어 결론적으로 같은 동작 수행하는 것이니 보면 같다는 것을 알아야한다.
	
//	Item i5 = "stone";		Item i5("stone");	같은표현
	Item i5(5);
	
//	i5 = "stone"; //ERROR : C++도 C의 확장판이기에 "stone"을 const char[6]로 인지. Item(string)은 있지만 Item(const char)는 없으니 안된다는 뜻 
//	Item(const char){} 만들어주면 되는데 너무 귀찮으니 형변환 해주면 된다.
//	i5 = string("stone");
	i5 = (string)"stone";
	 
	Item i6(1, "grass");
	Item i7 = { 2, "dirt" };
	i7 = { 2, "dirt" };		// C++11의 묵시적형변환 문법 (옛컴파일러에서는 X)
	Item i8{ 3, "wood" };

	int itemNum1 = (int)i8;	// 명시적 형변환 //  C C++에서 형변환도 연산자 => 오버로딩 해주면 된다. 
	int itemNum2 = i7;		// 묵시적 형변환 
	cout << itemNum1 << endl;
	cout << itemNum2 << endl;
	
	println((string)i8);	// 명시적 형변환
//	println(i8);			// 묵시적 형변환 
	// println(int ), println(string ) 오버로딩해서 두가지 함수가 있으면 
	// 둘다 되기 때문에 컴파일러가 프로그래머의 의도를 알지 못해 미리 에러 발생시킨다.  
	// 그럴 경우에는 묵시적 형변환 사용불가능
	println((int)i8) ;
	
}
