#include "score.h"
//�迭�� �ܾ �����ָ� �� �ܾ �Է��Ͽ� ���ִ� �Լ�
//���� �ܾ ���� ��� �ΰ��� ������� �ʰ� �ϱ� ����( bool already)�迭�� ����Ͽ���, 
//'end' | �ܾ �� ������ ��� ���� �����׸� ���
void gotoxy(int x, int y)
{
    COORD Pos = { x-1, y-1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void Jari::jawon() {
	Jari * Pjari;
	Pjari = new Jari;
	srand((unsigned int)time(0));
	int process = 1;
	int score = 0;
	int choice;
	int k = 0;
	char in[50] = "";
	string result = "";
	string error[100] = { " " };
	string coding[100] = { " " };
	string line[300];
	bool already[25] = { 0 };
	ifstream input("keyword.txt");
	if (input.fail()) {
		cout << "������ ���� ���� �ʽ��ϴ�!" << endl;
		cout << "c://file ��ο� input.txt ������ ������ �ּ���!!" << endl;
		getch();
		system("cls");
		Pjari->home();
	}
	while (!input.eof()) {
		input >> line[k];
		k++;
	}
	if (k == 1) {
		cout << "\t\t������ ����ֽ��ϴ�!!" << endl;
		cout << "\t\t����������������" << endl;
		cout << "\t\t��  \t 1. Ȩ���� ����     ��" << endl;
		cout << "\t\t��  \t 2. ����Ϸ� ����   ��" << endl;
		cout << "\t\t����������������" << endl;
		cout << "\t\t���� >>";
	Again:
		cin >> choice;
		if (choice == 1) { system("cls"); Pjari->home(); }
		else if (choice == 2) { system("cls"); Pjari->fileUpdate(); }
		else { cout << "�������� �ʴ� ��ȣ �Դϴ� >>"; goto  Again; }
	}

	srand(unsigned(time(0)));
	for (int i = 0; i<25; i++) {
		coding[i] = line[(rand() % (k-1))];   //�ڵ� �迭 ����
	}
	system("mode con:cols=100 lines=30");
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			gotoxy(1,1);
			gotoxy(15*(i+1), 5*(j+1));
			cout<<coding[(i*5) + j];
		}
	}
	while(process!=25){
			gotoxy(5,3);
			cout<<"�Է� >>";
			cin >> result;
			for(int i=0;i<5;i++){
				for(int j=0;j<5;j++){
					if(result.compare(coding[i*5+j]) == 0 && !already[i*5+j]==1){  //�ܾ �´���, �� �ܾ ������� ���� ������
						already[i*5+j]=1;
						score++;
						gotoxy(1,1);
						gotoxy(15*(i+1), 5*(j+1));
						cout<<"              ";
						goto finish;
					}//if
				}//for j
			}//for i
			finish:
			gotoxy(1,1);
			cout<<"\t\t��� ������� : "<<score;
			gotoxy(1,1);
			gotoxy(5, 3);
			cout<<"                                 "<<endl;
			if(score==25)
				break;
			if (result.compare("end") == 0) {
				break;
			}
		}
		system("mode con:cols=82 lines=25");
		for (int j = 0; j<5; j++) { cout << endl; }
		char * print[5] = {
			"\t\t����������������",
			"\t\t��  \t 1. Ȩ���� ����     ��",
			"\t\t��  \t 2. �ٽ��ϱ�        ��",
			"\t\t��  \t ���. �׸��ϱ�   ��",
			"\t\t����������������"
		};

		for (int i = 0; i<5; i++) {
			cout << print[i] << endl;
		}
		cout << "\n\n\t����  >>  ";
		cin >> choice;
		switch(choice){
			case 1:system("mode con:cols=82 lines=25"); system("cls"); Pjari->home();//Ȩ���� ����
			case 2:system("cls");Pjari->jawon();
			default: system("cls"); cout << endl << "\n\t\t��� �̿����ּż� �����մϴ�! ���" << endl << endl << endl << endl; exit(0);
		}
	}