// [�������] STL map �ڷᱸ�� Ȱ��
//#include "pch.h"
#include <iostream>
#include <fstream>
#include <map>
//#include <string>
using namespace std;

// �ܾ �Է¹ް� �Է�Ƚ�� ī����, ���� ���� �Էµ� �ܾ�&Ƚ�� ��� 
int main(){
	ios_base::sync_with_stdio(false);
	ifstream cin;
	cin.open("input.txt");
	map<string, int> ch;	 			// <�ܾ�, Ƚ��> 
	map<string, int>::iterator it;
//	char a[100];	
	string a;
	int n;
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> a;
		ch[a]++; 
	}
	int max = 0;
	string res;
	
	for(it = ch.begin(); it != ch.end(); it++){
//		cout << it->first << " " << it->second << "\n";
		if(it->second > max){
			max = it->second;
			res = it->first;
		}
	}
	cout << res << " : " << max <<"\n";
	return 0;
}

