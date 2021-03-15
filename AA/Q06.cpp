#include <stdio.h>
//using namespace std;
int main() {
	//freopen("input.txt", "rt", stdin);
	char a[50];
	int i , res = 0, cnt = 0;
	scanf("%s", &a);
	for(i = 0; a[i] != '\0'; i++){
		if(48 <= a[i] && a[i] <= 57) {
			res = res * 10 +(a[i] - 48);
		}
	}
	printf("%d\n", res);
	for(i = 1; i <= res; i++){
		if(res% i == 0) cnt++;
	} 
	printf("%d\n", cnt);
	return 0;
}

