/*
��Ӱ��迡�� ����/�Ҹ��� ���� ������ ���� �Ҹ���

�ڽ�Ŭ������ �����ڰ� ȣ��ɶ� �θ�Ŭ������ �����ڰ� ���� ȣ��ȴ�. �Ҹ��ڴ� �������� ����
�������� ���� ��ü�� ����������� �ʱ�ȭ �ϱ� �����̴�. ���� �����ڰ� ����Ǳ� ���� ������� ���� �������Ѵ�.
������� ���� �����ǰ� �����ڰ� ȣ��Ǵ� ��

���� : (�ڽ�Ŭ���� ��ü������)
	�θ�Ŭ���� �������
	�θ�Ŭ���� ������
	�ڽ�Ŭ���� �������
	�ڽ�Ŭ���� ������

���� �Ҹ��� : �Ҹ��ڵ� �����Լ��� �� �� �ִ�
*/

#include <iostream>
using namespace std;

class Ice {
public:
	Ice() { cout << "Ice()" << endl; }
	~Ice() { cout << "~Ice()" << endl; }
};

class Pat {
public:
	Pat() { cout << "Pat()" << endl; }
	~Pat() { cout << "~Pat()" << endl; }
};

class Bingsoo {
public:
	Bingsoo() { 
		cout << "Bingsoo()" << endl; 
		ice = new Ice;
	}
	virtual ~Bingsoo() { // virtual���� �θ�Ҹ��� ~Bingsoo() ȣ��O, �ڽļҸ��� ~PatBingsoo()ȣ��X
		cout << "~Bingsoo()" << endl; 
		delete ice;
	}

private:
	//Ice ice;	// Ice() -> Bingsoo()
	
	Ice *ice; 
	// ��������� �����ͷ� ���ָ� Bingsoo()������ �ȿ��� �����Ҵ��� �Ͼ�� ������ 
	// Ice *ice; ������ ������� ���� -> Bingsoo()������ ȣ�� -> ������ �ȿ��� Ice��ü������ ���� Ice()������ ȣ��
};

class PatBingsoo : public Bingsoo {
public:
	PatBingsoo() { 
		cout << "PatBingsoo ()" << endl; 
		pat = new Pat[10];
	}
	~PatBingsoo() { 
		cout << "~PatBingsoo ()" << endl; 
		delete[] pat;
	}

private:
	Pat *pat;
};

int main() {
	//PatBingsoo *p = new PatBingsoo;
	
	Bingsoo *p = new PatBingsoo;
	// �������ε����� delete p;����� ~Bingsoo()�� ȣ��ȴ�. ~PatBingsoo()�� ȣ��Ǳ� �ٶ�� �Ҹ��ڸ� virtual�� ������ָ� �������ε��ȴ�
	// ����Ҹ��ڷ� ������ָ� delete p; �����Ͻ���ÿ� �Ҹ��ڰ� virtual���� Ȯ���ϰ� �Ǵ��� �̷�� �Ҹ��ڸ� �������ε��ϱ�� ����
	// ����������� p�� PatBingsoo��ü���� �˰� delete p;�� ~PatBingsoo()�� ȣ���Ѵ� (�����Լ�->�������ε��� ��������)

	// ��) ���α׷� �뷮�� Ŀ���� PatBingsoo������, �Ҹ��ڿ��� pat = new Pat[1000000]; �� ����µ� �Ҹ��ڰ� ȣ���� �ȵǾ� ������ �ȵǸ� ? �޸�ȿ�� ��

	delete p;
}