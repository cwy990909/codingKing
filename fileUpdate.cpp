#include "score.h"
//�ڽ��� ���ϴ� �ܾ�� ������ �����Ѵ�. (c://file//keyword)�� ����� ������ �����Ѵ�.

void Jari::fileUpdate()
{
	Jari * Pjari;
	Pjari = new Jari;

	char result[100];
	FILE *f;
	f = fopen("keyword.txt", "w"); //���� ����
	if (f == NULL) {
		printf("File error!!");
	}
	else
	{
		int count;
		cout << "�� ���ڸ� �Է��Ͻðڽ��ϱ�>>";
		cin >> count;
		cout << "���ڸ� �Է����ּ���>>\n";
		for (int i = 0; i<count; i++) {
			cin >> result;
			fprintf(f, " %s\t", result);
		}
	}
	fclose(f);
	cout << "����� �Ϸ�Ǿ����ϴ�!!" << endl;
	getchar();
	system("cls");
	Pjari->home();
}
