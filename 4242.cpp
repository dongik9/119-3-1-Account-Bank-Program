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
 
   printf("\n\n\t\t\t\t\t\t\t���� �ð� : %d-%d-%d %d:%d:%d\n",
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
	printf("Store name : %s   Y/M/D : %s   ���� : %s\n",
	Name, Year, Month, Date, Sales );
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
		printf("\t\t\t[1] �����Է�\n\n");		
		printf("\t\t\t[2] ���Ͱ��\n\n");
		printf("\t\t\t[3] ���������\n\n");
		printf("\t\t\t[4] �������ͺ�\n\n");
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
			case 1: //�����Է� 
				yellow();
				time();
				blue();
				printf("\n\t\t****�����Է�****\n\n");
				white();
				printf("Store Name : ");
				scanf("%s", &Name);
				printf("Year : ");
				scanf("%s", &Year);
				printf("Month : ");
				scanf("%s", &Month);
				printf("Date : ");
				scanf("%s", &Date);
				printf("���� : ");
    			scanf("%s", &Sales);
				save();
				printf("\nEnter the number : ");
				scanf("%d", &check);
                break;
			//-------------[2]-------------	
			case 2:{ //���Ͱ�� 
				yellow();
				time();
				blue();
				printf("\n\t\t****���Ͱ��****\n\n"); 
				white();
				
				for(int i=0; i<4; i++){
					printf("%d���� ������ �Է��ϼ��� : ", i+1);
					scanf("%d", &weeksale[i]);
					sum += weeksale[i];
				}
				printf("�̹��� �Ѹ����� %d��\n", sum);
				
				printf("�̹��� �ΰǺ� : ");
				scanf("%d", &labor);
				
				profit = sum - labor;
				printf("�̹��� �������� %d��\n", profit);
				
				char temp[100];
				itoa(profit, temp, 10); // ������ ���ڿ��� ��ȯ 
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
			case 3: //��������� 
				yellow();
				time();
				blue();
				printf("\n\t\t****���������****\n\n");
				white();
				printf("======================================================\n");
				load();
				printf("\nHelloWorld3!!\n\n"); 
				//��������ҷ����� 
				printf("======================================================\n");
				printf("\nEnter the number : ");
				scanf("%d", &check);				
				break; 	
			//-------------[4]-------------
			case 4: //�������ͺ� 
				yellow();
				time();
				blue();
				printf("\n\t\t****�������ͺ�****\n\n");
				white();
				printf("======================================================\n");
				printf("\nHelloWorld4!!\n\n");
				//�������ͺҷ����� 
				printf("======================================================\n");
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
