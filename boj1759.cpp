/*
���Ʈ���� ���շ� ��Ʈ��ŷ ����
c�� �߿� l �� ���(�ּ� �Ѱ��� ������ �ΰ��� ���� ����) ���ĺ������� ���� ��� ���
1. ���ĺ� �� ���� 2. ���ĺ� �ϳ��� �־�� ��ȣ�� ����O, X�� ������
cCl �� 2^c �� �ð����⵵

e.g. l==4, c==6, ��밡�ɾ��ĺ� atcisw �϶�
a c i s t w
o o o o o o
x x x x x x

��� 1 ����, ���� ���� ���� ���� �� �ȿ��� ���� �����ϰ� ��ȣ �����
��� 2 ���ĺ� l���� ��ȣ ���� ����� ���� �ּ� ����1, ����2 �����ϴ��� �����ֱ�
�� ��� ��� time complexity O(2^c)

��ͷ� Ǯ��
go(n, alpha, password, i) ��� ����Լ�
n : �������ϴ¾�ȣ����, alpha : ����Ҽ��ִ¾��ĺ�,
password : ������������ȣ, i : ����������������ؾ��ϴ¾��ĺ����ε���

������ ã�� ��� : ��� ���߿� ��ȣ�� ����==l �϶�
�Ұ����� ���(��͸� �̾���� ���� ���� �� ���� ���) : alphabet[idx] �� idx �� ��밡���Ѿ��ĺ����� c���� Ŀ����
�������� �Ѿ�� ��� : alphabet[idx] �� ���O �Ǵ� ���X �ϴ� ���� ������ ���⿡
   i��° ���ĺ� ���O : go(n, alpha, password + alpha[i], i+1)
   i��° ���ĺ� ���X : go(n, alpha, password, i+1)

����Լ� ���� ����
if() // ������ ã����쿡 ����
if() // �Ұ����� ��쿡 ����
���� �ΰ�if���� �ɷ������ʾ�����, ������� ����
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int l, c;

bool check(string& pw)
{
	int jaeum = 0, moeum = 0;
	for (char ch : pw)
	{
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') moeum++;
		else jaeum++;
	}
	if (jaeum >= 2 && moeum >= 1) return true;
	else return false;
	// return jaeum >= 2 && moeum >= 1; �̷��� ǥ���� ���� �ִٱ�!

}

void go(vector<char>& vec, string pw, int i)
{
	// �� �������� ��� ����� if �� ���� �ٲٸ� ���� �ȵ�. ��ҿ��� ����, ���⼭�� ����������.
	// ������ ���ĺ��� ����Ͽ� ��ȣ �ϼ��ǰ� ���� if (i >= c) return; �� ��� ������ �ʿ��ϱ� ����
	if (pw.size() == l) {
		if (check(pw)) cout << pw << '\n';
		return;
	}
	if (i >= c) return;
	go(vec, pw + vec[i], i + 1);
	go(vec, pw, i + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);

	cin >> l >> c;
	vector<char> v(c);
	for (int i = 0; i < c; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	go(v, "", 0);

	return 0;
}

/*
* Debug assertion Failed !
* Expression : vector subscription out of range ���� 
* ������ vector<char> v; �̵����� ���� ����� ���� �Լ� �ȿ��� �������� ����
* �迭�� �׷��� ������ ũ�� ���س��� �ϰ�
* ���ʹ� c�� �ް� ���� main���� vector<char> v(c) �� �����ϰ�
* �Լ����� v�� ����ؾ��� ������ ���ڷ� �Ѱ�����
*/