#define MAX_SIZE 100

// �ʱ�ȭ
int root[MAX_SIZE];
for (int i = 0; i < MAX_SIZE; i++)
{
	root[i] = i;
}

// find(x) by recursion
int find(int x)
{
	if (root[x] == x) {
		return x;
	}
	else {
		return find(root[x]);

		// ��ξ���
		//return root[x] = find(root[x]);
	}
}

// union(x,y)
void union(int x, int y)
{
	x = find(x);
	y = find(y);
	root[y] = x;
}

// https://www.geeksforgeeks.org/disjoint-set-data-structures/?ref=gcse