// DD75.cpp ���ʹ� BB������ ���־�Ʃ����� �ڵ�����  

#include <iostream>
using namespace std;

struct Point {
	int x, y;
};

class Polygon {	// �ٰ���
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

	// ���� ������ ���� 
	Polygon(const Polygon &rhs){
		nPoints = rhs.nPoints;
		points = new Point[nPoints];
		for(int i=0; i<nPoints; i++){
			points[i] = rhs.points[i];	// �������� 
		}
		cout << "���� ����" << endl;
	}
	// �̵� ������ ���� (��¥�� ������ ��ü�� ȿ������ ���� �޸��Ҵ�X  )
	Polygon(Polygon &&rhs){
		nPoints = rhs.nPoints;	// ��������Ұ���
		points = rhs.points;	// �޸� ���ξ��İ� �����Ͱ��� �������� 
		rhs.points = NULL;		// �Ҹ��ڿ��� rhs�� ����Ű�� �޸������Ҳ��� ������ �����ֱ� 
		cout << "���� ����" << endl;
	}

	~Polygon(){
		delete[] points;
	}
	
	// ���� ���� ������ ����
	Polygon &operator=(const Polygon &rhs){
		if(this != &rhs){
			nPoints = rhs.nPoints;
			delete[] points;
			points = new Point[nPoints];
			for(int i=0; i<nPoints; i++){
				points[i] = rhs.points[i];	// �������� 
			}
		}
		cout << "���� ����" << endl;
		return *this;
	}
	
	// �̵� ���� ������ ����
	Polygon &operator=(Polygon &&rhs){
		if(this != &rhs){
			nPoints = rhs.nPoints;
			delete[] points;
			points = rhs.points;
			rhs.points = NULL;
		}
		cout << "���� ����" << endl;
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
	Point *points;		// ������(����üPoint����)�� ������ �����Ҵ�� �迭�� ����Ű�� ������ 
};

Polygon getSqare(){
	Point points[4] = { {0,0}, {1,0}, {0,1}, {1,1} };
	Polygon p(4, points);
	return p;
}

int main(){
	Polygon a;
	a = getSqare();		// ���� ��ü ���� 2ȸ
	Polygon b = a;		// ���� ��ü ���� 1ȸ 	Polygon b(a);�� ����
	Polygon c;
	c = a;				// ���� ��ü ���� 1ȸ
	
	int nPoints = c.GetNPoints();
	Point *points = c.GetPoints();
	for(int i=0; i<nPoints; i++){
		cout << "(" << points[i].x << "," << points[i].y << ")" << endl;
	}
} 
