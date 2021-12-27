// 68 �� ������ ���� 
// DFS : ����ġ ����׷��� �������
#include <stdio.h>
using namespace std;
int map[30][30], ch[30], n, cost=2147000000;	// cost ������ min���� �ϸ� �������� ���� �Ʒ��� !!! 

void DFS(int v, int sum){
	int i;
	if(v==n) {
		if(cost>sum) cost=sum;	
	}
	else{
		for(i=1; i<=n; i++){
			if(map[v][i]>0 && ch[i]==0){
				ch[i]=1;
				DFS(i, sum+map[v][i]);
				ch[i]=0;
			}
		}
	}
}

int main(){
//	freopen("input.txt", "rt", stdin);
	int i, m, a, b, c;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a][b]=c;
	}
	ch[1]=1;
	DFS(1, 0);
	printf("%d\n", cost);
	return 0;
}

// [Error] reference to 'min' is ambiguous ([�� ��] ���� ���� 'min' ��ȣ�մϴ�) 
// -> namespace std �ȿ� C++ �Լ��� max �Լ��� �����ϱ� ����
// int max ��� int maxx �̷������� ������ �����ϸ� �ȴ�.  min�� �������� minn �Ǵ� �ּҺ���̴� cost�� ������ ���� 

// �׷��� DFS ������ ���� �̷��� Ǫ�� �� ��
// 1->N ���� ���� ������ ���ͽ�Ʈ�� �˰���  ã.��.��.��.�� !! 
