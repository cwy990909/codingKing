#include "score.h"
using namespace std;
//��� �޴��� �����ְ� ���ø��� �˸��� �Լ��� �̵��� �ش�.
void Jari::home(){
	srand((unsigned)time(0));
	Jari * Pjari;
	Pjari=new Jari;
	int choice_1=0;
	
	char *print[16]={
		"\t\t�������������������",
		"\t\t��  -----   ------  |  ------  |  ��", 
		"\t\t��       |  |       |       |  |  ��", 
		"\t\t��  -----   ------  |  -----/  |  ��", 
		"\t\t��       |     --          --     ��",
		"\t\t��     |     <    >      <    >   ��",
		"\t\t��  ------    ----        ----    ��",
		"\t\t��                                ��",
		"\t\t��  \t 1. �ڵ��� ��� �⺻      ��",
		"\t\t��  \t 2. �ܾ ����������     ��",
		"\t\t��  \t 3. �ӵ��� ������!        ��",
		"\t\t��  \t 4. �ٸ� �ܾ ��������! ��",
		"\t\t��  \t 5. ����                ��",
		"\t\t��  \t ���. �߸� ���Ա�!   ��",
		"\t\t��                                ��",
		"\t\t�������������������\n\n"
	};
	for(int i=0;i<16;i++){
		cout<<print[i]<<endl;
	}
 	cout<<"\t����(���ڷ� �Է�)  >>  ";
	scanf_s("%d", &choice_1);
	switch (choice_1) {
		case 1: {system("cls"); Pjari->jariyeonsup(); }  //�ڸ�����(jari.cpp)
		case 2: {system("cls"); Pjari->codingKing(); }   //��������(codingking.cpp)
		case 3: {system("cls"); Pjari->jawon(); }        //�ڿ�ĳ��(jawon.cpp)
		case 4: {system("cls"); Pjari->fileUpdate(); }   //���ϵ��(fileUpdate.cpp)
		case 5: {system("cls"); Pjari->help(); }         //����/����(help.cpp)
		default: exit(0);
	}
}