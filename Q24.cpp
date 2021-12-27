#include <stdio.h>
#include <vector>
#include <algorithm>	// abs();
using namespace std; 
// �־����� ������ ������ ��쵵 ������ �� ����ؾ���  
int main(){
	int i, n, pre, now, pos;	scanf("%d", &n);
	vector<int> a(n);	
	scanf("%d", &pre);
	for(i = 1; i<n; i++){
		scanf("%d", &now);
		pos = abs(pre-now);
		if(0<pos && pos<n && a[pos]==0)
			a[pos]++;
		else{
			printf("NO\n");
			return 0;
		}
		pre = now;
	}
	printf("YES\n");
	return 0;
}

/* 
key : ���� ���
5
1 4 2 3 7 �� �ԷµǸ� 1 4, 4 2, 2 3, 3 7 �� ����������
pre=1�� ��� 1 4, 1 2, 1 3, 1 7 �� ���մϴ�

exit() �Լ� : stdlib.h, commit�� ���� ���η������� ���� �����
���� ���� �����԰� ���ÿ� ���μ��������Ͽ� �ü������ ���� �ѱ��.
exit(0) �������� EXIT_SUCCESS
exit(1) �����޽��� ���� EXIT_FAILURE 

return _; _�� �����ϰ� ���� ****/  

