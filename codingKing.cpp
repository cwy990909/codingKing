#include "score.h"
//�ܾ �����ְ�(������) �ܾ �Է��ϸ� (�¾Ƶ�, Ʋ����) ���� �ܾ �Է��� �� �ְ� �ȴ�.
//'end'�Է� | �ܾ 10�� �Է½�  ���� �����׸� ���
void Jari::codingKing(){
	srand((unsigned)time(0));
	Jari * Pjari;
	Pjari=new Jari;
	int score=0;
	int k=0;
	string result="";
	string error[100]={" "};
	string coding[100]={" "};
	string line[300];
	int choice;
	
	ifstream input("keyword.txt");
	if (input.fail()) {
		cout << "������ ���� ���� �ʽ��ϴ�!" << endl;
		cout << "input.txt ������ ������ �ּ���!!" << endl;
		getch();
		system("cls");
		Pjari->home();
	}
	while(!input.eof()){
		input>>line[k];
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
	srand(unsigned (time(0)));
	for(int i=0;i<100;i++){
		coding[i]=line[(rand()%(k-1))];   //�ڵ� �迭 ����
	}
	for(int j=0;j<300;j++){ line[j]="";}

	for(int i=0;i<10;i++){
		cout<<endl<<"\n\t\t��� ������� : "<<i+1<<"/"<<10<<" ���᰹�� : "<<score<<" ���"<<endl;

		for(int j=0;j<7;j++){cout<<endl;}
		cout<<"\t\t\t\t"<<coding[i]<<endl;
		cout<<"\t\t\t\t����������\t\t"<<endl;
		cout<<"\t\t\t\t        "<<endl;
		for(int j=0;j<9;j++){cout<<endl;}
		cout<<"�Է�>> ";
		cin>>result;
		if(result.compare(coding[i])==0){             //�´��� Ȯ��
			score++;
			system("cls");
		}
		else if(result=="end"){
			system("cls");
			break;
		}
		else{
			//���ڿ� ����
			error[i]=coding[i];
			system("cls");
		}
	}
	Pjari->setMaxScore_codingKing(score);
	cout<<endl<<"\n\t\t��� �������� : "<<score<<"/"<<10<<" �ְ����� : "<<Pjari->getMaxScore_codingKing()<<" ���"<<endl;  //���� ����
	for(int j=0;j<3;j++){cout<<endl;}
	char * print [6]= {
		"\t\t����������������",
		"\t\t��  \t 1. Ȩ���� ����     ��",
		"\t\t��  \t 2. �ٽ��ϱ�        ��",
		"\t\t��  \t 3. �����Ʈ Ȯ��   ��",
		"\t\t��  \t �ʸ���. �����ϱ�   ��",
		"\t\t����������������"
	};

	for(int i=0;i<6;i++){
		cout << print[i]<<endl;
	}
	cout<<"\n\n\t����  >>  ";
	cin>>choice;
	switch(choice){
		case 1:system("cls"); Pjari->home(); break;
		case 2:system("cls"); Pjari->codingKing(); break;
		case 3:system("cls"); Pjari->odap(error, 10-score); break;
		default: system("cls"); cout << endl << "\n\t\t��� �̿����ּż� �����մϴ�! ���" << endl << endl << endl << endl; exit(0);
	}
}