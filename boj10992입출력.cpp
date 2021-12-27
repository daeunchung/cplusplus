#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = N-1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++) cout << ' ';
		cout << '*';
		if (i == 0) {
			for (int j = 0; j < 2 * (N - 1 - i) - 1; j++) cout << '*';
		}
		else
		{
			for (int j = 0; j < 2 * (N - 1 - i) - 1; j++) cout << ' ';
		}
		if(i != N-1) cout << '*';
		if(i != 0) cout << '\n';
	}
	return 0;
}

//    *
//   * *
//  *   *
// *     *
//*********
//N = 5
//4 * 0    i = 4  N-1¹ø °ø¹é 
//3 * 1 *  i = 3   2*1-1
//2 * 3 *  i = N-3   2*2-1
//1 * 5 *  i = N-4   2*3-1   1 + 3 = 4
//0 * 7* * i = N-5   2*4-1   0 + N-1 = N-1

