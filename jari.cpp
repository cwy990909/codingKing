#include "score.h"
//한 문자씩 보여주면 getch()를 통해서 입력받는다.
//입력시 다음 문자로 넘어간다. ' ' | 10개를 입력했을 시 다음 선택항목 출력
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
		b[i+2]=33+(rand()%90);   //코딩 배열 생성
	}
	for(int i=2;i<12;i++)
	{
		cout<<endl<<"\n\t\t■□ 진행사항 : "<<i-1<<"/"<<10<<" 맞춘갯수 : "<<score<<" □■"<<endl;
		for(int j=0;j<5;j++){cout<<endl;}
		cout<<"\t\t■■■\t■■■\t □□□□□\t■■■\t■■■"<<endl;
		cout<<"\t\t\t\t\t "<<endl;
		cout<<"\t\t  "<<b[i-2]<<"\t  "<<b[i-1]<<"\t      ";
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 12 );   //색상 변경
		cout<<b[i];															//단어 출력
		SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 15);   
		cout<<"   \t  "<<b[i+1]<<"\t   "<<b[i+2]<<endl;
		cout<<"\t\t\t\t\t "<<endl;
		cout<<"\t\t■■■\t■■■\t □□□□□\t■■■\t■■■"<<endl;
		cout<<"\t\t\t\t     ↑"<<endl;
		for(int j=0;j<9;j++){cout<<endl;}
		cout<<"입력>> ";
		char result; result=getch();  //단어 입력
		if(result==b[i]){             //맞는지 확인
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

	cout<<endl<<"\n\t\t■□ 현재점수 : "<<score<<"/"<<10<<" 최고점수 : "<<Pjari->getMaxScore_jari()<<" □■"<<endl;  //맞춘 갯수
	for(int j=0;j<5;j++){cout<<endl;}
	char * print [6]= {
		"\t\t■■■■■■■■■■■■■■■",
		"\t\t■  \t 1. 홈으로 가기     ■",
		"\t\t■  \t 2. 다시하기        ■",
		"\t\t■  \t 3. 오답노트 확인   ■",
		"\t\t■  \t 어떤것. 그만하기   ■",
		"\t\t■■■■■■■■■■■■■■■"
	};

	for(int i=0;i<6;i++){
		cout << print[i]<<endl;
	}
	cout<<"\n\n\t선택  >>  ";
	cin>>choice;
	switch(choice){
		case 1:system("cls"); Pjari->home(); break;
		case 2:system("cls"); Pjari->jariyeonsup(); break;
		case 3:system("cls"); Pjari->odap(error, 10-score); break;
		default: system("cls"); cout << endl << "\n\t\t■□ 이용해주셔서 감사합니다! □■" << endl << endl << endl << endl; exit(0);
	}
}