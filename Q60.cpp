// �ϳ��� �κ������� ����� �ڿ��� ���� ����� ������ �κ������� ���������.  
#include <stdio.h>
using namespace std;
int n, a[11], total=0;
bool flag=false;

void DFS(int L, int sum){
	// ����Լ����� return �ϸ� ��ͷ� ����Դ� �Լ����� Ÿ��Ÿ�� �ö����ʰ� ���� �� �ٷ� ���� 
	if(sum>(total/2)) return;	
	if(sum==(total-sum)){
		flag=true; //return;
	} 
	if(L==n+1){
		if(sum==(total-sum)){
			flag=true; return;
		}
	}
	else{
		DFS(L+1, sum+a[L]);
		DFS(L+1, sum);
	}
}
int main(){
//	freopen("input.txt", "rt", stdin);
	int i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
		total+=a[i];
	}
	DFS(1, 0);
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}
