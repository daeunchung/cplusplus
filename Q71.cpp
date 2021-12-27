#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int ch[10001], d[3]={-1, 1, 5};
// ch[] : �Ÿ��迭 �� �湮����üũ�迭 
int main(){
//	freopen("input.txt", "rt", stdin);
	int s, e, x, i, pos;
	queue<int> Q;
	scanf("%d %d", &s, &e);
	ch[s]=1;	// ��������� 0�ƴ϶� 1�� �����ؼ�  
	Q.push(s);
	while(!Q.empty()){
		x=Q.front();
		Q.pop();
		for(i=0; i<3; i++){
			pos=x+d[i];
			if(pos<=0 || pos>10000) continue;
			if(pos==e){
				printf("%d\n", ch[x]);	// ���⼭ �ٷ� ���ܰ��� ch[x] ���
				exit(0);	// ���α׷� ���� 
			}
			if(ch[pos]==0){
				ch[pos]=ch[x]+1;
				Q.push(pos);
			} 
		}
	}
	return 0;
}
