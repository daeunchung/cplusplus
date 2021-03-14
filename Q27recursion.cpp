#include <iostream>
#include <vector>
using namespace std;
//int fac(int n){
//	if(n==1) return 1;
//	else return n*fac(n-1);
//} 
//int main(){
//	int n;
//	cin>>n;
//	cout<<fac(n);
//	return 0;
//}

int func(vector<int> &v, int n){
	int tmp=n;
	if(n>1){
		func(v, n-1);
		//then divide n
		int i=2;
		while((i<=tmp)&&(tmp>1)){
			if(tmp%i==0){
				v[i]++;
				tmp=tmp/i;
			}else{
				i+=1;
			}
		}
	}
	return 0;
}

int main(){
	//freopen("input.txt","rt", stdin);
	int n, i;
	scanf("%d",&n);
	vector<int> v(n+1);
	func(v, n);
	printf("%d! = ",n);
	for(i=2; i<=n; i++){
		if(v[i]!=0) printf("%d ", v[i]);
	}
	return 0;
}

