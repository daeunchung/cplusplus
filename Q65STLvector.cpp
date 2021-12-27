// [�������] STL vector �������
/*
ios::sync_with_stdio�� cpp�� iostream�� c�� stdio�� ����ȭ�����ִ� ����
�⺻���� true : cout << "HI"; printf("BYE"); cout<<"hi" �� ������� ���
		 false: � ������ ��µ��� �� ���� ����. 
�׷��� ������ ios::sync_with_stdio(false); �� �߰��Ͻø�, 
iostream �Լ��� cin/ cout�� stdio �Լ��� getchar()�� ȥ���ϸ� �ȉ�. 
*/
#include <iostream>       
#include <vector>
using namespace std;
int main(){
//	iso_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	
	vector<int> a;
	a.push_back(6); 
	a.push_back(8); 
	a.push_back(11);
	cout<<a.size()<<endl;
	cout<<a[1]<<endl;
	
	vector<int> c[3];
	c[0].push_back(1); 
	c[0].push_back(3); 
	c[0].push_back(5); 
	c[1].push_back(2); 
	c[1].push_back(4); 
	c[1].push_back(6); 
	c[2].push_back(7); 
	cout<<c[1][1]<<endl;
	cout<<c[2][0]<<endl;
	
	// ����ġ��������Ʈ �� ��밡��  
	vector<pair<int, int> > g[3];	// graph[3];
	g[1].push_back({3, 5}); 
	g[1].push_back({4, 7}); 
	g[1].push_back({5, 9}); 
	g[2].push_back(make_pair(7, 7));
	cout<<g[2][0].first<<" "<<g[2][0].second<<endl;
	
	return 0;
}





