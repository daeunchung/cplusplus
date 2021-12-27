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

/* 초보자용 재귀함수 틀
void recur(int x){
	if(x==0) return;
	else{
		printf("%d ", x);
	 	recur(x-1);
	}
}// printf 를 재귀함수보다 먼저 실행하면 3 2 1 출력

void recur(int x){
	if(x==0) return;
	else{
	 	recur(x-1);
		printf("%d ", x);
	}
}
// printf 를 재귀함수보다 나중에 실행하면 
// 재귀함수 다 돌고 stack에서 나올 때 1 2 3 출력 */
