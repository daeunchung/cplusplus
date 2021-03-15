#include <iostream>       
#include <vector>
#include <algorithm>
using namespace std;
int main(){
//	freopen("input.txt", "rt", stdin);
	int i, j, r, c, a, b, max=-1, tmp;
	scanf("%d %d", &r, &c);
	vector<vector<int> > map(r+1, vector<int>(c+1, 0));
	vector<vector<int> > dy(r+1, vector<int>(c+1, 0));
	for(i=1; i<=r; i++){
		for(j=1; j<=c; j++){
			scanf("%d", &map[i][j]);
			dy[i][j] = dy[i-1][j]+dy[i][j-1]-dy[i-1][j-1]+map[i][j];
//			printf("%d  ", dy[i][j]);
		}
//		printf("\n");
	}
	scanf("%d %d", &a, &b);
	for(i=a; i<=r; i++){
		for(j=b; j<=c; j++){
			tmp=0;
			tmp = dy[i][j]-dy[i-a][j]-dy[i][j-b]+dy[i-a][j-b];
			if(tmp > max) max = tmp;
		}
	}
	printf("%d\n", max);
	return 0;
}
