#include "score.h"
void odap(string error[], int num){
	printf("\t**����󵵼�**\n");  //���� �󵵼� top 10���� ����� ����
	for(int i=0;i<num;i++){
		cout<<i<<" : "<<error[i]<<endl;
	}
}