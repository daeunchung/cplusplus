// 1 ≤ min ≤ 1,000,000,000,000
// min ≤ max ≤ min + 1,000,000
#include <iostream>
using namespace std;

//long long minn, maxx;
/*
// 틀린 내 풀이
28   48
minn  maxx
30    50
2*2*7 |8 9 10 11 12 |
3*3*3 |4 5 |
4*4*1 |2 3 |
5*5*1 |2 |
6*6*|1 |

=> 2*2*9 와 3*3*4 는 같은 수인데 두번 빼주니까 틀리는거 => 내 풀이가 틀린 원인
*/
//int main()
//{
//	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
//
//	int sqOKnums = 0;	//제곱 ㅇㅇ수
//	cin >> minn >> maxx;
//	for (int i = 2; i * i <= maxx; i++)
//	{
//		long long firstmok = minn / (i * i);
//		long long lastmok = maxx / (i * i);
//		if (minn % (i * i) == 0) sqOKnums++;
//		//if (maxx % (i * i) == 0) sqOKnums++;
//		sqOKnums += (lastmok - firstmok);
//	}
//	int sqNOnums = maxx - minn + 1 - sqOKnums;
//	cout << sqNOnums << '\n';
//	return 0;
//}


// 로직 X
bool arr[1000001];
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	long long minn, maxx;

	cin >> minn >> maxx;

	// min 이 arr[0] 에 저장
	// 2*2*firstmok-minn, 2*2*(firstmok+1)-minn, 2*2*(firstmok+2)-minn ... 지워나가는 식으로 ....
	
	for (long long i = 2; i * i <= maxx; i++)
	{
		long long mok = minn / (i * i);
		
		if (minn % (i * i) == 0) {
			arr[i * i * mok - minn] = true;
		}

		//for (long long j = i * i * (mok + 1) - minn; j <= maxx - minn; mok++) {	// 반복문 증감식에서 mok을 증가시키면 그게 반영이 되니?
		//	arr[j] = true;
		//}
		for (long long j = i * i * (mok + 1) - minn; j <= maxx - minn; j += i * i) {
			arr[j] = true;
		}
	}

	int cnt = 0;
	for (int i = 0; i <= maxx - minn; i++) {
		if (!arr[i]) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}