/*
������(�Ͻ���) ����ȯ implicit conversion
����� ����ȯ explicit conversion

���������, �̵������ڴ� �޴� �Ű������� ���º��Ͱ� �޶�����
��ȯ�����ڴ� ���� �ֱ⺸�ٴ� ����ȯ�� ������ �������� �� ������ ��ȯ�����ڶ�� �θ���. 

����ȯ ������ �տ� explicit Ű���带 �ٿ��ָ� ��������� �������� ������ ����Ұ��� => �������߸� ����ȯ 
 : ������ ����ȯ���� ���� ��ġ�ʴ� Ÿ������ �߸� ����ȯ �Ǿ� ������ ����� ���� �������� ��� 
��ȯ�����ڷ� ������ ����ȯ�� �Ͼ�� �͵鵵 ������ �տ� explicit �ٿ��ָ� �ڵ���ȯX 

*/

#include <iostream>
#include <string>

using namespace std;

class Item {
public:
	///// A /////
	Item(int num) : num(num){	// ��ȯ������ ���Ҽ��� 
		// �� �����ڰ� int�� Item���� ��ȯ���ִ� ���ұ��� �������־��� �� 
		cout << "Item(int)" << endl;
	}	
	/////////////
	
	Item(string name) : name(name){ // ��ȯ������ ���Ҽ���
		cout << "Item(string)" << endl;
	}
	Item(int num, string name) : num(num), name(name){
		cout << "Item(int, string)" << endl;
	}
	void print(){
		cout << num << " : " << name << endl;
	}
	
	// intŸ�������� ����ȯ ������ �����ε� (��������� �ٸ���. ó���� ���� ��ȯŸ����  
	explicit operator int() const {					// ����������ȯ �����س��� explicit ����� �� 
		return num; 
	}
	// string������ ����ȯ ������ 
	explicit operator string() const {	
	// to_string() : <string>�Լ�. ����->���ڿ� 
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
	// a�� aaa(3)ó�� int�� ���͵� ������ ����ȯ�� �Ͼ�ϱ� ����X 
} 


int main(){
	Item i1 = Item(1);	// ������ ȣ�� 		A�� �⺻�����ڷ� ���� --- B
	Item i2(2);			// ���� ������ ǥ�� 
	Item i3 = 3;		// ������ ȣ�� 
	
	i3 = 3;	// Item = int ? ��� �̵����Կ����ڷ� ������ �Ǵ��� ? Item &Item::operator=(Item &&) ȣ�� 
// A�� ��ȯ�����ڷ� �����Ͽ� 3�̶�� int�� Item �ӽð�ü�� ����ȯ. ���Ŀ� �ӽð�ü�� �̵�������(��������)�� i3�� ���ԵǴ� ��
// => ������ ����ȯ 
	Item i4 = (Item)4;	// ����� ����ȯ 	A�� ��ȯ�����ڷ� ���� --- C
	// B�� C�� ���������� ȣ��Ǿ� ��������� ���� ���� �����ϴ� ���̴� ���� ���ٴ� ���� �˾ƾ��Ѵ�.
	
//	Item i5 = "stone";		Item i5("stone");	����ǥ��
	Item i5(5);
	
//	i5 = "stone"; //ERROR : C++�� C�� Ȯ�����̱⿡ "stone"�� const char[6]�� ����. Item(string)�� ������ Item(const char)�� ������ �ȵȴٴ� �� 
//	Item(const char){} ������ָ� �Ǵµ� �ʹ� �������� ����ȯ ���ָ� �ȴ�.
//	i5 = string("stone");
	i5 = (string)"stone";
	 
	Item i6(1, "grass");
	Item i7 = { 2, "dirt" };
	i7 = { 2, "dirt" };		// C++11�� ����������ȯ ���� (�������Ϸ������� X)
	Item i8{ 3, "wood" };

	int itemNum1 = (int)i8;	// ����� ����ȯ //  C C++���� ����ȯ�� ������ => �����ε� ���ָ� �ȴ�. 
	int itemNum2 = i7;		// ������ ����ȯ 
	cout << itemNum1 << endl;
	cout << itemNum2 << endl;
	
	println((string)i8);	// ����� ����ȯ
//	println(i8);			// ������ ����ȯ 
	// println(int ), println(string ) �����ε��ؼ� �ΰ��� �Լ��� ������ 
	// �Ѵ� �Ǳ� ������ �����Ϸ��� ���α׷����� �ǵ��� ���� ���� �̸� ���� �߻���Ų��.  
	// �׷� ��쿡�� ������ ����ȯ ���Ұ���
	println((int)i8) ;
	
}
