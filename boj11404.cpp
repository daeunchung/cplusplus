/* �÷��̵� �ͼ� : ���İ��� ���� k �� �������� �˰����� ���� */

#include <iostream>
#include <vector>
using namespace std;
int arr[101][101];
int N, M, a, b, c;
int INF = 100000000; // �۰� ����ָ� �ϳ��� �Ÿ��� �ִ� 10���� ���� ���� �� �ֱ� ������ Ʋ�Ƚ��ϴ�

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			arr[i][j] = INF;

	for (int i = 1; i <= M; i++)
	{
		cin >> a >> b >> c;
		if (!arr[a][b])
			arr[b][c] = c;
		else //�̹� ��ΰ� �ִ� ��� �ּҰ� ����
			arr[a][b] = min(arr[a][b], c);
	}

	for (int i = 1; i <= N; i++) arr[i][i] = 0;

	// �÷��̵� �ͼ�
	for (int k = 1; k <= N; k++) // ���İ��� ���
	{
		for (int i = 1; i <= N; i++) // ����ϴ� ���
		{
			for (int j = 1; j <= N; j++) // �����ϴ� ���
			{
				if (arr[i][k] == 0 || arr[k][j] == 0 || i == j)
					continue;
				if (arr[i][j] == 0 || arr[i][k] + arr[k][j] < arr[i][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == INF) cout << 0 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}