#include <bits/stdc++.h>
using namespace std;

// �˷����� ���� ģ���� (���� ���� Ǯ�̴� ���)- ���� �޴� ���ϱ�
const int INF = 987654321;

// �� �޴��� ��ΰ� �Ļ� �������� ���� ��ȯ
bool canEverybodyEat(const vector<int>& menu);

// �丮�� �� �ִ� ���� ����
int M;	

// food��° ������ ������ ���� ����
int selectMenu(vector<int>& menu, int food)
{
	// ���� ���: ��� ���Ŀ� ���� ������ ���θ� �������� ��
	if (food == M) {
		if (canEverybodyEat(menu)) return menu.size();
		// �ƹ��͵� �� �Դ� ����� ������ ���� ū ���� ��ȯ�Ѵ�.
		return INF;
	}

	// �� ������ ������ �ʴ� ����� ���� ���
	int ret = selectMenu(menu, food + 1);
	// �� ������ ����� ����� ���� ����ؼ� �� ���� ���� ���Ѵ�.
	menu.push_back(food);
	ret = min(ret, selectMenu(menu, food + 1));
	menu.pop_back();
	return ret;
}



int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	return 0;
}



// ���� �ڵ� https://chosh95.tistory.com/55

bool canEverybodyEat(const vector<int>& menu)
{
	return false;
}
