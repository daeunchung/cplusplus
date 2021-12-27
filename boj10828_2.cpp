// 21-12-21
#include <iostream>
#include <string>
using namespace std;

struct Stack {
	int data[10000];
	int size;
	Stack()
	{
		size = 0;
	}
	void push(int num)
	{
		data[size] = num;	// ? ....??
		size += 1;
	}
	int pop()
	{
		if (size == 0) return -1;
		else {
			size -= 1;
			return data[size];
		}
	}
	int empty()
	{
		if (size == 0) return 1;
		else return 0;
	}
	int top()
	{
		if (size == 0) return -1;
		else return data[size-1];
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Stack s;
	int t, n;
	cin >> t;
	while (t--)
	{
		string str;
		cin >> str;
		if (str == "push")
		{
			cin >> n;
			s.push(n);
		}
		else if (str == "pop")
		{
			cout << s.pop() << '\n';
		}
		else if (str == "size")
		{
			cout << s.size << '\n';
		}
		else if (str == "empty")
		{
			cout << s.empty() << '\n';
		}
		else if (str == "top")
		{
			cout << s.top() << '\n';
		}
	}
	return 0;
}

// 0ms