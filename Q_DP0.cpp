// DEV C++ ���� : ����->ȯ�漳��->��� ���� 

#include<bits/std++.h> 
/* C++ standard library���� �����ϴ� ��� ��� vector, map, set, string, algorithm... ��� ��밡��
 �����Ϸ� ���� - �����Ϸ� �߰� ��� :  -std=c++14 �����Ϸ� ���׷��̵� ����� ��밡�� (foreach���� ��� ��밡��)
 �׷��� �̰� ���� ����� ���ſ��� ������Ÿ���� ���. header �ϳ��ϳ� ���� ���� ������ Ÿ�� ����. 
 std++.h ��������� ������ �迭�� GCC�����Ϸ����� ����� ��������Դϴ�.
 window�迭 �����Ϸ��� visual studio������ �������� �ʽ��ϴ�. DEV-C++�� GCC�����Ϸ� ���
 
 ����ó�� ä������Ʈ ����
 �ڵ� �����ϸ� �ش� ������ ���۵Ǿ �ű⼭ ������ + ����Ǵµ� 
 �ð������� �����Ͻð� ������ ����ð��� �����ϴ� �Ŷ� ����ص� �������ϴ�. 
 �����ø��ǾƵ� -> groom edu (����� compile time X, runtime 0) 
 �Ҿ��ϸ� �׳� ���� ������� ���ܿͼ� ������ ~ 
*/
using namespace std;
int main(){
	// ����ȭ ���� (C++ǥ��stream�� ���������� ����ϰڴ�-> �ӵ�up)
	// �� �ڵ� �ۼ����� ������ Cǥ��buffer �� C++ǥ��buffer�� �����ؼ� ����ϱ⿡ �ӵ���������.
	// cin.tie(NULL);  cin��cout�� buffer flush tie�� Ǯ����� (untie) 
	// acmicpc.net/blog/view/56   acmicpc.net/blog/view/56
	ios_base::sync_with_stdio(false); 	
	cin.tie(NULL);
}
