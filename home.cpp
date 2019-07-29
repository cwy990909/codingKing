#include "score.h"
using namespace std;
//모든 메뉴를 보여주고 선택마다 알맞은 함수로 이동해 준다.
void Jari::home(){
	srand((unsigned)time(0));
	Jari * Pjari;
	Pjari=new Jari;
	int choice_1=0;
	
	char *print[16]={
		"\t\t■■■■■■■■■■■■■■■■■■",
		"\t\t■  -----   ------  |  ------  |  ■", 
		"\t\t■       |  |       |       |  |  ■", 
		"\t\t■  -----   ------  |  -----/  |  ■", 
		"\t\t■       |     --          --     ■",
		"\t\t■     |     <    >      <    >   ■",
		"\t\t■  ------    ----        ----    ■",
		"\t\t■                                ■",
		"\t\t■  \t 1. 코딩의 모든 기본      ■",
		"\t\t■  \t 2. 단어를 마스터하자     ■",
		"\t\t■  \t 3. 속도를 높혀봐!        ■",
		"\t\t■  \t 4. 다른 단어를 연습하자! ■",
		"\t\t■  \t 5. 사용법                ■",
		"\t\t■  \t 어떤것. 잘못 들어왔군!   ■",
		"\t\t■                                ■",
		"\t\t■■■■■■■■■■■■■■■■■■\n\n"
	};
	for(int i=0;i<16;i++){
		cout<<print[i]<<endl;
	}
 	cout<<"\t선택(숫자로 입력)  >>  ";
	scanf_s("%d", &choice_1);
	switch (choice_1) {
		case 1: {system("cls"); Pjari->jariyeonsup(); }  //자리연습(jari.cpp)
		case 2: {system("cls"); Pjari->codingKing(); }   //낱말연습(codingking.cpp)
		case 3: {system("cls"); Pjari->jawon(); }        //자원캐기(jawon.cpp)
		case 4: {system("cls"); Pjari->fileUpdate(); }   //파일등록(fileUpdate.cpp)
		case 5: {system("cls"); Pjari->help(); }         //도움말/사용법(help.cpp)
		default: exit(0);
	}
}