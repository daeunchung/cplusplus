/* unique �Լ��� �������� �ߺ� �Ǵ� ���� �� vector�� ���� �޺κ����� ������ ������ ������. 
�� �ٽ� ���� �ߺ� ���� �ʴ� ���ҵ� ���� �տ��� ���� ä���. */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

struct loc {
	int seq, locX;
	loc(int n1, int n2) : seq(n1), locX(n2) {}
};

bool compare1(const loc& loc1, const loc& loc2)
{	return loc1.seq < loc2.seq;	}

bool compare2(const loc& loc1, const loc& loc2)
{	return loc1.locX < loc2.locX;	}

vector<loc> V;
vector<loc>::iterator iter, pr;

int N, x;

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> x;
		V.emplace_back(loc(i, x));
	}
	sort(V.begin(), V.end(), compare2);

	int newloc = 0;
	iter = V.begin();
	pr = iter--;
	while(iter != V.end()) {
		if (pr->locX != iter->locX) iter->locX = newloc++;	
		iter++;
	}
	sort(V.begin(), V.end(), compare1);
	for (iter = V.begin(); iter < V.end(); iter++) {
		cout << iter->locX << " ";
	}
}