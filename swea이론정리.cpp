/*
* �ݺ��� �����˻� 
* binarySearch(a[], key)
*	start = 0, end = length(a)-1;
*	while(start <= end){
*		mid = start + (end-start)/2;
*		if(a[mid] == key) return true;
*		else if(a[mid] > key) end = mid-1;
*		else start = mid + 1;
*	}
*	return false;
* end binarySearch();
*/

/*
* ����Լ��̿� �����˻�
* binarySearch(a[], low, high, key)
*	mid = (low + high) / 2;
*	if(key == a[mid]) return true;
*	else if(key < a[mid]) binarySearch(a[], low, mid-1, key); // �Ʒ��� �������� �̵�
*	else if(key > a[mid]) binarySearch(a[], mid+1, high, key); // ���� �������� �̵�
*	else return false;
* end binarySearch();
*/

/*
* �������� ���������ÿ�
* �ּҰ� ã�Ƽ� ����տ� ���� ��ȯ�ؼ� ���� �տ� ¯�ھƵ�.
* ��� ã�� 1��° �ּ� ���� �����ϰ� 2~n ��° ���� �� �ּҰ� ã�Ƽ� 2�� �ڸ��� ��ȯ
* �ǽð����� ���� ���� ���� ������ ¯�ھƵδ� ����
*/


/*
* Stack 2
* ����ǥ���(�Ϲݼ���)�� stack �� �̿��Ͽ� �ı�ǥ���(�����ڸ� �ǿ����� �ڿ� ǥ��, ��ǻ�� ����)���� �����Ѵ�
* �����ڸ� stack �� �־ ����->������ ����
* 
* ����ǥ������� ǥ���� ������ ����Ҷ���
* �ǿ����ڸ� stack �� �־ ������ ���� ���
* 
* 
* ��Ʈ��ŷ ���
* �ظ� ã�� ���߿� ������(�ذ� �ƴϸ�), �ǵ��ư��� �ٽ� �ظ� ã�ư��� ��� : ����ȭ ����, ���� ���� �ذῡ ���
* ������ ������ �����ϴ� �ذ� �����ϴ����� ���θ� yes �Ǵ� no �� ���ϴ� ���� 
* E.g. �̷�ã��, NQueen, Map coloring, �κ������� ��(Subset Sum) ��
*  
* Power Set : � ������ �����հ� �ڱ��ڽ��� ������ ��� �κ����� (2�� n����)
* ��Ʈ��ŷ ������� Power Set(���κ�����) ���ϱ� : 1 �Ǵ� 0 �� ������ �׸��� ������ n���� �迭�� ����� ��� �̿�
* 1 �̸� �ش� ���Ұ� �κ����տ� ���Եǰ� , 0 �̸� ���Ե��� �ʴ´�.
* ���ϴ� �信 ���������� ����� ���, �信 ���� �������� ��� ȣ��
* 
* ��Ʈ��ŷ vs DFS
* ��Ʈ��ŷ�� �߰��� ���� �ƴ� �ڽĳ���� Ž���� �ߴ� . ��� ������ �θ� Ÿ�� �ö󰡼� �ٸ� �ڽ� Ž�� 
* DFS �� �߰��� ���̵� �ƴϵ� ������� ��� �ڽ� ��带 Ž�� 
* 
* 
*/

//Power Set�� ���ϴ� ��Ʈ��ŷ �˰���
//void backtrack(int a[], int k, int input)
//{
//	int c[MAXCANDIDATES] = { 0, };
//	int ncandidates = 0;
//	int i = 0;
//
//	if (k == input)
//	{
//		printf("(");
//		for (int i = 0; i <= k; i++)
//			if (a[i] == 1)
//				printf(" %d", i);
//		printf(")\n");
//	}
//	else
//	{
//		k++;
//		construct_candidates(a, k, input, c, &ncandidates);
//		for (i = 0; i < ncandidates; i++)
//		{
//			a[k] = c[i];
//			backtrack(a, k, input);
//		}
//	}
//}
//
//������ ���ϴ� ��Ʈ��ŷ �˰���
