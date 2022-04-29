#include <bits/stdc++.h>
using namespace std;

string solution(string s) {

    //check가 true인 상태일 때(공백 다음에 나오는 문자)
    int i = 0;

    //true로 시작해야 맨 처음 단어에 대응 가능.
    bool check = true;
    while (s[i]) {
        //공백일 경우 flag하고 넘어감
        if (s[i] == ' ') {
            check = true;
            i++;
            continue;
        }
        else {
            //공백이 아닌 문자를 만났을 경우
            //1.첫번째 문자
            if (check) {
                s[i] = toupper(s[i]);
                check = false;
            }
            //2. 첫번째가 아닌 문자.
            else {
                s[i] = tolower(s[i]);
                check = false;
            }
            i++;
        }
    }
    return s;
}