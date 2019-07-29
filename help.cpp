#include "score.h"
//도움말/사용법
void Jari::help() {
	srand((unsigned)time(0));
	Jari * Pjari;
	Pjari = new Jari;

	cout << endl << "\n\t\t■□ 사용법" << " □■" << endl;
	cout << endl << "\t\t1번 : <<특수문자를 연습하는 페이지>>" << endl << endl;
	cout << "\t\t종료를 원하시면 ' '를 입력해주세요!" << endl << endl;

	cout << endl << "\t\t2번 : <<등록한 단어를 연습하는 페이지>>" << endl;
	cout << endl << "\t\t종료를 원하시면 'end'를 입력해주세요!" << endl << endl;

	cout << endl << "\t\t3번 : <<배열된 단어로 입력하는 페이지>>" << endl << endl;
	cout << "\t\t종료를 원하시면 'end'를 입력해주세요!" << endl;
	getch();
	system("cls");
	Pjari->home();
}
