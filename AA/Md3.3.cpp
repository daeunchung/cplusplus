// 문제1 문자열클래스를 완성해보세요 (난이도:중) 

class string {
  char *str;
  int len;

 public:
  string(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
  string(const char *s);
  string(const string &s);
  ~string();

  void add_string(const string &s);   // str 뒤에 s 를 붙인다.
  void copy_string(const string &s);  // str 에 s 를 복사한다.
  int strlen();                       // 문자열 길이 리턴
};

	bool operator<(const State &b)const{}
	1. 매개변수의 상수화(모든 함수) 
		입력받는 매개변수가 변하지 못하도록 고정. 
	
	2. 메서드의 상수화(멤버 메서드) 
		멤버 메서드 함수명 괄호닫고 바로 "뒤에" const .
		메서드 수행중에 멤버변수를 절대 바꾸지 못하도록. 바뀌면 컴파일에러 
		간혹가다 const int func(){} 이건 반환타입을 const int로 라는거고 메서드 상수화X 

