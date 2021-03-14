#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 지난번에 좌표 -> vector, pair 자료구조 
// 3개, 4개의 값이 한쌍을 이룰때 비교하며 정렬하는 법 (tuple도 사용가능) 
// => 구조체와 벡터를 사용한 자료정렬

struct Loc{
	int x, y, z;
	// 생성자:구조체의 이름과 똑같은 멤버함수 
	Loc(int a, int b, int c){
		x=a; y=b; z=c;
	}
	// 연산자 오버로딩 (두객체의  크기비교함수를 customize) 
	bool operator<(const Loc &b)const{
//		return x<b.x;	// 호출한객체 < 매개변수로받은객체  로 정렬(오름차순) 
		if(x!=b.x) return x<b.x; 
		if(y!=b.y) return y<b.y; 
		if(z!=b.z) return z<b.z; 
	}
};
int main(){
	vector<Loc> XY;
	XY.push_back(Loc(2, 3, 5));
	XY.push_back(Loc(3, 6, 7));
	XY.push_back(Loc(2, 3, 1));
	XY.push_back(Loc(5, 2, 3));
	XY.push_back(Loc(3, 1, 6));
	sort(XY.begin(), XY.end());
//	range-based for statement : C++98 에서 안돌아서 C++11로 바꿔줘야함 
//	for(auto pos : XY) cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<endl; 
	for(int i=0; i<XY.size(); i++)
		cout<<XY[i].x<<" "<<XY[i].y<<" "<<XY[i].z<<endl;
	return 0;
}
