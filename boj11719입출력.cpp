#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	while (getline(cin, str))
	{
		cout << str << '\n';
	}
	return 0;
}

/*
* 다른 고수분들 코드
#include<cstdio>
char a;
int main() {
	while ((a = getchar()) && a != EOF) {
		printf("%c", a);
	}
}

#include <cstdio>
#include <cstring>
int main() {
	char str[110];
	while (gets(str)>0) printf("%s\n",str);
}

#include <stdio.h>
int main()
{
	char a[1000];

	while(gets(a)!=NULL)
	{
		printf("%s\n",a);
	}
	return 0;
}

#include <stdio.h>

int main(){
	char x;

	while((scanf("%c",&x))!=EOF)
	printf("%c",x);

	return 0;
}

#include<stdio.h>

int main(void){
	char s[101];
	while(fgets(s,101,stdin)){
		printf("%s",s);
	}
}

*/