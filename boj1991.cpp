#include <iostream>
using namespace std;

int N;
struct node {
    char left;  char right;
};
struct node arr[100];

void preOrder(char root)
{
    if (root == '.') return;
    else {
        cout << root;
        preOrder(arr[root].left);
        preOrder(arr[root].right);
    }
}

void inOrder(char root)
{
    if (root == '.') return;
    else {
        inOrder(arr[root].left);
        cout << root;
        inOrder(arr[root].right);
    }
}

void postOrder(char root)
{
    if (root == '.') return;
    else {
        postOrder(arr[root].left);
        postOrder(arr[root].right);
        cout << root;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    char c1, c2, c3;

    for (int i = 0; i < N; i++)
    {
        cin >> c1 >> c2 >> c3;
        arr[c1].left = c2;
        arr[c1].right = c3;
    }
    preOrder('A');  cout << '\n';
    inOrder('A');  cout << '\n';
    postOrder('A');  cout << '\n';
    return 0;
}
