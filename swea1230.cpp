/* 1230. [S/W 문제해결 기본] 8일차 - 암호문3 D3 */
#include <iostream>
#include <list>
using namespace std;
int testCase = 10, l1, l2, l3, x, y, s;
char ch;
list<int>::iterator iter;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= testCase; i++)
	{
		list<int> lst;
		cin >> l1;
		for (int i = 0; i < l1; i++) {
			cin >> l2;
			lst.push_back(l2);
		}
		cin >> l3;
		for (int i = 0; i < l3; i++) {
			cin >> ch ;
			if (ch == 'A') {
				cin >> y;
				for (int i = 0; i < y; i++)
					cin >> s;
					lst.push_back(s);
			}
			else if (ch == 'I') {
				cin >> x >> y;
				iter = lst.begin();
				for (int i = 0; i < x; i++)
					++iter;
				for (int i = 0; i < y; i++) {
					cin >> s;
					lst.insert(iter, s);
				}
			}
			else if (ch == 'D')
			{
				cin >> x >> y;
				iter = lst.begin();
				for (int i = 0; i < x; i++)
					++iter;
				for (int i = 0; i < y; i++) {
					iter = lst.erase(iter);
				}
			}
		}
		cout << "#" << i << " ";
		iter = lst.begin();
		for (int i = 0; i < 10; i++) {
			cout << *iter << " ";
			iter++;
		}		cout << "\n";
	}
	return 0;
}