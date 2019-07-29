#include "score.h"
//배열로 단어를 보여주면 그 단어를 입력하여 업애는 함수
//같은 단어가 있을 경우 두개다 사라지지 않게 하기 위해( bool already)배열을 사용하였고, 
//'end' | 단어를 다 맞췄을 경우 다음 선택항목 출력
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
		cout << "파일이 존재 하지 않습니다!" << endl;
		cout << "c://file 경로에 input.txt 파일을 생성해 주세요!!" << endl;
		getch();
		system("cls");
		Pjari->home();
	}
	while (!input.eof()) {
		input >> line[k];
		k++;
	}
	if (k == 1) {
		cout << "\t\t파일이 비어있습니다!!" << endl;
		cout << "\t\t■■■■■■■■■■■■■■■" << endl;
		cout << "\t\t■  \t 1. 홈으로 가기     ■" << endl;
		cout << "\t\t■  \t 2. 등록하러 가기   ■" << endl;
		cout << "\t\t■■■■■■■■■■■■■■■" << endl;
		cout << "\t\t선택 >>";
	Again:
		cin >> choice;
		if (choice == 1) { system("cls"); Pjari->home(); }
		else if (choice == 2) { system("cls"); Pjari->fileUpdate(); }
		else { cout << "존재하지 않는 번호 입니다 >>"; goto  Again; }
	}

	srand(unsigned(time(0)));
	for (int i = 0; i<25; i++) {
		coding[i] = line[(rand() % (k-1))];   //코딩 배열 생성
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
			cout<<"입력 >>";
			cin >> result;
			for(int i=0;i<5;i++){
				for(int j=0;j<5;j++){
					if(result.compare(coding[i*5+j]) == 0 && !already[i*5+j]==1){  //단어가 맞는지, 그 단어가 사라지지 않은 것인지
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
			cout<<"\t\t■□ 진행사항 : "<<score;
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
			"\t\t■■■■■■■■■■■■■■■",
			"\t\t■  \t 1. 홈으로 가기     ■",
			"\t\t■  \t 2. 다시하기        ■",
			"\t\t■  \t 어떤것. 그만하기   ■",
			"\t\t■■■■■■■■■■■■■■■"
		};

		for (int i = 0; i<5; i++) {
			cout << print[i] << endl;
		}
		cout << "\n\n\t선택  >>  ";
		cin >> choice;
		switch(choice){
			case 1:system("mode con:cols=82 lines=25"); system("cls"); Pjari->home();//홈으로 가기
			case 2:system("cls");Pjari->jawon();
			default: system("cls"); cout << endl << "\n\t\t■□ 이용해주셔서 감사합니다! □■" << endl << endl << endl << endl; exit(0);
		}
	}