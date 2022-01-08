#include <iostream>
#include <set>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	set<int> s;
	set<int>::iterator iter;
	int N, x;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> x;
		s.insert(x);
	}
	cout << *s.begin() << " " << *(--s.end()) << '\n';
	return 0;
}
// 720ms => ���� ���� ������ �ٽ� �غ��� set �������ƺ�


// �Ʒ��ڵ� sky1357�� 72ms : �����ؼ� �����ɷ� �ߴµ� VS������ ���� X
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>

char s[9000000], d[] = " \n", *part;
int i, m = 2e9, M = -2e9;
//1e9 = 1 * 10��9�� = 1000000000,
//2e9 = 2 * 10��9�� = 2000000000

int main()
{
	fread(s, 1, 9000000, stdin);

	// �޾ƿ� s�� " ", "\n" �� �ɰ���
	strtok(s, d);
	part = strtok(NULL, d);

	while (part != NULL)
	{
		int pn = atoi(part);

		if (m > pn) m = pn;
		if (M < pn) M = pn;

		part = strtok(NULL, d);
	}

	printf("%d %d", m, M);

	return 0;
}

/* strtok �Լ� 
strtok �Լ��� ó�� �ҷ��ٶ��� ���ϴ� ���ڿ��� ����ְ� 
�� �������ʹ� ù��° ���ڿ� NULL�� �־��ִ� ���� �� �� �ִµ���, 
�̴� strtok �Լ����� "������ �ʰ� �����ڸ� ã�Ҵ� �� ���ڿ� �ּҿ��� ���� �ٽ� ã�ƴ޶�"�� ���� 
������ �ִٰ� �����ϸ�˴ϴ�.
strtok �Լ��� NULL�� ��ȯ�� �� ���� ����ؼ� �ҷ�����ϴ� �Լ��Դϴ�.
*/