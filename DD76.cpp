/*
텍스트, 이미지를 전송하는 메신저어플
여러 객체들의 중복되는 성질을 부모객체로 모아서 상속받아 사용하면 효율적이다.

텍스트 객체 : 보낸시간 보낸사람 텍스트내용
이미지 객체 : 보낸시간 보낸사람 사진파일
=> 보낸시간 보낸사람 을 부모객체로 , 텍스트 객체와 이미지 객체는 이를 상속받아 서로다른 내용만 추가해 사용
	효율적으로 관리할 수 있다. 뭔가 하나 변경되면 부모클래스에서 하나 바꿔주면 끝. 상속안하면 모든 클래스마다 뒤지면서 바꿔줘야함

부모클래스의 변수들은 protected로 설정해서 자식들이 접근할 수 있게 하기 보다는
그대로 private으로 설정해서 부모클래스 내에서 관리해주는 것이 낫다.
*/

#include <iostream>
#include <string>

using namespace std;

class Image {
public:
	operator string() {	// string으로 형변환하는 연산자를 오버로딩
		return "사진";
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
	TextMessage *hello = new TextMessage(10, "두들", "안녕");
	ImageMessage *dog = new ImageMessage(20, "두들", p_dogImage);

	cout << "보낸 시간 : " << hello->GetSendTime() << endl;
	cout << "보낸 사람 : " << hello->GetSendName() << endl;
	cout << "  내 용   : " << hello->GetText() << endl;
	cout << endl;

	cout << "보낸 시간 : " << dog->GetSendTime() << endl;
	cout << "보낸 사람 : " << dog->GetSendName() << endl;
	cout << "  내 용   : " << (string)*dog->GetImage() << endl;
	cout << endl;

	delete hello;
	delete dog;
	delete p_dogImage;

}