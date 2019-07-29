#include "score.h"
//단어를 보여주고(붉은색) 단어를 입력하면 (맞아도, 틀려도) 다음 단어를 입력할 수 있게 된다.
//'end'입력 | 단어를 10개 입력시  다음 선택항목 출력
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
		cout << "파일이 존재 하지 않습니다!" << endl;
		cout << "input.txt 파일을 생성해 주세요!!" << endl;
		getch();
		system("cls");
		Pjari->home();
	}
	while(!input.eof()){
		input>>line[k];
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
	srand(unsigned (time(0)));
	for(int i=0;i<100;i++){
		coding[i]=line[(rand()%(k-1))];   //코딩 배열 생성
	}
	for(int j=0;j<300;j++){ line[j]="";}

	for(int i=0;i<10;i++){
		cout<<endl<<"\n\t\t■□ 진행사항 : "<<i+1<<"/"<<10<<" 맞춘갯수 : "<<score<<" □■"<<endl;

		for(int j=0;j<7;j++){cout<<endl;}
		cout<<"\t\t\t\t"<<coding[i]<<endl;
		cout<<"\t\t\t\t□□□□□□□□□\t\t"<<endl;
		cout<<"\t\t\t\t        "<<endl;
		for(int j=0;j<9;j++){cout<<endl;}
		cout<<"입력>> ";
		cin>>result;
		if(result.compare(coding[i])==0){             //맞는지 확인
			score++;
			system("cls");
		}
		else if(result=="end"){
			system("cls");
			break;
		}
		else{
			//문자열 복사
			error[i]=coding[i];
			system("cls");
		}
	}
	Pjari->setMaxScore_codingKing(score);
	cout<<endl<<"\n\t\t■□ 현재점수 : "<<score<<"/"<<10<<" 최고점수 : "<<Pjari->getMaxScore_codingKing()<<" □■"<<endl;  //맞춘 갯수
	for(int j=0;j<3;j++){cout<<endl;}
	char * print [6]= {
		"\t\t■■■■■■■■■■■■■■■",
		"\t\t■  \t 1. 홈으로 가기     ■",
		"\t\t■  \t 2. 다시하기        ■",
		"\t\t■  \t 3. 오답노트 확인   ■",
		"\t\t■  \t 너머지. 종료하기   ■",
		"\t\t■■■■■■■■■■■■■■■"
	};

	for(int i=0;i<6;i++){
		cout << print[i]<<endl;
	}
	cout<<"\n\n\t선택  >>  ";
	cin>>choice;
	switch(choice){
		case 1:system("cls"); Pjari->home(); break;
		case 2:system("cls"); Pjari->codingKing(); break;
		case 3:system("cls"); Pjari->odap(error, 10-score); break;
		default: system("cls"); cout << endl << "\n\t\t■□ 이용해주셔서 감사합니다! □■" << endl << endl << endl << endl; exit(0);
	}
}