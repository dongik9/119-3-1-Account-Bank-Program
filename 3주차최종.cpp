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
 
   printf("\n\n\t\t\t\t\t\t\t���� �ð� : %d-%d-%d %d:%d:%d\n",
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
				itoa(sum, temp1, 10); // ������ ���ڿ��� ��ȯ
				
				FILE *fp3 = NULL;	        
				fp3=fopen("totalsales.txt","a");
				fprintf(fp3,"Store Name : %s\t Y_M : %sY_%sM\t TotalSales : %s����\n", &name2, &year2, &month2, &temp1);			
				fclose(fp3);
}
void save3(){
	char temp2[100];
				itoa(profit, temp2, 10); // ������ ���ڿ��� ��ȯ 
				
				FILE *fp4 =NULL;	        
				fp4=fopen("profit.txt","a");
				fprintf(fp4,"Store Name : %s\t Y_M : %sY_%sM\t Profit : %s����\n", &name2, &year2, &month2, &temp2);			
				fclose(fp4);
}

void load(){//1�� �޴��� ���õ�, �ð������� �޴� �߰��� ���� 1����µǰԸ���� 
	
	FILE *fp2 =NULL; 
	fp2=fopen("sales_today.txt", "r");
	fscanf(fp2,"%s %s %s %s %s", &name, &year, &month, &date, &sales);
	while (EOF!= fscanf(fp2,"%s %s %s %s %s \n", &name, &year, &month, &date, &sales)) // ���� ���������� �б� 
			{	
				printf("Store name : %s\tY/M/D : %s/%s/%s\t���� : %s\n",
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
					} //���� ���� �ҷ����� 
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
					} //���� ���� �ҷ����� 
				fclose(fp6);
}
// 1. �����Է�ĭ 2.���Ͱ��ĭ 3. ��������� 4. �������ͺ�
int main(){
	
	do{	
		system( "cls" );
		yellow();
		time();
		blue();
		printf("\n\t\t\tWelcome to Account Book Program\n\n");
		purple();
		printf("***�ڿ����ڵ��� ���� ����� ���α׷�\n");
		printf("***����� ���� ���� ���α׷�\n\n");
		yellow();
		printf("\t\t\t\t***MAIN MENU***\n\n");
		printf("\t\t===================================================\n\n");
		printf("\t\t\t[1] ������ ���� �Է�\n\n");		
		printf("\t\t\t[2] ���� �� ���� ���\n\n"); 
		printf("\t\t\t[3] ���� ���� ��\n\n");
		printf("\t\t\t[4] ���� ���� ��\n\n");
		printf("\t\t\t[5] ����\n\n");
		printf("\t\t===================================================\n");
		green();
		printf("\t\t\t\t\tMade By dongik9 & Choi-gunwoo\n\n");
		white();
		printf("Enter the number : ");
		scanf("%d", &menu_num); 
		
	
		system( "cls" ); //ȭ�� ����� 
		switch (menu_num){
			//-------------[1]-------------
			case 1: //�����Է�, ��ȣ �߰��Ͽ� 1���� ����� �� �� �ִ� �޴� ���� 
				yellow();
				time();
				blue();
				printf("\n\t\t****������ ���� �Է�****\n\n");
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
				printf("���� : ");
    			scanf("%s", &sales);
				save();
				printf("============================================================\n");	
				printf("\nEnter the number : ");
				scanf("%d", &check);
                break;
			//-------------[2]-------------	
			case 2: //����׼��Ͱ�� 
				
				yellow();
				time();
				blue();
				printf("\n\t\t****���� �� ���� ���****\n\n"); 
				white();
				printf("=============================================================\n");
				purple();
				printf("  ****����׼��Ͱ�꿡���� ��� ������ �����Դϴ�.****\n\n");
				white();
				green();
				printf("\t\t(0) �⺻����\n\n");
				white();
				printf("Store Name : ");
				scanf("%s", &name2);
				printf("Year : ");
				scanf("%s", &year2);
				printf("Month : ");
				scanf("%s", &month2);
				printf("���� %s�� %s�� %s�� ����׼��� ����� �����մϴ�.\n\n", name2, year2, month2);
				 
				green();
				printf("\t\t(1) ������\n\n"); 
				white();
				for(int i=0; i<4; i++){
					printf("%d���� ������ �Է��ϼ��� : ", i+1);
					scanf("%d", &weeksale[i]);
					sum += weeksale[i];
				}
				printf("\n�̹��� �Ѹ����� %d����\n\n", sum);
				save2();
				
				green();
				printf("\t\t(2) ���Ͱ��\n\n"); 
				white();
				printf("�̹��� �ΰǺ� : ");
				scanf("%d", &labor);
				printf("�̹��� ������ : ");
				scanf("%d", &manage);
				profit = sum - labor - manage;
				printf("\n�̹��� �������� %d����\n\n", profit);
				save3();
				printf("=============================================================\n");
				printf("\nEnter the number : ");
				scanf("%d", &check);	
				break;	
			//-------------[3]-------------	 
			case 3: //��������� 
				yellow();
				time();
				blue();
				printf("\n\t\t****���� ���� ��****\n\n");
				white();
				printf("=======================================================================\n");
				load2();
				printf("=======================================================================\n");
				printf("\nEnter the number : ");
				scanf("%d", &check);				
				break; 	
			//-------------[4]-------------
			case 4: //�������ͺ� 
				yellow();
				time();
				blue();
				printf("\n\t\t****���� ���� ��****\n\n");
				white();
				printf("=======================================================================\n");
				load3(); 
				printf("=======================================================================\n");
				printf("\nEnter the number : ");
				scanf("%d", &check);	
				break;			 
			//-------------[5]-------------
			case 5: //���� 
				yellow();
				printf("\n\n\t\t�����մϴ�.\n\n");
				white();
				exit(0);
				break;
				}
	} while (menu_num != -1);
	 
	
	return 0;
}
