#include <stdio.h>
#include <algorithm>
using namespace std;
char a[101], b[101];
// bool flag = true; 사용해서 판단해도 ok
int main(){
	scanf("%s\n%s", &a, &b);
	sort(a, a+sizeof(a));
	sort(b, b+sizeof(b));
	for(int i = 0; i< sizeof(a); i++){
		if(a[i] != b[i]){
			printf("NO"); exit(0);
		}
	}
	printf("YES");
	return 0;
}
