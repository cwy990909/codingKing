#include "score.h"
void Jari::odap(char *odap, int num){
	int check = 0;
	Jari * Pjari;
	Pjari=new Jari;
	system("cls");
	cout<<"\t������Ʈ��"<<endl;
	for (int j = 0; j < num; j++) {
		for (int i = 0; i < j; i++) {
			if (odap[i] == odap[j]) check++;
		}
		if (check == 0)  cout << "\t" << odap[j] << endl;
		check = 0;
	}
	getchar();
	cout<<"\t��Ȩ���� ���ư����� 'enter'�� �����ּ���!��";
	getchar();
	system("cls");
	Pjari->home();
}
void Jari::odap(string *odap, int num){
	int check = 0;
	Jari * Pjari;
	Pjari=new Jari;
	system("cls");
	cout<<"\t������Ʈ��"<<endl;
	for (int j = 0; j < num; j++) {
		for (int i = 0; i < j; i++) {
			if (odap[i] == odap[j]) check++;
		}
		if(check==0)  cout << "\t" << odap[j] << endl;
		check = 0;
	}
	getchar();
	cout<<"\t��Ȩ���� ���ư����� 'enter'�� �����ּ���!��";
	getchar();
	system("cls");
	Pjari->home();
}

