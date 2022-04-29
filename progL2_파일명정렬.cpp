#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//���� : ���� �̸�(index, head, number)
struct fileName {
    int index;
    string head;
    int number;
};

vector<fileName> v;

//fileName ����ü ���� ����
bool compare(const fileName& f1, const fileName& f2) {
    if (f1.head == f2.head) {
        if (f1.number == f2.number) {
            return f1.index < f2.index;
        }
        else {
            return f1.number < f2.number;
        }
    }
    else {
        return f1.head < f2.head;
    }
}

//�ش� ���ڰ� �������� �Ǵ��ϴ� �Լ�
bool isNumber(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}

vector<string> solution(vector<string> files) {

    vector<string> answer;

    //��� ���� Ž��
    for (int i = 0; i < files.size(); i++) {

        //1. �ҹ��� ��ȯ
        string fileString = "";
        for (int j = 0; j < files[i].length(); j++) {
            fileString += tolower(files[i][j]);
        }

        //HEAD, NUMBER �ʱ�ȭ
        string HEAD = "";
        string NUMBER = "";
        int pointer = 0;

        //2-1. HEAD ����
        while (pointer <= fileString.length()) {

            //���ڰ� ������ �ݺ��� ����
            if (isNumber(fileString[pointer])) {
                break;
            }

            HEAD += fileString[pointer];
            ++pointer;
        }

        //2-2. NUMBER ����
        while (pointer <= fileString.length()) {

            //���ڰ� �ƴѰ��� ������ �ݺ��� ����
            if (!isNumber(fileString[pointer])) {
                break;
            }

            NUMBER += fileString[pointer];
            ++pointer;
        }

        //����ü ����
        fileName f;
        f.index = i;
        f.head = HEAD;
        f.number = stoi(NUMBER);

        //3. ���Ϳ� ����ü ����
        v.push_back(f);
    }

    //4. ����
    sort(v.begin(), v.end(), compare);

    //��� ����
    for (int i = 0; i < v.size(); i++) {
        answer.push_back(files[v[i].index]);
    }

    //��ȯ
    return answer;
}