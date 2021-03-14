#include <iostream>
using namespace std;
class Rect{
	int r;
	int c;
public:
	Rect(int a=0, int b=0) : r(a), c(b) {}
	
	int GetArea() const {
		return r*c;
	}
};
void foo(const Rect& r){
	int area = r.GetArea();
}
int main(){
	Rect r(2, 5);
	foo(r);
}
// main에서 Rect r객체는 상수객체가 아니지만 void foo(const Rect& r)에서 
// 받은 r이 GetArea()를 호출해주기 위해서는 GetArea()함수가 상수함수여야 하는건가.. 
