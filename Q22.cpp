#include <stdio.h>
#include <vector>
// �ð��ʰ������� ���� ����for�� �ȿ��� �ذ��ϱ� 
// (�ϳ��� ���� sum�� ������ŭ �����ְ� �尪��ŭ ���ֱ�, ��ĭ��ĭ ������ ����) 
int main(){
	int i, n, m, sum = 0, max = -200;
	scanf("%d %d", &n, &m);
	std::vector<int> t(n);	// std��� ��ü�� vector �迭�� ���� (�ʱⰪ�� �⺻0���� �Ǿ�����) 
	for(i = 0; i<n; i++){
		scanf("%d", &t[i]);
	} 
	for(i = 0; i<m; i++){
		sum += t[i];
	}
	max = sum;
	for(i = m; i<n; i++){
		sum = sum + t[i] - t[i-m];
		if(sum > max)
			max = sum;
	}
	printf("%d\n", max);
	return 0;
}
