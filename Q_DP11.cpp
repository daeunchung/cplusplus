/* 11. �ִ����� ���ϱ� (���� �˰���) 
9�� 10���� �ٸ�. �� ������ �Ѱ��� Ǯ �� �ִٴ� ���� ������ dy[][] �� 2�����迭�� ��ƾ��Ѵ�. 
dy[i][j] = dy[i-1][j-pt];	i:�������� j:���ѽð� ps:�������� pt:�����ð� 

�׷��� dy�� 2���� �迭�� ������ �������⵵�� ����ϴ�. 
 => 1�����迭 dy�� �ϴ¹��� ����. �ٷ� �ڿ��� ���� ��ȯ�ϴ� �� 
 �ʱⰪ 0���� �ʱ�ȭ, �ڿ������� dy[idx] idx=pt;�϶����� ����.  
 dy[idx] = dy[idx-pt]+ps; �̰��� �ڿ��� ���� ��ȸ�ϸ� ���� �����ϱ⿡ �ߺ��Ǵ� �� X 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, m, ps, pt;
	cin>>n>>m;
	vector<int> dy(m+1);
	for(int i=0; i<n; i++){
		cin>>ps>>pt;
		for(int j=m; j>=pt; j--){
			dy[j]=max(dy[j], dy[j-pt]+ps);
		}
	}
	cout<<dy[m];
	return 0;
}
