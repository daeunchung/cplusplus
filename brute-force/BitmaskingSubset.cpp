void Subset()
{
	for (int flag = 0; flag < (1 << n); ++flag)
	{
		for (int i = 0; i < n; ++i)
			if ((1 << i) & flag)
				cout << arr[i] << " ";
		cout << '\n';
	}
}
 
int main()
{
	Subset();
	cout << "부분집합의 개수 : " << (1 << n) << '\n';
}
