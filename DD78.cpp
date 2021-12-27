/*
�����Լ��� ���� ���ε�

������ : ���α׷��� ����� �ñ�
��Ÿ�� : ���α׷��� ����Ǵ� �ñ�
*/
#include <iostream>
using namespace std;

class Weapon {
public:
	Weapon(int power) : power(power) {
		cout << "Weapon(int)" << endl;
	}
	virtual void Use() {	// ���� �Լ� virtual : ������ (�Լ��� ȣ���� �ɼ��� �ȵɼ��� �ִٴ� ���� �����Ѵ�)
		cout << "Weapon::Use()" << endl;
	}
protected:
	int power;
};

class Sword : public Weapon {
public:
	Sword(int power) : Weapon(power) {
		cout << "Sword(int)" << endl;
	}
	void Use() { // �������̵�
		cout << "Sword::Use()" << endl;
		Swing();
	}
private:
	void Swing() {
		cout << "Swing sword." << endl;
	}
};

class Magic : public Weapon {
public:
	Magic(int power, int manaCost) : Weapon(power), manaCost(manaCost) {
		cout << "Magic(int, int)" << endl;
	}
	void Use() { // �������̵�
		cout << "Magic::Use()" << endl;
		Cast();
	}
private:
	void Cast() {
		cout << "Cast magic." << endl;
	}
	int manaCost;
};

int main() {
	Sword mySword(10);
	Magic myMagic(15, 7);

	mySword.Use();
	myMagic.Use();

	// �θ�Ŭ���� �Լ��� virtual Ű���� ���� �Ϲ� �Լ��̸�
	// ���� ���ε����� ���� currentWeapon�� Weapon��ü�������̱⿡ currentWeapon->Use(); �ÿ� ������ Weapon�� �Լ��� ����ȴ�.

	// �θ�Ŭ���� �Լ��� �Լ��� virtual Ű���尡 ���� �����Լ��̸� 
	// ���α׷��� ����� �������� �� �� �����ϱ� ���α׷��� ����Ǵ� �������� �����ϰ� �� ������ �̷��.
	// ���α׷� ����Ǵ� ������ ����
	// currentWeapon = &mySword; �� �θ�Ŭ���� �����Ϳ� Sword ��ü mySword�� �־��־��⿡ 
	// currentWeapon->Use(); �� ����Ǵ� ���������� �����Ͱ� � ��ü�� ����Ű���� ��Ȯ�� �� �� �ִ�.

	// virtual �Ⱥپ������� �����Ͱ� ���ü�� ����Ű���� �˱� ����� ������ �θ�ü ���� ȣ��		 => ���� ���ε�
	// virtual Ű���� �پ������� ȣ��� �Լ� ���ϴ� ��(Binding)�� ����Ǵ� ������ �����ϵ��� �̷��	 => ���� ���ε�

	// �� �� :
	// �θ�Ŭ������ �����Լ��� �ڽ�Ŭ�������� �������̵� �ϸ� ���� ���ε��� �Ͼ��. 
	// �θ�Ŭ������ �����͸� ���ؼ� �������̵��� �Լ��� ȣ���ϸ� �ڽ�Ŭ�������� �������̵��� �Լ��� ����ȴ�
	Weapon *currentWeapon;

	currentWeapon = &mySword;
	currentWeapon->Use();		// �����Ͻ��������� currentWeapon�� ������ ����Ű���� �˱� ���峪, ���α׷� ������������� ���� �� �� �ִ�
	currentWeapon = &myMagic;
	currentWeapon->Use();

}