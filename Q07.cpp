#include <stdio.h>
int main() {
	//freopen("input.txt", "rt", stdin);
	char a[101], b[101];
	int i, cnt = 0; 
	gets(a);	// scanf�� �������ִ¹��ڿ��� ������������ �б⶧����
	for(i = 0; a[i] != '\0'; i++){
		if(a[i] == ' ') continue;
		if(97 <= a[i] && a[i] <= 122) b[cnt++] = a[i];
		else if (65 <= a[i] && a[i] <= 90) b[cnt++] = a[i] + 32;
	} 
	b[cnt] = '\0';
	printf("%s\n", b);
	return 0;
}
