#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// �������� ��ǥ -> vector, pair �ڷᱸ�� 
// 3��, 4���� ���� �ѽ��� �̷궧 ���ϸ� �����ϴ� �� (tuple�� ��밡��) 
// => ����ü�� ���͸� ����� �ڷ�����

struct Loc{
	int x, y, z;
	// ������:����ü�� �̸��� �Ȱ��� ����Լ� 
	Loc(int a, int b, int c){
		x=a; y=b; z=c;
	}
	// ������ �����ε� (�ΰ�ü��  ũ����Լ��� customize) 
	bool operator<(const Loc &b)const{
//		return x<b.x;	// ȣ���Ѱ�ü < �Ű������ι�����ü  �� ����(��������) 
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
//	range-based for statement : C++98 ���� �ȵ��Ƽ� C++11�� �ٲ������ 
//	for(auto pos : XY) cout<<pos.x<<" "<<pos.y<<" "<<pos.z<<endl; 
	for(int i=0; i<XY.size(); i++)
		cout<<XY[i].x<<" "<<XY[i].y<<" "<<XY[i].z<<endl;
	return 0;
}
