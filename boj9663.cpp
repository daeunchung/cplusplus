/*
��Ʈ��ŷ�� N-Queens ����ó�� �������� �ַ���� ���� �������� ��� ����� Ž���ϴ� ���̴�. 
��ǥ���� ���� Ž�� ������δ� DFS(���� �켱 Ž��)�� �ִ�.
DFS�� ��� ȣ���� �̿��ؼ� Ž���� �� ������, depth�� ����� Ž���� �� �ִٴ� ������ �ִ�. 
������ ���� ��ǥ�� ���� �ʴ� ��α��� Ž���ϴ� ���� ��ȿ�����̴�. 
�׷��� ��ȵ� ���� ��Ʈ��ŷ���� DFS���� �� �̻� �������� ���� Ž����θ� �����Ͽ� 
��ȿ������ Ž���� ���� �� �ִ�.

�ذ����� ���ؼ� 
https://chanhuiseok.github.io/posts/baek-1/ �� �ڵ带 ������ �� �Դϴ�. 
*/

#include <iostream>
using namespace std;

int n, count = 0;
int board[15];

// �������� �Ǵ��ϴ� �Լ�
int promising(int cdx) {

	// ���� ���̸� �ȵǰ�, �밢���� �־�� �� �ȴ�.
	for (int i = 0; i < cdx; i++) {
		if (board[cdx] == board[i] || cdx - i == abs(board[cdx] - board[i])) {
			return 0;
		}
	}
	return 1;
}

// nqueen �˰��� ����
void nqueen(int cdx) {

	// cdx�� ������ ����� �����ϰ� ������� ����, ã�� �Ϸ�
	if (cdx == n) {
		::count++;
		return;
	}

	for (int i = 0; i < n; i++) {
		board[cdx] = i; // cdx��° ��, i��° ���� queen�� ���ƺ���.	
		// ���� �� �࿡ �� �Ϳ� ���� �������� �Ǵ��Ѵ�.
		if (promising(cdx)) { // �� �ڸ��� �ξ �����Ҵٸ�,
			nqueen(cdx + 1); // �� ���� �࿡ ���� ���� ���� ���� �� ����.
		}
	}
}

int main() {

	cin >> n;
	nqueen(0);
	cout << ::count << '\n';
	return 0;
}