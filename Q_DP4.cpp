/*
 �ִ�κ���������
 1�����迭 -> python 1���� ����Ʈ 

 Ǯ�� : arr[i]�� ������ ������ ���� ���������� �����غ���. 

 dy[i] �� �ǹ� : arr[i]�� ���� ��������ϴ� �κ�����������  
 ������ ���� ���� ��������� ������ �߿� ���� �� ������ ���� 
 
 ���������� dy[i]�� �ִ��� ������ ��� 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, res=0;
	cin>>n;
	vector<int> arr(n+1), dy(n+1);	// 0���� �ʱ�ȭ
	for(int i = 1; i<=n; i++)
		cin>>arr[i];
	// �ִ�κ����������� dynamic 2��for�� 
	dy[1]=1;	// DP Bottom-Up
	for(int i = 2; i<=n; i++){	
		int max = 0;
		for(int j = 1; j<i; j++){	// for(int j=i-1; j>=1; j--)
			if(arr[j]<arr[i] && dy[j]>max){
				max=dy[j];
			}
		}
		dy[i] = max+1;
		if(dy[i]>res) res=dy[i];
	}
	cout<<res;
	return 0;
}

