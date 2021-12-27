/*
����� �ʿ��� ����(2) �̰� ��¥ �߿���
*/
#include <iostream>
#include <string>

using namespace std;

class Image {
public:
	operator string() {
		return "����";
	}
};

class Message {
public:
	Message(int sendTime, string sendName)
		: sendTime(sendTime), sendName(sendName) {}

	int GetSendTime() const { return sendTime; }
	string GetSendName() const { return sendName; }
	virtual string GetContent() const { return ""; }

private:
	int sendTime;
	string sendName;
};

class TextMessage : public Message {
public:
	TextMessage(int sendTime, string sendName, string text)
		: Message(sendTime, sendName), text(text) {}

	string GetText() const { return text; }
	string GetContent() const { return text; }
private:
	string text;
};

class ImageMessage : public Message {
public:
	ImageMessage(int sendTime, string sendName, Image *image)
		: Message(sendTime, sendName), p_image(image) {}

	Image *GetImage() const { return p_image; }
	string GetContent() const { return (string)*p_image; }
private:
	Image *p_image;
};

void printMessage(const Message &m) { 
	// (Message *m), (const Message &m) �� �� ��ɷ� �޴��� �Ѵ� ���� ���ε� �Ͼ��
	// ���۷��������� �����͵� �Ѵ� ��ü����ü�� �Ѱ��ִ� ���� �ƴϱ� ������ ���� ���ε��� �����ϴ�  
	
	// (const Message m) ��ü ��ü�� �Ѱܼ� �޾��ְ� �Ǹ� �װ������� ��ü�� ����Ǿ� ��üŸ���� Message�� �ȴ�
	// �θ�Ŭ���� Message ���� GetContent() �� ��������ϴ� �ƹ��͵� ��µ��� �ʴ´�.
	cout << "���� �ð� : " << m.GetSendTime() << endl;
	cout << "���� ��� : " << m.GetSendName() << endl;
	cout << "  �� ��   : " << m.GetContent() << endl;
	cout << endl;
}
int main() {
	Image *p_dogImage = new Image();

	Message *messages[] = {
		new TextMessage(10, "�ε�", "�ȳ�"),
		new TextMessage(11, "�ε�", "�ȳ�"),
		new TextMessage(12, "�ε�", "�ȳ�"),
		new ImageMessage(20, "�ε�", p_dogImage)
	};

	// �� ��ü�� �´� �����͸� ���� ������ �ʰ� ��ó�� �θ�Ŭ���� �����͹迭�� ���� ��ü�� �����ϰ� �ּҰ��� �־���
	//TextMessage *hello = new TextMessage(10, "�ε�", "�ȳ�");
	//ImageMessage *dog = new ImageMessage(20, "�ε�", p_dogImage);
	//printMessage(*hello);
	//printMessage(*dog);
	
	// ���� ��� for��
	for (Message *m : messages) {
		printMessage(*m);
	}

	/*
	for (int i = 0; i < 4; i++) {
		printMessage(*messages[i]);
	}
	*/
	delete p_dogImage;
}