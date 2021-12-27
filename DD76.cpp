/*
�ؽ�Ʈ, �̹����� �����ϴ� �޽�������
���� ��ü���� �ߺ��Ǵ� ������ �θ�ü�� ��Ƽ� ��ӹ޾� ����ϸ� ȿ�����̴�.

�ؽ�Ʈ ��ü : �����ð� ������� �ؽ�Ʈ����
�̹��� ��ü : �����ð� ������� ��������
=> �����ð� ������� �� �θ�ü�� , �ؽ�Ʈ ��ü�� �̹��� ��ü�� �̸� ��ӹ޾� ���δٸ� ���븸 �߰��� ���
	ȿ�������� ������ �� �ִ�. ���� �ϳ� ����Ǹ� �θ�Ŭ�������� �ϳ� �ٲ��ָ� ��. ��Ӿ��ϸ� ��� Ŭ�������� �����鼭 �ٲ������

�θ�Ŭ������ �������� protected�� �����ؼ� �ڽĵ��� ������ �� �ְ� �ϱ� ���ٴ�
�״�� private���� �����ؼ� �θ�Ŭ���� ������ �������ִ� ���� ����.
*/

#include <iostream>
#include <string>

using namespace std;

class Image {
public:
	operator string() {	// string���� ����ȯ�ϴ� �����ڸ� �����ε�
		return "����";
	}
};

class Message {
public:
	Message(int sendTime, string sendName) {
		this->sendTime = sendTime;
		this->sendName = sendName;
	}
	int GetSendTime() const { return sendTime; }
	string GetSendName() const { return sendName; }
private:
	int sendTime;
	string sendName;
};

class TextMessage : public Message {
public:
	TextMessage(int sendTime, string sendName, string text)
		: Message(sendTime, sendName) {
		this->text = text;
	}
	string GetText() const { return text; }
private:
	string text;
};

class ImageMessage : public Message {
public:
	ImageMessage(int sendTime, string sendName, Image *image)
		: Message(sendTime, sendName) {
		this->image = image;
	}
	Image *GetImage() const { return image; }
private:
	Image *image;
};

int main() {
	Image *p_dogImage = new Image();
	TextMessage *hello = new TextMessage(10, "�ε�", "�ȳ�");
	ImageMessage *dog = new ImageMessage(20, "�ε�", p_dogImage);

	cout << "���� �ð� : " << hello->GetSendTime() << endl;
	cout << "���� ��� : " << hello->GetSendName() << endl;
	cout << "  �� ��   : " << hello->GetText() << endl;
	cout << endl;

	cout << "���� �ð� : " << dog->GetSendTime() << endl;
	cout << "���� ��� : " << dog->GetSendName() << endl;
	cout << "  �� ��   : " << (string)*dog->GetImage() << endl;
	cout << endl;

	delete hello;
	delete dog;
	delete p_dogImage;

}