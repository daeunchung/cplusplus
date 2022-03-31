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
		v[b] = 100;	// 9보다 큰 아무 수
	}
	sort(v.begin(), v.end());	// 오름차순
	v.erase(v.begin() + 10 - c, v.end());	// v에는 있는 리모컨 버튼만 저장

	int ans = 0, currentch = 0;
	int buttonchoice = 0;
	int nlen = finalch.size();

	// finalch == 100, 101, 102 등(?) 일때 (최선의 숫자 구하기 전에 예외처리)
	if (nlen > abs(StringToInt(finalch) - 100)) {
		cout << abs(StringToInt(finalch) - 100) << '\n';
		return 0;
	}

	//109
	//9
	//0 2 3 4 5 6 7 8 9 // 1만 있는상황
	//=> 111--  (5)
	//105
	//9
	//0 2 3 4 5 6 7 8 9 // 1만 있는상황
	//= > 111------ (9)X   +++++(5)O

	// 숫자버튼'만'가지고 최선의 숫자(목표채널과 최대로 가까운 숫자) 만드는 for문
	for (int i = 0; i < nlen; i++)
	{
		auto it = find(v.begin(), v.end(), finalch[i] - '0');
		// 리모컨 버튼 중에 d[i] 가 없으면 d[i]와 가장 숫자차가 적게나는 버튼 찾아서 누른다
		if (it == v.end()) {
			// 최소로 차이나는 숫자 찾기
			int diff = 100000;
			for (auto ptr = v.begin(); ptr != v.end(); ++ptr) {
				if (diff > abs(finalch[i] - '0' - *ptr)) {
					diff = abs(finalch[i] - '0' - *ptr);
					buttonchoice = *ptr;
				}
			}
			currentch += buttonchoice * pow(10, nlen - i - 1);

		}
		// 리모컨 버튼 중에 d[i] 가 있으면 누른다
		else
		{
			currentch += (*it) * pow(10, nlen - i - 1);
		}
		ans = i + 1;
	}

	// 숫자만 가지고 가장 가까운 채널로 이동했고 +,- 갯수 세어줄 차례
	int symbolcnt = currentch - StringToInt(finalch);
	if (symbolcnt > 0) ans += symbolcnt;
	else ans -= symbolcnt;

	cout << ans << '\n';
	return 0;
}