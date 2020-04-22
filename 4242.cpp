#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int menu_num;
int check=0;
char Name[100];
char Year[100];
char Month[100];
char Date[100];
char Sales[100];


int weeksale[4];
int labor, profit=0, sum=0;

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
 
   printf("\n\n\t\t\t\t\t\t\t현재 시간 : %d-%d-%d %d:%d:%d\n",
         tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday,
         tm.tm_hour, tm.tm_min, tm.tm_sec);
 
}
void save(){
	FILE *fp =NULL;	        
	fp=fopen("sales.txt","a");
	fprintf(fp,"%s %s-%s-%s %s\n", &Name, &Year, &Month, &Date, &Sales); 			
	fclose(fp); 
}
void load(){
	FILE *fp2 =NULL; 
	fp2=fopen("sales.txt", "r");
	fscanf(fp2,"%s %s %s %s %s", &Name, &Year, &Month, &Date, &Sales);
	printf("Store name : %s   Y/M/D : %s   매출 : %s\n",
	Name, Year, Month, Date, Sales );
}
// 1. 매출입력칸 2.순익계산칸 3. 월별메출비교 4. 월별순익비교
int main(){
	
	do{	
		system( "cls" );
		yellow();
		time();
		blue();
		printf("\n\t\t\tWelcome to Account Book Program\n\n");
		purple();
		printf("***자영업자들을 위한 가계부 프로그램\n");
		printf("***매출과 순익 관리 프로그램\n\n");
		yellow();
		printf("\t\t\t\t***MAIN MENU***\n\n");
		printf("\t\t===================================================\n\n");
		printf("\t\t\t[1] 매출입력\n\n");		
		printf("\t\t\t[2] 순익계산\n\n");
		printf("\t\t\t[3] 월별매출비교\n\n");
		printf("\t\t\t[4] 월별순익비교\n\n");
		printf("\t\t\t[5] 종료\n\n");
		printf("\t\t===================================================\n");
		green();
		printf("\t\t\t\t\tMade By dongik9 & Choi-gunwoo\n\n");
		white();
		printf("Enter the number : ");
		scanf("%d", &menu_num); 
		
	
		system( "cls" ); //화면 지우기 
		switch (menu_num){
			//-------------[1]-------------
			case 1: //매출입력 
				yellow();
				time();
				blue();
				printf("\n\t\t****매출입력****\n\n");
				white();
				printf("Store Name : ");
				scanf("%s", &Name);
				printf("Year : ");
				scanf("%s", &Year);
				printf("Month : ");
				scanf("%s", &Month);
				printf("Date : ");
				scanf("%s", &Date);
				printf("매출 : ");
    			scanf("%s", &Sales);
				save();
				printf("\nEnter the number : ");
				scanf("%d", &check);
                break;
			//-------------[2]-------------	
			case 2:{ //순익계산 
				yellow();
				time();
				blue();
				printf("\n\t\t****순익계산****\n\n"); 
				white();
				
				for(int i=0; i<4; i++){
					printf("%d주차 매출을 입력하세요 : ", i+1);
					scanf("%d", &weeksale[i]);
					sum += weeksale[i];
				}
				printf("이번달 총매출은 %d원\n", sum);
				
				printf("이번달 인건비 : ");
				scanf("%d", &labor);
				
				profit = sum - labor;
				printf("이번달 순수익은 %d원\n", profit);
				
				char temp[100];
				itoa(profit, temp, 10); // 정수를 문자열로 변환 
				printf("%s", temp);
				
				FILE *fp2 =NULL;	        
				fp2=fopen("sales.txt","a");
				fprintf(fp2,"%s \n", &temp);			
				fclose(fp2); 
				
				printf("\nHelloWorld2!!\n"); 
				printf("\nEnter the number : ");
				scanf("%d", &check);	
				break;	
			}
			//-------------[3]-------------	 
			case 3: //월별매출비교 
				yellow();
				time();
				blue();
				printf("\n\t\t****월별매출비교****\n\n");
				white();
				printf("======================================================\n");
				load();
				printf("\nHelloWorld3!!\n\n"); 
				//월별매출불러오기 
				printf("======================================================\n");
				printf("\nEnter the number : ");
				scanf("%d", &check);				
				break; 	
			//-------------[4]-------------
			case 4: //월별순익비교 
				yellow();
				time();
				blue();
				printf("\n\t\t****월별수익비교****\n\n");
				white();
				printf("======================================================\n");
				printf("\nHelloWorld4!!\n\n");
				//월별순익불러오기 
				printf("======================================================\n");
				printf("\nEnter the number : ");
				scanf("%d", &check);	
				break;			 
			//-------------[5]-------------
			case 5: //종료 
				yellow();
				printf("\n\n\t\t종료합니다.\n\n");
				white();
				exit(0);
				break;
				}
	} while (menu_num != -1);
	 
	
	return 0;
}
