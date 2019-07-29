#include "score.h"
void odap(string error[], int num){
	printf("\t**오답빈도수**\n");  //오답 빈도수 top 10으로 만들고 싶음
	for(int i=0;i<num;i++){
		cout<<i<<" : "<<error[i]<<endl;
	}
}