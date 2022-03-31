#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
// ���� ���� N(1 �� N �� 1,000,000)�� M(1 �� M �� 10,000), K(1 �� K �� 10,000) �� �־�����. 
// �Է����� �־����� ��� ���� -2^63���� ũ�ų� ����, 2^63-1���� �۰ų� ���� �����̴�.

// M�� ���� ������ �Ͼ�� Ƚ���̰�, K�� ������ ���� ���ϴ� Ƚ���̴�
//  ceil(log2(Num))�� ���� Height�� ���Ѵ�. - ������ ���ϴ� �ǰ�
// Tree[] �迭�� ���� ���, Num���� ũ�ų� ���� 2�� ������ �� ���� ���� ������*2��ŭ�� ������ �ʿ��ϱ� �����̴�.
// Tree[] �迭�� ũ�⸦ �������� �Ҵ����ش� (height * 2 -> (1<<height+1)
/*
-Init() �Լ��� ���� Tree�迭�� �ʱ�ȭ���ָ�, Node�� 1�� �����Ͽ� Tree�� 1���� ���� ����ִ´�.������ Arr[]�� ������ start, end�� �����Ѵ�(0~Num - 1)

- Sum() �Լ��� ���� Arr[Left]~Arr[Right]������ ���� ���Ѵ�

- Update() �Լ��� ���� Arr[idx] �� Arr[idx] + Diff��ŭ �ٲ۴ٰ� �� ��, Tree[]�� start~end�ε����� idx�� ���ԵǾ� �ִٸ� += Diff�� �����Ѵ�
*/
ll* tree;
ll arr[1000001];

//
ll init(int node, int start, int end)
{
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);

}
// left right �� ����, ������ �ٲ�� ���� start, end
// start   end                                                                - (a)
//            start       end                                                 - (b) 
//                              start    end                                  - (c)
//                                      start        end                      - (d)
//                                                      start        end      - (e)
//                                
//                   LEFT                     RIGHT  (����)
ll sum(int node, int start, int end, int left, int right)
{
    if (end < left || right < start) return 0;                            // - (a,e)
    if (left <= start && end <= right) return tree[node];                 // - (c)
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, ll diff)
{
    if (idx <start || idx > end) return;
    tree[node] += diff;
    if (start == end) return;
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, diff);
    update(node * 2+1, mid+1, end, idx, diff);
}

int main() 
{
    ios_base::sync_with_stdio(false);   cin.tie(0);  cout.tie(0);

    int N, M, K; //���ǰ���, ���� �Ͼ�� Ƚ��, ������ ���� ���ϴ� Ƚ��
    int a, b, c2;   ll c1;
    cin >> N >> M >> K;
    //int height = sqrt(N);
    int height = ceil(log2(N));
    tree = new ll[1 << (height + 1)];

    for (int i = 0; i < N; i++) cin >> arr[i];

    init(1, 0, N-1);

    for (int i = 0; i < M + K; i++) {
        cin >> a >> b;;
        if (a == 1) {   //b->c�� ��ȯ
            cin >> c1;
            long long diff = c1 - arr[b - 1];
            arr[b - 1] = c1;
            update(1, 0, N - 1, b - 1, diff);
        }
        else if (a == 2) {
            cin >> c2;
            //cout << sum(1, 0, N - 1, b - 1, c - 1) << '\n';       // C4244 _int64���� int�� ��ȯ�ϸ鼭 �����Ͱ� �սǵ� �� ����
            cout << sum(1, 0, N - 1, b - 1, c2 - 1) << '\n'; 
        }
    }
    return 0;
}