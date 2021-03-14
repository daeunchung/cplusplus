// DEV C++ 언어설정 : 도구->환경설정->언어 변경 

#include<bits/std++.h> 
/* C++ standard library에서 제공하는 모든 기능 vector, map, set, string, algorithm... 모두 사용가능
 컴파일러 설정 - 컴파일러 추가 명령 :  -std=c++14 컴파일러 업그레이드 해줘야 사용가능 (foreach구문 등등 사용가능)
 그러나 이거 쓰면 헤더가 무거워서 컴파일타임이 길다. header 하나하나 따로 쓰면 컴파일 타임 단축. 
 std++.h 헤더파일은 리눅스 계열일 GCC컴파일러에만 내장된 헤더파일입니다.
 window계열 컴파일러인 visual studio에서는 지원하지 않습니다. DEV-C++은 GCC컴파일러 사용
 
 백준처럼 채점사이트 원리
 코드 제출하면 해당 서버로 전송되어서 거기서 컴파일 + 실행되는데 
 시간측정은 컴파일시간 제외한 실행시간을 측정하는 거라 사용해도 괜찮습니다. 
 정보올림피아드 -> groom edu (여기는 compile time X, runtime 0) 
 불안하면 그냥 각자 헤더파일 땡겨와서 쓰세용 ~ 
*/
using namespace std;
int main(){
	// 동기화 해제 (C++표준stream만 독립적으로 사용하겠다-> 속도up)
	// 위 코드 작성하지 않으면 C표준buffer 와 C++표준buffer를 병행해서 사용하기에 속도느려진다.
	// cin.tie(NULL);  cin과cout의 buffer flush tie를 풀어놓기 (untie) 
	// acmicpc.net/blog/view/56   acmicpc.net/blog/view/56
	ios_base::sync_with_stdio(false); 	
	cin.tie(NULL);
}
