/*
* �ε�ȣ - ��Ʈ��ŷ, ���Ʈ����
1. ���� �� �����ϰ� �˻�
2. ���� ����'�ϸ鼭' (�Ź�)�˻�

1(���Ʈ����) ���� 2(��Ʈ��ŷ)�� ��� (920ms -> 8ms ����)
 < < < > < < > < > �϶� �տ��� �̹� 9 < 8 �̸� �ڿ��� ���� ä��°� �ð����� => �� ��� Ž���� ����

 �ε�ȣ ���� 2 �� k �� 9 
�� ���鿡 �� �� �ִ� ���� 0~9 �� �ð����⵵ : 10^(k+1)

check[] �迭 : �̹� ����� ������ check �ϴ� �迭
*/

// 1. ���Ʈ���� (272ms)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int n;
char a[10];         // �Է¹��� �ε�ȣ ����
vector<string> ans; // ���� ������ ���ڿ��� ����
bool check[10];     // 0 ~ 9 ���ڻ�뿩��check

bool good(string num)
{
    for (int i = 0; i < n; i++) {
        if (a[i] == '<') {
            if(num[i] > num[i + 1]) return false;
        }
        else if (a[i] == '>') {
            if(num[i] < num[i + 1]) return false;
        }
    }
    return true;    // �κvȣ Ʋ���°� ������ true 
}
void go(int index, string num)
{
    // �ε�ȣ �� ä������
    if (index == n + 1) {
        if (good(num)) {
            ans.push_back(num);
        }
        return;
    }
    // �ε�ȣ �� �� ä������
    for (int i = 0; i <= 9; i++) {
        if (check[i]) continue; // �̹� ����� ���ڸ� pass
        check[i] = true;
        go(index + 1, num + to_string(i));
        check[i] = false;
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