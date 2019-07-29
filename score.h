#pragma warning (disable : 4996)
#include <iostream>
#include <io.h>
#include <cstring>
#include <iomanip>
#include <conio.h>
#include <iomanip> 
#include<iostream>
#include <iomanip> 
#include<stdlib.h>
#include<fstream>
#include<string>
#include<string.h>
#include<time.h>
#include<winsock2.h>
#include<Windows.h>

using namespace std;
static int maxScore_jari, maxScore_codingKing;
static char * fileNameArray[100];
static int fileName_count=0;
typedef class Jariyeonsup{
public:
	void main();
	void jariyeonsup();
	void codingKing();
	void home();
	void jawon();
	void print_exit();
	void odap(char *error, int num);
	void odap(string *error, int num);
	void fileUpdate();
	static void setMaxScore_jari(int score){
		if(score>maxScore_jari){
			maxScore_jari=score;
		}
	}
	static void setMaxScore_codingKing(int score){
		if(score>maxScore_codingKing){
			maxScore_codingKing=score;
		}
	}
	static int getMaxScore_jari(){
		return maxScore_jari;
	}
	static int getMaxScore_codingKing(){
		return maxScore_codingKing;
	}
	void help();
}Jari;