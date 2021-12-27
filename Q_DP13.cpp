/* 13. ȸ��̱� (�÷��̵�-�ͼ� ����) 
 ����ġ���� ��� 1�� �����Ⱑ��ġ �׷������� �ִܰŸ� ����Ѵٰ� �����ϸ� ��
 dis[][] �迭���� dis[i][] �����߿� �ִ���  i�� ȸ���� ȸ�������̴�.
 dis�迭�� �ϼ��Ҷ� ��� �������� ��� ���������� �ִܰŸ� ���ؼ� ä���. 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, a, b;
	cin>>n;
	vector<vector<int> > dis(n+1, vector<int>(n+1, 100));
	vector<int> res(n+1);
	for(int i=1; i<=n; i++) dis[i][i]=0;
	while(true){
		cin>>a>>b;
		if(a==-1 && b==-1) break;
		dis[a][b]=1;
		dis[b][a]=1;
	}
//	while(a!=-1 && b!=-1){
//		cin>>a>>b;
//		dis[a][b]=1;
//		dis[b][a]=1;
//	} �̰� �� �ȵɱ� ? 
	// �÷��̵�-�ͼ� // for(int k�� 1~n ����){ ����for�� } => ����for�� 
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
			}
		}
	}
	///////////////////////////////////////////////////////////////////
	int score=100;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i==j) continue;
			res[i]=max(res[i], dis[i][j]);			
		}
		score=min(score, res[i]);
	}
	
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(res[i]==score) cnt++;
	}
	cout<<score<<" "<<cnt<<endl;
	for(int i=1; i<=n; i++){
		if(res[i]==score) cout<<i<<" ";
	}
	return 0;
} 
