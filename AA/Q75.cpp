#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// 문제 풀이 : D값이 큰 순서로 M을 체크할것 
struct Data{
	int m, d;
	Data(int a, int b){
		m=a; d=b;
	}
	bool operator<(const Data &b)const{
		return d>b.d; 	// this.m>b.m;
	}
};
int main(){
//	freopen("input.txt", "rt", stdin);
	int n, i, j, a, b, res=0, max=-1;
	vector<Data> T;
	priority_queue<int> pQ;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d %d", &a, &b);
		T.push_back(Data(a, b));
		if(b>max) max=b; 
	}
	sort(T.begin(), T.end());	// 위에 operator에서 정의해준대로 정렬
	j=0;
	for(i=max; i>0; i--){
		// j가 멈춰있던 지점부터 다시돌도록  
		for( ; j<n; j++){
			if(T[j].d < i) break;
			pQ.push(T[j].m);
		}
		if(!pQ.empty()){
			res+=pQ.top();
			pQ.pop();
		}
	} 
	printf("%d\n", res);
	return 0;
}
