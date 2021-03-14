#include <stdio.h>
using namespace std;
int main(){
//	freopen("input.txt", "rt", stdin);
	int i, cnt = 0;
	char a[40];
	scanf("%s", &a);
	for(i = 0; a[i] != '\0'; i++){
		if(a[i] == '(') cnt++;
		else if(a[i] == ')') cnt--;
		if(cnt < 0) break;
	}
	if(cnt == 0) printf("YES");
	else printf("NO");
	return 0;
}
