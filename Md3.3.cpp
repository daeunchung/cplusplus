// ����1 ���ڿ�Ŭ������ �ϼ��غ����� (���̵�:��) 

class string {
  char *str;
  int len;

 public:
  string(char c, int n);  // ���� c �� n �� �ִ� ���ڿ��� ����
  string(const char *s);
  string(const string &s);
  ~string();

  void add_string(const string &s);   // str �ڿ� s �� ���δ�.
  void copy_string(const string &s);  // str �� s �� �����Ѵ�.
  int strlen();                       // ���ڿ� ���� ����
};

	bool operator<(const State &b)const{}
	1. �Ű������� ���ȭ(��� �Լ�) 
		�Է¹޴� �Ű������� ������ ���ϵ��� ����. 
	
	2. �޼����� ���ȭ(��� �޼���) 
		��� �޼��� �Լ��� ��ȣ�ݰ� �ٷ� "�ڿ�" const .
		�޼��� �����߿� ��������� ���� �ٲ��� ���ϵ���. �ٲ�� �����Ͽ��� 
		��Ȥ���� const int func(){} �̰� ��ȯŸ���� const int�� ��°Ű� �޼��� ���ȭX 

