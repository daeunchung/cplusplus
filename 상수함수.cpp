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
// main���� Rect r��ü�� �����ü�� �ƴ����� void foo(const Rect& r)���� 
// ���� r�� GetArea()�� ȣ�����ֱ� ���ؼ��� GetArea()�Լ��� ����Լ����� �ϴ°ǰ�.. 
