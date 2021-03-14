#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	char a[10];
	scanf("%s", &a);
	int c=0, h=0, i, idx=0;
	if(a[1] == 'H'){
		c=1;
		idx=1;
	}
	else{
		for(i=1; a[i] != 'H'; i++){
			c = c*10 + (a[i]-48);
			idx = i+1;
		}
	}
	
	if(a[idx+1] == '\0'){
		h=1;
	}else{
		for(i=idx+1; a[i] != '\0'; i++){
			h = h*10 + (a[i]-48);
		}
	}
	printf("%d\n", c*12+h);
	return 0;
}
