/* Disjoint-set : ���μҰ����� ����: �ڷᱸ�� ������� : Tree
make-set(x) : x�� ������ ���ҷ� �ϴ� ���ο� ���� ����ϴ�.
union(x, y) : x�� ���� �°� y�� ���� ���� ��Ĩ�ϴ�.
ex) {1, 2} �� {2, 3} �� �����ϸ� ������{2}�� �����ϴ� {1, 2, 3} ����� ���� �� 
find(x) : x�� ���� ���� ��ǥ��(��Ʈ��� ��)�� ��ȯ�մϴ�.
 �л���ȣ�� ���� �����ϰ� ģ�������̸� Ʈ���� �������� ���� 
 1���� �迭�� ����� Ʈ���� ���� (�迭�� idx�� �� �л��� ��¡) �ʱ⼳�� : idx=�л���ȣ  
 unf �迭 : 1���л�=1������, 2���л�=2������...  
 unf[a]=b; �迭ĭ�ȿ� �ٸ��л���ȣ(idx��)�� �������� Ʈ������ */
 
#include <stdio.h>
using namespace std;
int unf[1001];	// �޸������̼��� ���� �迭
 
int Find(int v){ // Find() : v�� ���չ�ȣ�� ��ȯ�ϴ� �Լ� 
	if(v==unf[v]) return v;
//	else return Find(unf[v]); // 1 2 3 4 5 ������ �缱Ʈ������ 5�� ��Ʈ�� �ݺ���ȸ�� �����ؾ��ؼ� �ð� �����ɸ���. 
	else return unf[v] = Find(unf[v]);	// �޸������̼��� ���ؼ� Union&Find ��ξ��� (�ð��ξ�����) 
}
void Union(int a, int b){
	a = Find(a);
	b = Find(b);
	if(a!=b) unf[a]=b;
}
int main(){
//	freopen("input.txt", "rt", stdin);
	int i, n, m, a, b, fa, fb;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++)
		unf[i]=i;
	for(i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		Union(a, b);
	}
	scanf("%d %d", &a, &b);
	fa=Find(a);
	fb=Find(b);
	if(fa==fb) printf("YES\n");
	else printf("NO\n");
	return 0;
}
