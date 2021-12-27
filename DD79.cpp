/*
상속이 필요한 이유(2) 이게 진짜 중요함
*/
#include <iostream>
#include <string>

using namespace std;

class Image {
public:
	operator string() {
		return "사진";
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
	// (Message *m), (const Message &m) 둘 중 어떤걸로 받던지 둘다 동적 바인딩 일어난다
	// 레퍼런스변수든 포인터든 둘다 객체그자체를 넘겨주는 것이 아니기 때문에 동적 바인딩이 가능하다  
	
	// (const Message m) 객체 자체로 넘겨서 받아주게 되면 그과정에서 객체가 복사되어 객체타입이 Message가 된다
	// 부모클래스 Message 에서 GetContent() 는 공백출력하니 아무것도 출력되지 않는다.
	cout << "보낸 시간 : " << m.GetSendTime() << endl;
	cout << "보낸 사람 : " << m.GetSendName() << endl;
	cout << "  내 용   : " << m.GetContent() << endl;
	cout << endl;
}
int main() {
	Image *p_dogImage = new Image();

	Message *messages[] = {
		new TextMessage(10, "두들", "안녕"),
		new TextMessage(11, "두들", "안녕"),
		new TextMessage(12, "두들", "안녕"),
		new ImageMessage(20, "두들", p_dogImage)
	};

	// 각 객체에 맞는 포인터를 각각 만들지 않고 위처럼 부모클래스 포인터배열을 만들어서 객체를 생성하고 주소값을 넣어줌
	//TextMessage *hello = new TextMessage(10, "두들", "안녕");
	//ImageMessage *dog = new ImageMessage(20, "두들", p_dogImage);
	//printMessage(*hello);
	//printMessage(*dog);
	
	// 범위 기반 for문
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