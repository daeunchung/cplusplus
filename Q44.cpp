#include <stdio.h>
#include <vector>
#include <algorithm> 
using namespace std;
int n;
int Count(int len, int *a){	// �Ű�����: ������ ������(�����˰���) �θ����� �ִ�Ÿ�, ���߰˻��ϴ� �迭 
	int i, cnt=1, pos=a[1];	// a[1]�������� �� �Ѹ��� �־ �ʱ� cnt=1; 
	for(i=2; i<=n; i++){
		if(a[i]-pos >= len){
			cnt++;
			pos=a[i];
		}
	}
	return cnt;
}
int main(){
//	freopen("input.txt", "rt", stdin);
	int m, i, lt=1, rt, mid, res;
	scanf("%d %d", &n, &m);

	int *a = new int[n+1]; // 0~n �� 
//	vector<int> a(n+1);
	for(i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	sort(a+1, a+n+1);	// vector�� �ƴ� �迭�� �����Ҷ� �������ִ� ������ ���� 
//	sort(a.begin(), a.end());

// ���� ����� �� ���� �ִ�Ÿ��� 1 ~ ���������� a[n] ���̿� ���� : ���⼭ �̺а˻� => ù rt�� a[n]���峡������ ����� �� 
	rt = a[n];
	while(lt<=rt){
		mid = (lt+rt)/2;
		if(Count(mid, a) >= m){
			res = mid;
			lt = mid+1;	
		}else
			rt = mid-1;
	}
	printf("%d\n", res);
	delete[] a;
	return 0;
}
