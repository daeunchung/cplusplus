#include <bits/stdc++.h>
using namespace std;

string solution(string s) {

    //check�� true�� ������ ��(���� ������ ������ ����)
    int i = 0;

    //true�� �����ؾ� �� ó�� �ܾ ���� ����.
    bool check = true;
    while (s[i]) {
        //������ ��� flag�ϰ� �Ѿ
        if (s[i] == ' ') {
            check = true;
            i++;
            continue;
        }
        else {
            //������ �ƴ� ���ڸ� ������ ���
            //1.ù��° ����
            if (check) {
                s[i] = toupper(s[i]);
                check = false;
            }
            //2. ù��°�� �ƴ� ����.
            else {
                s[i] = tolower(s[i]);
                check = false;
            }
            i++;
        }
    }
    return s;
}