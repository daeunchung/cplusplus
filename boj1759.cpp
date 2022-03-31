/*
브루트포스 조합론 백트래킹 수학
c개 중에 l 개 골라(최소 한개의 모음과 두개의 자음 포함) 알파벳순으로 나열 모든 경우
1. 알파벳 순 정렬 2. 알파벳 하나씩 넣어보며 암호에 포함O, X를 따진다
cCl 라서 2^c 의 시간복잡도

e.g. l==4, c==6, 사용가능알파벳 atcisw 일때
a c i s t w
o o o o o o
x x x x x x

방법 1 자음, 모음 먼저 나눠 놓고 그 안에서 조건 만족하게 암호 만들기
방법 2 알파벳 l개인 암호 전부 만들고 나서 최소 자음1, 모음2 만족하는지 따져주기
두 방법 모두 time complexity O(2^c)

재귀로 풀이
go(n, alpha, password, i) 라는 재귀함수
n : 만들어야하는암호길이, alpha : 사용할수있는알파벳,
password : 현재까지만든암호, i : 사용할지말지결정해야하는알파벳의인덱스

정답을 찾은 경우 : 재귀 도중에 암호의 길이==l 일때
불가능한 경우(재귀를 이어나가도 답을 구할 수 없는 경우) : alphabet[idx] 의 idx 가 사용가능한알파벳개수 c보다 커질때
다음으로 넘어가는 경우 : alphabet[idx] 를 사용O 또는 사용X 하는 경우로 나누어 지기에
   i번째 알파벳 사용O : go(n, alpha, password + alpha[i], i+1)
   i번째 알파벳 사용X : go(n, alpha, password, i+1)

재귀함수 내부 구조
if() // 정답을 찾은경우에 수행
if() // 불가능한 경우에 수행
위에 두개if문에 걸러지지않았음즉, 다음재귀 수행
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int l, c;

bool check(string& pw)
{
	int jaeum = 0, moeum = 0;
	for (char ch : pw)
	{
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') moeum++;
		else jaeum++;
	}
	if (jaeum >= 2 && moeum >= 1) return true;
	else return false;
	// return jaeum >= 2 && moeum >= 1; 이렇게 표현할 수도 있다구!

}

void go(vector<char>& vec, string pw, int i)
{
	// 이 문제에서 재귀 설계는 if 문 순서 바꾸면 절대 안됨. 평소에는 무관, 여기서는 로직깨진다.
	// 마지막 알파벳을 사용하여 암호 완성되고 나서 if (i >= c) return; 와 재귀 검진이 필요하기 때문
	if (pw.size() == l) {
		if (check(pw)) cout << pw << '\n';
		return;
	}
	if (i >= c) return;
	go(vec, pw + vec[i], i + 1);
	go(vec, pw, i + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);

	cin >> l >> c;
	vector<char> v(c);
	for (int i = 0; i < c; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	go(v, "", 0);

	return 0;
}

/*
* Debug assertion Failed !
* Expression : vector subscription out of range 에러 
* 전역에 vector<char> v; 이따구로 벡터 만들어 놓고 함수 안에서 받으려고 했음
* 배열은 그렇게 전역에 크기 정해놓고 하고
* 벡터는 c값 받고 나서 main에서 vector<char> v(c) 로 선언하고
* 함수에서 v를 사용해야할 때에는 인자로 넘겨주자
*/