// over load 다중 정의

// 오른쪽부터 시작해서 default값을 주어야한다.
#include <iostream>
using namespace std;
int inventory[64] = {0};
int score = 0;
//void getItem(int itemId){
//	inventory[itemId]++;
//}
//void getItem(int itemId, int cnt){
//	inventory[itemId] += cnt;
//}

// 오버로딩을 위해 함수를 3개 만들필요 X
// 매개변수의 default값은 항상 오른쪽부터 시작해서 원하는곳까지 
void getItem(int itemId, int cnt=1, int sc=0){
	inventory[itemId] += cnt;
	score += sc;
}
int main(){
	getItem(6, 5);
	getItem(3, 2);
	getItem(3);
	getItem(11, 34, 7000);
	
	cout<<score<<endl;
	for(int i=0; i<16; i++)
		cout<<inventory[i]<<' ';
	cout<<endl;
}


