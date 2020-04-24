#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

int menu_num;
int check=0;
char name[100];
char year[100];
char month[100];
char name2[100];
char year2[100];
char month2[100];
char date[100];
char sales[100];
int weeksale[4];
int labor, manage, profit=0, sum=0;

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
				fp=fopen("sales_today.txt","a");
				fprintf(fp,"%s %s %s %s %s\n", &name, &year, &month, &date, &sales); 	 			
				fclose(fp); 
}
void save2(){
	char temp1[100];
				itoa(sum, temp1, 10); // 정수를 문자열로 변환
				
				FILE *fp3 = NULL;	        
				fp3=fopen("totalsales.txt","a");
				fprintf(fp3,"Store Name : %s\t Y_M : %sY_%sM\t TotalSales : %s만원\n", &name2, &year2, &month2, &temp1);			
				fclose(fp3);
}
void save3(){
	char temp2[100];
				itoa(profit, temp2, 10); // 정수를 문자열로 변환 
				
				FILE *fp4 =NULL;	        
				fp4=fopen("profit.txt","a");
				fprintf(fp4,"Store Name : %s\t Y_M : %sY_%sM\t Profit : %s만원\n", &name2, &year2, &month2, &temp2);			
				fclose(fp4);
}

void load(){//1번 메뉴와 관련됨, 시간남으면 메뉴 추가로 만들어서 1번출력되게만들기 
	
	FILE *fp2 =NULL; 
	fp2=fopen("sales_today.txt", "r");
	fscanf(fp2,"%s %s %s %s %s", &name, &year, &month, &date, &sales);
	while (EOF!= fscanf(fp2,"%s %s %s %s %s \n", &name, &year, &month, &date, &sales)) // 파일 마지막까지 읽기 
			{	
				printf("Store name : %s\tY/M/D : %s/%s/%s\t매출 : %s\n",
					&name, &year, &month, &date, &sales);

			}
}
void load2(){
			FILE *fp5 = NULL;
				fp5 = fopen("totalsales.txt", "r");
				char buffer[100];
				int count = 1;
				
				while(fgets(buffer, 100, fp5) != NULL){
					printf("%s\n", &buffer);
					count++;
					} //월별 매출 불러오기 
				fclose(fp5);	
}
void load3(){
			FILE *fp6 = NULL;
				fp6 = fopen("profit.txt", "r");
				char buffer[100];
				int count = 1;
				
				while(fgets(buffer, 100, fp6) != NULL){
					printf("%s\n", &buffer);
					count++;
					} //월별 순익 불러오기 
				fclose(fp6);
}
// 1. 매출입력칸 2.순익계산칸 3. 월별매출비교 4. 월별순익비교
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
		printf("\t\t\t[1] 오늘의 매출 입력\n\n");		
		printf("\t\t\t[2] 매출 및 순익 계산\n\n"); 
		printf("\t\t\t[3] 월별 매출 비교\n\n");
		printf("\t\t\t[4] 월별 순익 비교\n\n");
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
			case 1: //매출입력, 번호 추가하여 1번의 결과만 볼 수 있는 메뉴 제작 
				yellow();
				time();
				blue();
				printf("\n\t\t****오늘의 매출 입력****\n\n");
				white();	
				printf("============================================================\n");
				printf("Store Name : ");
				scanf("%s", &name);
				printf("Year : ");
				scanf("%s", &year);
				printf("Month : ");
				scanf("%s", &month);
				printf("Date : ");
				scanf("%s", &date);
				printf("매출 : ");
    			scanf("%s", &sales);
				save();
				printf("============================================================\n");	
				printf("\nEnter the number : ");
				scanf("%d", &check);
                break;
			//-------------[2]-------------	
			case 2: //매출및순익계산 
				
				yellow();
				time();
				blue();
				printf("\n\t\t****매출 및 순익 계산****\n\n"); 
				white();
				printf("=============================================================\n");
				purple();
				printf("  ****매출및순익계산에서의 모든 단위는 만원입니다.****\n\n");
				white();
				green();
				printf("\t\t(0) 기본정보\n\n");
				white();
				printf("Store Name : ");
				scanf("%s", &name2);
				printf("Year : ");
				scanf("%s", &year2);
				printf("Month : ");
				scanf("%s", &month2);
				printf("상점 %s의 %s년 %s월 매출및순익 계산을 시작합니다.\n\n", name2, year2, month2);
				 
				green();
				printf("\t\t(1) 매출계산\n\n"); 
				white();
				for(int i=0; i<4; i++){
					printf("%d주차 매출을 입력하세요 : ", i+1);
					scanf("%d", &weeksale[i]);
					sum += weeksale[i];
				}
				printf("\n이번달 총매출은 %d만원\n\n", sum);
				save2();
				
				green();
				printf("\t\t(2) 순익계산\n\n"); 
				white();
				printf("이번달 인건비 : ");
				scanf("%d", &labor);
				printf("이번달 관리비 : ");
				scanf("%d", &manage);
				profit = sum - labor - manage;
				printf("\n이번달 순수익은 %d만원\n\n", profit);
				save3();
				printf("=============================================================\n");
				printf("\nEnter the number : ");
				scanf("%d", &check);	
				break;	
			//-------------[3]-------------	 
			case 3: //월별매출비교 
				yellow();
				time();
				blue();
				printf("\n\t\t****월별 매출 비교****\n\n");
				white();
				printf("=======================================================================\n");
				load2();
				printf("=======================================================================\n");
				printf("\nEnter the number : ");
				scanf("%d", &check);				
				break; 	
			//-------------[4]-------------
			case 4: //월별순익비교 
				yellow();
				time();
				blue();
				printf("\n\t\t****월별 순익 비교****\n\n");
				white();
				printf("=======================================================================\n");
				load3(); 
				printf("=======================================================================\n");
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
