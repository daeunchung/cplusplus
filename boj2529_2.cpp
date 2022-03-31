// 2. ��Ʈ��ŷ (4ms)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n;
char a[10];         // �Է¹��� �ε�ȣ ����
vector<string> ans; // ���� ������ ���ڿ��� ����
bool check[10];     // 0 ~ 9 ���ڻ�뿩��check

bool good(char x, char y, char op)
{
    if (op == '<') {
        if (x > y) return false;
    }
    else if (op == '>') {
        if (x < y) return false;
    }
    return true;    // �κvȣ Ʋ���°� ������ true 
}
void go(int index, string num)
{
    // �ε�ȣ �� ä������ ������ �� �ĺ��� �־��ش�
    if (index == n + 1) {
        ans.push_back(num);
        return;
    }
    // �ε�ȣ �� �� ä������
    for (int i = 0; i <= 9; i++) {
        if (check[i]) continue; // �̹� ����� ���ڸ� pass
        // ù�ε�ȣ�� ������ ��(ù����) or ���»��� ������ �ε�ȣ �����ÿ�
        if (index == 0 || good(num[index-1], i+'0', a[index-1])) {
            check[i] = true;
            go(index + 1, num + to_string(i));
            check[i] = false;
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    go(0, "");
    auto p = minmax_element(ans.begin(), ans.end());
    cout << *p.second << '\n';  // �ִ�
    cout << *p.first << '\n';   // �ּ�
    return 0;
}