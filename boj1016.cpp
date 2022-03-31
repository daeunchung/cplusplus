// 1 �� min �� 1,000,000,000,000
// min �� max �� min + 1,000,000
#include <iostream>
using namespace std;

//long long minn, maxx;
/*
// Ʋ�� �� Ǯ��
28   48
minn  maxx
30    50
2*2*7 |8 9 10 11 12 |
3*3*3 |4 5 |
4*4*1 |2 3 |
5*5*1 |2 |
6*6*|1 |

=> 2*2*9 �� 3*3*4 �� ���� ���ε� �ι� ���ִϱ� Ʋ���°� => �� Ǯ�̰� Ʋ�� ����
*/
//int main()
//{
//	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
//
//	int sqOKnums = 0;	//���� ������
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


// ���� X
bool arr[1000001];
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);	cout.tie(nullptr);
	long long minn, maxx;

	cin >> minn >> maxx;

	// min �� arr[0] �� ����
	// 2*2*firstmok-minn, 2*2*(firstmok+1)-minn, 2*2*(firstmok+2)-minn ... ���������� ������ ....
	
	for (long long i = 2; i * i <= maxx; i++)
	{
		long long mok = minn / (i * i);
		
		if (minn % (i * i) == 0) {
			arr[i * i * mok - minn] = true;
		}

		//for (long long j = i * i * (mok + 1) - minn; j <= maxx - minn; mok++) {	// �ݺ��� �����Ŀ��� mok�� ������Ű�� �װ� �ݿ��� �Ǵ�?
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