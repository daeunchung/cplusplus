#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
//  �� �Է°��� ���ؼ� ���α׷��� �� ���� �����ؾ� �ϰ�, �� ������ ��� �������̴�. 
//  ��踶�� �����ϴ� ���α׷��� �޶� �װ� ������ ���ƾ���
//  ���� ���൵�߿� �߰��� Error �߻��� �� �ڿ� ���� ���̻� ������ �ʿ� X
#define MAXV 1000000000
typedef long long ll;
stack<ll> s;
vector<string> v;
vector<ll> numv;
// ��� ���� ���� �Լ����� error ���θ� ��ȯ�Ѵ�
bool NUM(ll x)
{
	s.push(x);
	return false;
}
bool POP()
{
	if (s.empty()) return true;
	s.pop();
	return false;
}
bool INV()
{
	if (s.empty()) return true;
	ll x = -(s.top());
	s.pop();
	s.push(x);
	return false;
}
bool DUP()
{
	if (s.empty()) return true;
	s.push(s.top());
	return false;
}
bool SWP()
{
	if (s.empty() || s.size() < 2) return true;
	ll x = s.top();
	s.pop();
	ll y = s.top();
	s.pop();
	s.push(x);
	s.push(y);
	return false;
}
bool ADD()
{
	if (s.empty() || s.size() < 2) return true;
	ll x = s.top();
	s.pop();
	ll y = s.top();
	s.pop();
	s.push(y + x);
	return false;
}
bool SUB()
{
	if (s.empty() || s.size() < 2) return true;
	ll x = s.top();
	s.pop();
	ll y = s.top();
	s.pop();
	s.push(y - x);
	return false;
}
bool MUL()
{
	if (s.empty() || s.size() < 2) return true;
	ll x = s.top();
	s.pop();
	ll y = s.top();
	s.pop();
	s.push(y * x);
	return false;
}
bool DIV()
{
	if (s.empty() || s.size() < 2) return true;
	ll x = s.top();
	if (x == 0) return true;
	s.pop();
	ll y = s.top();
	s.pop();
	if(y * x < 0)
		s.push(-(abs(y / x)));
	else
		s.push(abs(y / x));
	return false;
}
bool MOD()
{
	if (s.empty() || s.size() < 2) return true;
	ll x = s.top();
	if (x == 0) return true;
	s.pop();
	ll y = s.top();
	s.pop();
	if (y < 0)
		s.push(-(abs(y % x)));
	else
		s.push(abs(y % x));
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	ll x;
	string str;
	bool isError;
	while (true)	
	{
		isError = false;
		
		while (true)  // ���α׷� �Ѱ� ����
		{

			cin >> str;

			if (str == "NUM") {
				cin >> x;
				numv.push_back(x);
			}
			if (str == "QUIT") return 0;
			if (str == "END") break;

			v.push_back(str);
		}
		cin >> n;
		while (n--)
		{
			int idx = 0;
			ll defaultnum;

			cin >> defaultnum;
			s.push(defaultnum);

			for (int i = 0; i < v.size(); ++i) {
				if (v[i] == "NUM") {
					isError = NUM(numv[idx]);
					++idx;
				}
				else if (v[i] == "POP") isError = POP();
				else if (v[i] == "INV") isError = INV();
				else if (v[i] == "DUP") isError = DUP();
				else if (v[i] == "SWP") isError = SWP();
				else if (v[i] == "ADD") isError = ADD();
				else if (v[i] == "SUB") isError = SUB();
				else if (v[i] == "MUL") isError = MUL();
				else if (v[i] == "DIV") isError = DIV();
				else if (v[i] == "MOD") isError = MOD();


				if (!s.empty() && (s.top() > MAXV || s.top() < -MAXV )) isError = true;
				if (isError) break;
			}
			if (isError || s.size() != 1)
				cout << "ERROR\n";
			else
				cout << s.top() << '\n';

			while (!s.empty()) s.pop();
		}

		numv.clear();
		v.clear();
		cout << '\n';
	}
	return 0;
}