#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
//	freopen("input.txt", "rt", stdin);
	int i, j, k, l, r, c, a, b, max=-1, sum;
	scanf("%d %d", &r, &c);
	vector<vector<int> > map(r+1, vector<int>(c+1, 0));
	for(i=1; i<=r; i++){
		for(j=1; j<=c; j++){
			scanf("%d", &map[i][j]);
		}
	}
	scanf("%d %d", &a, &b);

	for(i=1; i<=r-a+1; i++){
		for(j=1; j<=c-b+1; j++){
			sum=0;
			for(k=0; k<a; k++){
				for(l=0; l<b; l++){
					sum += map[i+k][j+l];
				}
			}
			if(sum > max) max = sum;
		}
	}
	printf("%d\n", max);
	return 0;
}
