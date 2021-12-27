// [�������] STL map �ڷᱸ�� Ȱ��
//#include "pch.h"
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
int main(){
	// cin, cout�� scanf, printf ��ŭ �ӵ� ���� ���� ����ȭ ����.�״�� cin scanf ���û�� �Ұ��� 
	ios_base::sync_with_stdio(false);
	ifstream cin;
	cin.open("input.txt");
	
/*
map �ڷᱸ�� : 
<key, value> key�� index��� ����
�������� ����Ʈ�� red-black tree 
map�� vector ó�� int i�� ���� �Ұ���. it�� ����Ѵ�. 
iterator : map�� �����ϱ� ���� �ݺ���.(�����ͷ� ����)
ch.end(); �� ������ �ڷḦ ����Ű���ʰ� ������ �ڷ��� ��ĭ�� ����Ų��. 
*/
	map<char, int> ch;	 
	map<char, int>::iterator it;
	char a[100];	
	cin >> a;
	for(int i = 0; a[i]!='\0'; i++){
		// �Է¹��� �����͸� ch������ ī����
		ch[a[i]]++; 
	}
	for(it = ch.begin(); it != ch.end(); it++){
		cout << it->first << " " << it->second << "\n";
	}
	return 0;
}
 
