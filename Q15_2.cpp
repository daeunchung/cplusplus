#include <iostream>
#include <vector>
using namespace std;
int main(){
	//freopen("input.txt", "rt", stdin);
	int n, i, j, flag, cnt=0;
	cin>>n;
	for(int i=2; i<=n; i++){
		flag=1;
		for(j=2; j*j<=i; j++){
			if(i%j==0){
				flag=0;
				break;
			}
		}
		if(flag==1) cnt++;
	}	
	cout<<cnt;
	return 0;
}
/*
 O(N^(1/2)) 의 시간복잡도로 간단히 계산 가능 
 약수는 대칭을 이루기 때문. 그러므로 특정한 숫자의 제곱근까지만 약수의 여부를 검증하면된다. 
*/
