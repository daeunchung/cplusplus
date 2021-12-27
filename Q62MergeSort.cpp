#include <stdio.h>       
using namespace std;
int data[101], tmp[101];
// https://www.youtube.com/watch?v=FCAtxryNgq4

// �����ϸ� �����ϴ� ����Լ� 
void divide(int lt, int rt){
	int mid;
	int p1, p2, p3;
	if(lt<rt){
		mid=(lt+rt)/2;
		divide(lt, mid);	// ������ 
		divide(mid+1, rt);	// ������ 
		// ��ġ�� (�ڽĴ� �������� ����) 
		// p1:�����ڽ� ���������� p2:�������ڽ� ���������� p3:tmp�迭������ 
		p1=lt;	 p2=mid+1;	p3=lt;
		while(p1<=mid && p2<=rt){
			// ���������̴� ���������� �־��ֱ� 
			if(data[p1]<data[p2]) tmp[p3++]=data[p1++];
			else tmp[p3++]=data[p2++];
		}
		while(p1<=mid) tmp[p3++]=data[p1++];
		while(p2<=rt) tmp[p3++]=data[p2++];
		// ------------ tmp�� ���ĿϷ�------- ���迭data�� �����ؾ���
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

// �������� : Merge Sort 
// �����Ͱ� n���� n�� �� , log����2 n �� ���� ����
// O(nlogn) 

