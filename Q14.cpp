#include <stdio.h>
int reverse(int x){
	int rnum = 0;
	while(x > 0){
		rnum = rnum*10 + (x%10); 
		x /= 10; 
	}
	return rnum;
}
bool isPrime(int x){
	int cnt = 0;
	bool flag = true;
	for(int i = 1; i<=x; i++)
		if(x%i == 0)
			cnt++;
	if(cnt != 2)
		flag = false;
	return flag;
	// return 값이 있는 함수는 꼭 타입을 반환해주는 코딩 하도록 ! 
}
int main(){
	int n, num;
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		scanf("%d", &num);
		if(isPrime(reverse(num)) == true)
			printf("%d ", reverse(num));
	}
	return 0;
}
