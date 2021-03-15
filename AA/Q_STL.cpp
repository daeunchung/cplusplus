// [잠깐지식] STL map 자료구조 활용
//#include "pch.h"
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int main(){
	// cin, cout이 scanf, printf 만큼 속도 내기 위해 동기화 해제.그대신 cin scanf 동시사용 불가능 
	ios_base::sync_with_stdio(false);
	ifstream cin;
	cin.open("input.txt");
	
/*
map 자료구조 : 
<key, value> key를 index라고 간주
균형잡힌 이진트리 red-black tree 
map은 vector 처럼 int i로 접근 불가능. it를 사용한다. 
iterator : map에 접근하기 위한 반복자.(포인터로 간주)
ch.end(); 는 마지막 자료를 가리키지않고 마지막 자료의 뒷칸을 가리킨다. 
*/
	map<char, int> ch;	 
	map<char, int>::iterator it;
	char a[100];	
	cin >> a;
	for(int i = 0; a[i]!='\0'; i++){
		// 입력받은 데이터를 ch안으로 카운팅
		ch[a[i]]++; 
	}
	for(it = ch.begin(); it != ch.end(); it++){
		cout << it->first << " " << it->second << "\n";
	}
	return 0;
}
 
