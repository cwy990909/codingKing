#include "score.h"
//�� ���ھ� �����ָ� getch()�� ���ؼ� �Է¹޴´�.
//�Է½� ���� ���ڷ� �Ѿ��. ' ' | 10���� �Է����� �� ���� �����׸� ���
void Jari::jariyeonsup(){
	srand((unsigned)time(0));
	Jari * Pjari;
	Pjari=new Jari;
	char b[104]={' '};
	char error[100]={' '};
	b[0]=' ';
	b[1]=' ';
	b[102]=' ';
	b[103]=' ';
	int score=0;
	srand(unsigned (time(0)));
	for(int i=0;i<10;i++){
		b[i+2]=33+(rand()%90);   //�ڵ� �迭 ����
	}
	for(int i=2;i<12;i++)
	{
		cout<<endl<<"\n\t\t��� ������� : "<<i-1<<"/"<<10<<" ���᰹�� : "<<score<<" ���"<<endl;
		for(int j=0;j<5;j++){cout<<endl;}
		cout<<"\t\t����\t����\t ������\t����\t����"<<endl;
		cout<<"\t\t\t\t\t "<<endl;
		cout<<"\t\t  "<<b[i-2]<<"\t  "<<b[i-1]<<"\t      ";
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12 );   //���� ����
		cout<<b[i];															//�ܾ� ���
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 15);   
		cout<<"   \t  "<<b[i+1]<<"\t   "<<b[i+2]<<endl;
		cout<<"\t\t\t\t\t "<<endl;
		cout<<"\t\t����\t����\t ������\t����\t����"<<endl;
		cout<<"\t\t\t\t     ��"<<endl;
		for(int j=0;j<9;j++){cout<<endl;}
		cout<<"�Է�>> ";
		char result; result=getch();  //�ܾ� �Է�
		if(result==b[i]){             //�´��� Ȯ��
			++score;
			system("cls");
		}
		else if(result==' '){
			system("cls");
			break;
		}
		else{
			error[i-2]=b[i];
			system("cls");
		}
	}
	Pjari->setMaxScore_jari(score);
	int choice;

	cout<<endl<<"\n\t\t��� �������� : "<<score<<"/"<<10<<" �ְ����� : "<<Pjari->getMaxScore_jari()<<" ���"<<endl;  //���� ����
	for(int j=0;j<5;j++){cout<<endl;}
	char * print [6]= {
		"\t\t����������������",
		"\t\t��  \t 1. Ȩ���� ����     ��",
		"\t\t��  \t 2. �ٽ��ϱ�        ��",
		"\t\t��  \t 3. �����Ʈ Ȯ��   ��",
		"\t\t��  \t ���. �׸��ϱ�   ��",
		"\t\t����������������"
	};

	for(int i=0;i<6;i++){
		cout << print[i]<<endl;
	}
	cout<<"\n\n\t����  >>  ";
	cin>>choice;
	switch(choice){
		case 1:system("cls"); Pjari->home(); break;
		case 2:system("cls"); Pjari->jariyeonsup(); break;
		case 3:system("cls"); Pjari->odap(error, 10-score); break;
		default: system("cls"); cout << endl << "\n\t\t��� �̿����ּż� �����մϴ�! ���" << endl << endl << endl << endl; exit(0);
	}
}