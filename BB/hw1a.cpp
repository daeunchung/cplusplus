/* B711169 정다은 3학년 */

#include <iostream>
#include "recta.h"
using namespace std;
int main() {
	Rectangle r(2, 3, 6, 6), s(1, 2, 5, 9);
	cout << "<rectangle r> "; r.Print();
	cout << "<rectangle s> "; s.Print();
	if (r.SmallerThan(s)) cout << "s is bigger" << '\n';
	else if (r.EqualTo(s)) cout << "Same Size" << '\n';
	else cout << "r is bigger" << '\n';
}