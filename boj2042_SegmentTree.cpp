#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
// 수의 개수 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 가 주어진다. 
// 입력으로 주어지는 모든 수는 -2^63보다 크거나 같고, 2^63-1보다 작거나 같은 정수이다.

// M은 수의 변경이 일어나는 횟수이고, K는 구간의 합을 구하는 횟수이다
//  ceil(log2(Num))을 통해 Height을 구한다. - 제곱근 구하는 건가
// Tree[] 배열을 만들 경우, Num보다 크거나 같은 2의 제곱수 중 가장 작은 제곱수*2만큼의 공간이 필요하기 때문이다.
// Tree[] 배열의 크기를 동적으로 할당해준다 (height * 2 -> (1<<height+1)
/*
-Init() 함수를 통해 Tree배열을 초기화해주며, Node는 1로 설정하여 Tree의 1부터 값을 집어넣는다.참조할 Arr[]의 범위를 start, end로 설정한다(0~Num - 1)

- Sum() 함수를 통해 Arr[Left]~Arr[Right]까지의 합을 구한다

- Update() 함수를 통해 Arr[idx] → Arr[idx] + Diff만큼 바꾼다고 할 때, Tree[]의 start~end인덱스에 idx가 포함되어 있다면 += Diff를 수행한다
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
// left right 는 고정, 구간이 바뀌는 것은 start, end
// start   end                                                                - (a)
//            start       end                                                 - (b) 
//                              start    end                                  - (c)
//                                      start        end                      - (d)
//                                                      start        end      - (e)
//                                
//                   LEFT                     RIGHT  (고정)
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

    int N, M, K; //수의개수, 변경 일어나는 횟수, 구간의 합을 구하는 횟수
    int a, b, c2;   ll c1;
    cin >> N >> M >> K;
    //int height = sqrt(N);
    int height = ceil(log2(N));
    tree = new ll[1 << (height + 1)];

    for (int i = 0; i < N; i++) cin >> arr[i];

    init(1, 0, N-1);

    for (int i = 0; i < M + K; i++) {
        cin >> a >> b;;
        if (a == 1) {   //b->c로 변환
            cin >> c1;
            long long diff = c1 - arr[b - 1];
            arr[b - 1] = c1;
            update(1, 0, N - 1, b - 1, diff);
        }
        else if (a == 2) {
            cin >> c2;
            //cout << sum(1, 0, N - 1, b - 1, c - 1) << '\n';       // C4244 _int64에서 int로 변환하면서 데이터가 손실될 수 있음
            cout << sum(1, 0, N - 1, b - 1, c2 - 1) << '\n'; 
        }
    }
    return 0;
}