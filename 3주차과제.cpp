#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>



void green(){	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
void purple(){ 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
void yellow(){	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}
void blue(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
void white(){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void time(){
	
  	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
 
   printf("\n\t\t\t\t\t\t\t현재 시간 : %d-%d-%d %d:%d:%d\n",
         tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
         tm.tm_hour, tm.tm_min, tm.tm_sec);
 
}


// 1. 매출입력칸 2.순익계산칸 3. 월별메출비교 4. 월별순익비교
int main(){
	yellow();
	time();
	blue();
	printf("\n\t\tWelcome to Account Book Program\n\n");
	purple();
	printf("***자영업자들을 위한 가계부 프로그램\n");
	printf("***매출과 순익 관리 프로그램\n\n");
	white();
	printf("\t\t\t\t***MAIN MENU***\n\n");
	printf("\t\t================================================\n\n");
	printf("\t\t\t[1] 매출입력\n\n");		
	printf("\t\t\t[2] 순익계산\n\n");
	printf("\t\t\t[3] 월별매출비교\n\n");
	printf("\t\t\t[4] 월별순익비교\n\n");
	printf("\t\t\t[5] 종료\n\n");
	printf("\t\t================================================\n\n");
	
	
	
#define UP 72
#define DOWN 80
#define ENTER 13

int key;
int menuNum=1; //menuNum -> 1 ~ 5
	
		key = getch();
		if(key==224){
			key = getch(); //224값 버림 
		}
		if(key == UP){ //위 방향키 
			if(menuNum>1){ menuNum--; } 
		} else if(key == DOWN){ //아래 방향키
			if(menuNum<5){ menuNum++; } 
		} else if(key == ENTER) {
			switch (menuNum){
				case 1: //select user
					system("cls");
					printf("HelloWorld1!!"); 
					break;
				case 2: //statistics
					system("cls"); //화면 지우기 
					printf("HelloWorld2!!"); 
					break;
				case 3: //view user records
					system("cls");
					printf("HelloWorld3!!"); 
					break;
				case 4: //about
					system("cls"); 
					printf("HelloWorld4!!"); 
					while (!kbhit()); //키 입력 대기 
					fflush(stdin);
					menuNum = 1;
					break;
				case 5: //quit
					system("cls"); //화면 지우기 
					printf("종료");
					exit(0);
					break;
				    }
			}
	
	
	
	return 0;
}
