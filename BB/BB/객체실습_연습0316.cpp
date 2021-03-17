#include <iostream>
using namespace std;

int rect(int& a, int& b) {
	return a * b;
}
int main() {
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b;
	cout << "가로의 길이 : ";
	cin >> a;
	cout << "세로의 길이 : ";
	cin >> b;
	cout << "직사각형의 넓이 : " << rect(a, b) << endl;
	return 0;
}