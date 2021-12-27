// 6. ���� ���� ž �ױ�  (LIS����) 
// dy[i]: i�� ž�� ���� ����⿡ ���Ҵٰ� ���������� ž�� ���� 
#include<bits/stdc++.h>
using namespace std;
struct Brick{
	int s, h, w;
	Brick(int a, int b, int c){
		s=a, h=b, w=c;
	}
	bool operator<(const Brick &b)const{
		// ������ �����ε� s�� ���� �������� (ȣ���Ѱ�ü s > �Ű�������ü b.s) 
		return s>b.s;
	}
};
int main(){
	ios_base::sync_with_stdio(false);
//	freopen("input.txt", "rt", stdin);
	int n, a, b, c, max_h=0, res=0;
	cin>>n;
	vector<Brick> Bricks;
	vector<int> dy(n, 0);
	for(int i=0; i<n; i++){
		cin>>a>>b>>c;
		Bricks.push_back(Brick(a, b, c));
	}
	sort(Bricks.begin(), Bricks.end());
	dy[0] = Bricks[0].h;
	res = dy[0];
	// Dynamic Programming //
	for(int i=1; i<n; i++){
		max_h=0;
		for(int j=i-1; j>=0; j--){
			if(Bricks[j].w > Bricks[i].w && dy[j]>max_h){
//				dy[i] = dy[j] + Bricks[j].h; Ʋ���ڵ�
				max_h = dy[j]; 
			}
		}
		dy[i] = max_h + Bricks[i].h;
//		res = max(res, dy[i]); ������ �ִ��� ���� 
	}
	res = *max_element(dy.begin(), dy.end()); 	// �ѹ��� ���Ϳ��� �ִ� ���� 
	cout << res;
	return 0;
} 
