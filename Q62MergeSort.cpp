#include <stdio.h>       
using namespace std;
int data[101], tmp[101];
// https://www.youtube.com/watch?v=FCAtxryNgq4

// 분할하며 정복하는 재귀함수 
void divide(int lt, int rt){
	int mid;
	int p1, p2, p3;
	if(lt<rt){
		mid=(lt+rt)/2;
		divide(lt, mid);	// 나누고 
		divide(mid+1, rt);	// 나누고 
		// 합치고 (자식다 나눠놓고 나서) 
		// p1:왼쪽자식 진행포인터 p2:오른쪽자식 진행포인터 p3:tmp배열포인터 
		p1=lt;	 p2=mid+1;	p3=lt;
		while(p1<=mid && p2<=rt){
			// 오름차순이니 작은수먼저 넣어주기 
			if(data[p1]<data[p2]) tmp[p3++]=data[p1++];
			else tmp[p3++]=data[p2++];
		}
		while(p1<=mid) tmp[p3++]=data[p1++];
		while(p2<=rt) tmp[p3++]=data[p2++];
		// ------------ tmp로 정렬완료------- 원배열data로 복사해야함
		for(int i=lt; i<=rt; i++)
			data[i]=tmp[i]; 
	}
}

int main(){
//	freopen("input.txt", "rt", stdin);
	int n,i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &data[i]);
	}
	divide(1, n);	// divide(lt, rt); 
	for(i=1; i<=n; i++){
		printf("%d ", data[i]);
	} 
	return 0;
}

// 병합정렬 : Merge Sort 
// 데이터가 n개면 n번 비교 , log작은2 n 개 레벨 생성
// O(nlogn) 

