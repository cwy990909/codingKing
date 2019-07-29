#include "score.h"
//자신이 원하는 단어로 파일을 변경한다. (c://file//keyword)의 경로의 파일을 변경한다.

void Jari::fileUpdate()
{
	Jari * Pjari;
	Pjari = new Jari;

	char result[100];
	FILE *f;
	f = fopen("keyword.txt", "w"); //파일 열기
	if (f == NULL) {
		printf("File error!!");
	}
	else
	{
		int count;
		cout << "몇 글자를 입력하시겠습니까>>";
		cin >> count;
		cout << "글자를 입력해주세요>>\n";
		for (int i = 0; i<count; i++) {
			cin >> result;
			fprintf(f, " %s\t", result);
		}
	}
	fclose(f);
	cout << "등록이 완료되었습니다!!" << endl;
	getchar();
	system("cls");
	Pjari->home();
}
