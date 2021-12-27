// DD75.cpp 부터는 BB폴더에 비주얼스튜디오로 코딩했음  

#include <iostream>
using namespace std;

struct Point {
	int x, y;
};

class Polygon {	// 다각형
public:
	Polygon(){
		nPoints = 0;
		points = NULL;
	}
	Polygon(const int nPoints, const Point *points) : nPoints(nPoints) { 
		this->points = new Point[nPoints];
		for(int i=0; i<nPoints; i++){
			this->points[i] = points[i];
		}
	}

	// 복사 생성자 구현 
	Polygon(const Polygon &rhs){
		nPoints = rhs.nPoints;
		points = new Point[nPoints];
		for(int i=0; i<nPoints; i++){
			points[i] = rhs.points[i];	// 깊은복사 
		}
		cout << "깊은 복사" << endl;
	}
	// 이동 생성자 구현 (어짜피 지워질 객체들 효율성을 위해 메모리할당X  )
	Polygon(Polygon &&rhs){
		nPoints = rhs.nPoints;	// 얕은복사불가능
		points = rhs.points;	// 메모리 새로안파고 포인터값만 얕은복사 
		rhs.points = NULL;		// 소멸자에서 rhs가 가리키는 메모리해제할꺼라 연결을 끊어주기 
		cout << "얕은 복사" << endl;
	}

	~Polygon(){
		delete[] points;
	}
	
	// 복사 대입 연산자 구현
	Polygon &operator=(const Polygon &rhs){
		if(this != &rhs){
			nPoints = rhs.nPoints;
			delete[] points;
			points = new Point[nPoints];
			for(int i=0; i<nPoints; i++){
				points[i] = rhs.points[i];	// 깊은복사 
			}
		}
		cout << "깊은 복사" << endl;
		return *this;
	}
	
	// 이동 대입 연산자 구현
	Polygon &operator=(Polygon &&rhs){
		if(this != &rhs){
			nPoints = rhs.nPoints;
			delete[] points;
			points = rhs.points;
			rhs.points = NULL;
		}
		cout << "얕은 복사" << endl;
		return *this;	 
	}
	int GetNPoints() const {
		return nPoints;
	} 
	 
	Point *GetPoints() const {
		if(nPoints == 0) return NULL;
		return points;
	}

private:  
	int nPoints;
	Point *points;		// 꼭짓점(구조체Point형태)을 저장한 동적할당된 배열을 가리키는 포인터 
};

Polygon getSqare(){
	Point points[4] = { {0,0}, {1,0}, {0,1}, {1,1} };
	Polygon p(4, points);
	return p;
}

int main(){
	Polygon a;
	a = getSqare();		// 얕은 객체 복사 2회
	Polygon b = a;		// 깊은 객체 복사 1회 	Polygon b(a);와 동일
	Polygon c;
	c = a;				// 깊은 객체 복사 1회
	
	int nPoints = c.GetNPoints();
	Point *points = c.GetPoints();
	for(int i=0; i<nPoints; i++){
		cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
	}
} 
