#include <stdio.h>
#pragma warning(disable: 4996)

#define SIZE 5 // �ο���
int main() {
	struct employee_info // ����ü ����
	{
		char name[12]; // �ִ� 11�� ���� �迭
		char id[10]; // �ִ� 9�� ���� �迭
		int salary; // �޿� ������ ������ ���
	};
	struct employee_info employee[SIZE]; // ����ü �迭 ����
	int average = 0, sum = 0; // �޿� ���, �޿� �հ�
	register int i;
	printf(">> ������ ����(�̸�, ID, �޿�)�� �Է��ϼ���. << \n");
	
	for (i = 0; i < SIZE; i++) {
		printf("%d��: ", i + 1);
		scanf("%s %s %d", employee[i].name, employee[i].id, &employee[i].salary);
		sum += employee[i].salary; // �޿� �հ�
	}
	average = sum / SIZE; // �޿� ���(������)
	printf("\n----------------------\n");
	printf(" �޿��� %d����(���) �̻��� �������� ", average);
		printf("\n----------------------\n");
	for (i = 0; i < SIZE; i++) {
		if (employee[i].salary >= average)
			printf("\t%s\t %d���� \n",
				employee[i].id, employee[i].salary);
	}
	printf("------------------------\n");
	return 0;
}