// ����Ʈ�� ���̿켱Ž��(BFS) : Level Ž�� => �ڷᱸ�� Queue ���
// Stack �������� Queue ���Լ���

// BFS Queue ���� �����غ��� ���� front ������back 
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int Q[100], front=-1, back=-1, ch[10]; // ������׷��� üũ�� ���� ch�迭
vector<int> map[10];	// ��������Ʈ 
int main(){
	freopen("input.txt", "rt", stdin);
	// Ʈ���̱� ������ node n ����� ������ n-1 �� 
	int i, a, b, x;
	// ��������Ʈ ���� 
	for(i=1; i<=6; i++){
		scanf("%d %d", &a, &b);
		map[a].push_back(b);
		map[b].push_back(a);
	} 
	// ť � 
	Q[++back]=1;
	ch[1]=1;
	// ť�� ���� �ڷᰡ ���������� ��� ���� (front==back�̸� ��ť)
	// ť�� �ѹ� �� ���� �ִ� ���� ch�� 1�̴�. ť���� ���͵� 1�̴�.
	// ť���� ������ DFS ���Ž������ �ٽ� ch�� 0���� ����������, ť���� ������ �ٽ� ch 0���� �������� �ʴ´�.
	// �̰� ��� Ž���� �ƴϰ� �ܼ� BFS �̱� ������. ��� �ѹ� ������ �� ! 
	while(front<back){
		x=Q[++front];
		printf("%d ", x);	// ť���� ������(+���) for�� �ڽĳ�� Ž�� 
		for(i=0; i<map[x].size(); i++){
			// ť�� �������� �ڽĳ��鸸 ť�� �־��ش�. 
			if(ch[map[x][i]]==0){
				ch[map[x][i]]=1;
				Q[++back]=map[x][i];
			}
		}		
	} 
	return 0;
}
