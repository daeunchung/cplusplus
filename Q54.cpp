#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;
// ���� ��ȣ push  
int main(){
//	freopen("input.txt", "rt", stdin);
	stack<char> s;
	char a[50];
	int i, flag=1;	// *** �߿� : flag �� ()) ó�� ��ȣ�� �������Ῡ��üũ 
	scanf("%s", &a);
	for(i=0; a[i]!='\0'; i++){
		if(a[i] == '(') s.push(a[i]);
		else{
			if(s.empty()){
				printf("NO\n");
				flag = 0;
				break;
			}
			s.pop();
		}
	}
	if(flag == 1){
		if(s.empty()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
