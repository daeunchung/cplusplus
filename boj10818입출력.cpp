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
// 720ms => 뭔가 문제 있으니 다시 해볼것 set 쓰지말아봐


// 아래코드 sky1357님 72ms : 제출해서 맞은걸로 뜨는데 VS에서는 실행 X
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>

char s[9000000], d[] = " \n", *part;
int i, m = 2e9, M = -2e9;
//1e9 = 1 * 10의9승 = 1000000000,
//2e9 = 2 * 10의9승 = 2000000000

int main()
{
	fread(s, 1, 9000000, stdin);

	// 받아온 s를 " ", "\n" 로 쪼갠다
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

/* strtok 함수 
strtok 함수를 처음 불러줄때만 원하는 문자열을 집어넣고 
그 다음부터는 첫번째 인자에 NULL을 넣어주는 것을 알 수 있는데요, 
이는 strtok 함수에게 "이전에 너가 구분자를 찾았던 그 문자열 주소에서 부터 다시 찾아달라"는 뜻을 
가지고 있다고 생각하면됩니다.
strtok 함수가 NULL을 반환할 때 까지 계속해서 불러줘야하는 함수입니다.
*/