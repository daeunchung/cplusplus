#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int StringToInt(string s)
{
	int slen = s.size();
	int value = 0;
	for (int i = 0; i < slen; i++)
	{
		value += (s[i] - '0') * pow(10, slen - i - 1);
	}
	return value;
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	vector<int> v(10);
	for (int i = 0; i < 10; i++) v[i] = i;

	string finalch;	cin >> finalch;
	int c;	cin >> c;
	for (int i = 0; i < c; i++)
	{
		int b;
		cin >> b;
		v[b] = 100;	// 9���� ū �ƹ� ��
	}
	sort(v.begin(), v.end());	// ��������
	v.erase(v.begin() + 10 - c, v.end());	// v���� �ִ� ������ ��ư�� ����

	int ans = 0, currentch = 0;
	int buttonchoice = 0;
	int nlen = finalch.size();

	// finalch == 100, 101, 102 ��(?) �϶� (�ּ��� ���� ���ϱ� ���� ����ó��)
	if (nlen > abs(StringToInt(finalch) - 100)) {
		cout << abs(StringToInt(finalch) - 100) << '\n';
		return 0;
	}

	//109
	//9
	//0 2 3 4 5 6 7 8 9 // 1�� �ִ»�Ȳ
	//=> 111--  (5)
	//105
	//9
	//0 2 3 4 5 6 7 8 9 // 1�� �ִ»�Ȳ
	//= > 111------ (9)X   +++++(5)O

	// ���ڹ�ư'��'������ �ּ��� ����(��ǥä�ΰ� �ִ�� ����� ����) ����� for��
	for (int i = 0; i < nlen; i++)
	{
		auto it = find(v.begin(), v.end(), finalch[i] - '0');
		// ������ ��ư �߿� d[i] �� ������ d[i]�� ���� �������� ���Գ��� ��ư ã�Ƽ� ������
		if (it == v.end()) {
			// �ּҷ� ���̳��� ���� ã��
			int diff = 100000;
			for (auto ptr = v.begin(); ptr != v.end(); ++ptr) {
				if (diff > abs(finalch[i] - '0' - *ptr)) {
					diff = abs(finalch[i] - '0' - *ptr);
					buttonchoice = *ptr;
				}
			}
			currentch += buttonchoice * pow(10, nlen - i - 1);

		}
		// ������ ��ư �߿� d[i] �� ������ ������
		else
		{
			currentch += (*it) * pow(10, nlen - i - 1);
		}
		ans = i + 1;
	}

	// ���ڸ� ������ ���� ����� ä�η� �̵��߰� +,- ���� ������ ����
	int symbolcnt = currentch - StringToInt(finalch);
	if (symbolcnt > 0) ans += symbolcnt;
	else ans -= symbolcnt;

	cout << ans << '\n';
	return 0;
}