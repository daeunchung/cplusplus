/*
 2. ��Ʈ��ũ �� �ڸ��� (Top-Down : ���, �޸������̼�) 
 ������ �̸� ������ ���� '���'�ؼ� ���� ȣ�⿡�� ������ �������� Cut Edge
 �޸� �س��� ���ʿ��� ���ȣ���� ���� 
*/
#include<bits/stdc++.h>
using namespace std;
int dy[101];	// Edge cut �� ���� �޸������̼� table 
int DFS(int n){
	// �Ʒ� if���� ���� Edge cut ����. �����ָ� n��Ŀ���� runtime ��.��.�����ɸ� 
	if(dy[n]>0) return dy[n];
	
	if(n==1 || n==2) return n;
	else return dy[n] = DFS(n-1) + DFS(n-2);
}

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	cout << DFS(n);
	return 0;
}
