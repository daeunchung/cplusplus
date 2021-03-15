#include <iostream>
using namespace std;
int main() {
	int  x, y, w, h;
	cin >> x >> y >> w >> h;
	int min = 1000;
	if (x < y) min = x;
	else min = y;
	if (w - x < min) min = w - x;
	if (h - y < min) min = h - y;
	cout << min;
	return 0;
}