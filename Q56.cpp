#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

void iter(int num){
		if(num>1)
			iter(num-1);
		printf("%d ", num);
}
int main(){
//	freopen("input.txt", "rt", stdin);
	int n, i;
	scanf("%d", &n);
	iter(n);
	return 0;
}

/* �ʺ��ڿ� ����Լ� Ʋ
void recur(int x){
	if(x==0) return;
	else{
		printf("%d ", x);
	 	recur(x-1);
	}
}// printf �� ����Լ����� ���� �����ϸ� 3 2 1 ���

void recur(int x){
	if(x==0) return;
	else{
	 	recur(x-1);
		printf("%d ", x);
	}
}
// printf �� ����Լ����� ���߿� �����ϸ� 
// ����Լ� �� ���� stack���� ���� �� 1 2 3 ��� */
