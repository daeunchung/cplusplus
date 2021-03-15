/* B711169 정다은 3학년 */
#ifndef RECTANGLE_H
#define RECTANGLE_H
using namespace std;

class Rectangle {
private:
	int xLow, yLow, height, width;
public:
	Rectangle(int, int, int, int);
	bool operator<(Rectangle&);
	bool operator==(Rectangle&);
	int GetHeight();
	int GetWidth();
	friend ostream& operator<<(ostream&, const Rectangle&);
};
#endif