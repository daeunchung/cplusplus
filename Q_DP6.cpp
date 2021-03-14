// 6. 가장 높은 탑 쌓기  (LIS응용) 
// dy[i]: i번 탑이 가장 꼭대기에 놓았다고 가정했을때 탑의 높이 
#include<bits/stdc++.h>
using namespace std;
struct Brick{
	int s, h, w;
	Brick(int a, int b, int c){
		s=a, h=b, w=c;
	}
	bool operator<(const Brick &b)const{
		// 연산자 오버로딩 s에 의한 내림차순 (호출한객체 s > 매개변수객체 b.s) 
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
//				dy[i] = dy[j] + Bricks[j].h; 틀린코드
				max_h = dy[j]; 
			}
		}
		dy[i] = max_h + Bricks[i].h;
//		res = max(res, dy[i]); 매차례 최댓값을 갱신 
	}
	res = *max_element(dy.begin(), dy.end()); 	// 한번에 벡터에서 최댓값 추출 
	cout << res;
	return 0;
} 
