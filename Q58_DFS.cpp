#include <iostream>       
#include <vector>
#include <algorithm>
using namespace std;

// ���� Ʈ�� ���� 
void D(int v){
	if(v>7) return;
	else{
		D(v*2);
		D(v*2+1);
		printf("%d ", v);	// ������ȸ 
	}
}
int main(){
//	freopen("input.txt", "rt", stdin);
	D(1); 
	return 0;
}

/*
����ϴ� �� printf("%d ", v); �� �Լ� �ڽ��� �ؾ��ϴ� �� �̶�� ǥ���ϸ�
void D(int v){
	if(v>7) return;
	else{
		printf("%d ", v);	// ������ȸ 
		D(v*2);
		printf("%d ", v);	// ������ȸ 
		D(v*2+1);
		printf("%d ", v);	// ������ȸ - ��������(�¿� �ڽĳ�� ���� ó���ϰ� �ڽ��� ���� �ϴ�) �� ���� �߿� 
	}
}
*/
 
