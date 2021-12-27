/*
 �ʹ� ũ�� ������ ������ �۰� ���� ���� ���ݾ� ũ�⸦ Ȯ���ؼ� �ذ��ϴ� ��
 ������ȹ�� Bottom-up ��� 
 ���������� ���� �� �ִ� ���� ���� �ظ� ���ϰ�  
 ���� �ظ� �̿��ؼ� ���� �ظ� ���ϰ� ...  
 ���� ��� ��ȭ�� f(n) = 2 * f(n-1)
 
 1. ������ȹ���̶�? ��Ʈ��ũ �� �ڸ��� (Bottom-Up)
 ios_base::sync_with_stdio(false); ����ȭ ���������� c++ǥ������� cio cout �� ����ؾ��Ѵ�
*/

#include<bits/stdc++.h>
using namespace std;
int dy[50];
int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n;
	cin>>n;
	dy[1]=1;
	dy[2]=2;
	for(int i = 3; i<=n; i++){
		dy[i] = dy[i-2] + dy[i-1];
	} 
	cout << dy[n];
	return 0;
}
