/* �����佺�׳׽��� ü : �Ҽ�(Prime Number) �Ǻ� �˰���

 �뷮�� �Ҽ��� �Ѳ����� �Ǻ��ϰ��� �� �� ����Ѵ�.  
���� �Ҽ��� �Ǻ��� ������ŭ �迭�� �Ҵ��� �� ���ؽ��� �ش��ϴ� ���� �־��ְ� �Ѱ��� ���������� �Ǻ�
 �迭�� ���� i�� ������� �����. �̶� i �ڱ��ڽ��� ������������, �̹� ������������ �ǳʶ� 
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, a[200001];
	cin>>n;
	for(int i=2; i<=n; i++) a[i]=i;
	for(int i=2; i<=n; i++){
		if(a[i]==0) continue;
		for(int j=i+i; j<=n; j+=i) a[j]=0;
	}
	for(int i=2; i<=n; i++){
		if(a[i] != 0) cout<<a[i]<<" ";
	}
	return 0;
}
