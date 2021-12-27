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
	MyClass obj[5];		// �迭 ��ĭ���� ��ü�ϳ��� ����
	
	cout << "Test #1 : " << endl;
	for(int i=0; i<5; i++){
		obj[i].Check(obj); 
	}
		
	cout << "Test #2 : " << endl;
	for(MyClass &i : obj){	// ������� for�� �迭�� ��ĭ�� ��ü�� ����Ű�� reference ���� MyClass &i 
		i.Check(obj); 
	}
		
	cout << "cnt = " << MyClass::cnt << endl;
}

/*
i.Check(obj); �ϸ�  void Check(MyClass *ptr){ ���� 
MyClass * ptr = obj; �� �ް� �ǰ� 
ptr + num �� &obj[num] �� �ȴ�. 
this�� �ڽ��� �����ִ� ��ü�� ����Ű�� ������ 

���� �ڵ忡�� if(ptr+num == this) ������ �׻� �����ϰ� �ȴ�. 
*/
