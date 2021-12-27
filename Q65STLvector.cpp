// [잠깐지식] STL vector 생성방법
/*
ios::sync_with_stdio는 cpp의 iostream을 c의 stdio와 동기화시켜주는 역할
기본값인 true : cout << "HI"; printf("BYE"); cout<<"hi" 가 순서대로 출력
		 false: 어떤 순서로 출력될지 알 수가 없죠. 
그렇기 때문에 ios::sync_with_stdio(false); 를 추가하시면, 
iostream 함수인 cin/ cout을 stdio 함수인 getchar()와 혼용하면 안됌. 
*/
#include <iostream>       
#include <vector>
using namespace std;
int main(){
//	iso_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	vector<int> a;
	a.push_back(6); 
	a.push_back(8); 
	a.push_back(11);
	cout<<a.size()<<endl;
	cout<<a[1]<<endl;
	
	vector<int> c[3];
	c[0].push_back(1); 
	c[0].push_back(3); 
	c[0].push_back(5); 
	c[1].push_back(2); 
	c[1].push_back(4); 
	c[1].push_back(6); 
	c[2].push_back(7); 
	cout<<c[1][1]<<endl;
	cout<<c[2][0]<<endl;
	
	// 가중치인접리스트 로 사용가능  
	vector<pair<int, int> > g[3];	// graph[3];
	g[1].push_back({3, 5}); 
	g[1].push_back({4, 7}); 
	g[1].push_back({5, 9}); 
	g[2].push_back(make_pair(7, 7));
	cout<<g[2][0].first<<" "<<g[2][0].second<<endl;
	
	return 0;
}





