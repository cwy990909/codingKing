#include "score.h"
//����/����
void Jari::help() {
	srand((unsigned)time(0));
	Jari * Pjari;
	Pjari = new Jari;

	cout << endl << "\n\t\t��� ����" << " ���" << endl;
	cout << endl << "\t\t1�� : <<Ư�����ڸ� �����ϴ� ������>>" << endl << endl;
	cout << "\t\t���Ḧ ���Ͻø� ' '�� �Է����ּ���!" << endl << endl;

	cout << endl << "\t\t2�� : <<����� �ܾ �����ϴ� ������>>" << endl;
	cout << endl << "\t\t���Ḧ ���Ͻø� 'end'�� �Է����ּ���!" << endl << endl;

	cout << endl << "\t\t3�� : <<�迭�� �ܾ�� �Է��ϴ� ������>>" << endl << endl;
	cout << "\t\t���Ḧ ���Ͻø� 'end'�� �Է����ּ���!" << endl;
	getch();
	system("cls");
	Pjari->home();
}
