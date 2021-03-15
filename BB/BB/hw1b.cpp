/* B711169 정다은 3학년 */
#include <iostream>
#include "rectb.h"
using namespace std;

int main() {
	Rectangle r(2, 3, 6, 6), s(1, 2, 5, 9);
	cout << "<rectangle r> " << r;
	cout << "<rectangle s> " << s;
	if (r < s) cout << "s is bigger";
	else if (r==s) cout << "Same Size";
	else cout << "r is bigger";
}