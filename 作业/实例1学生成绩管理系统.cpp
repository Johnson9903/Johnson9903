#include<stdio.h>
#define CORSE_NUM 6
#define MAX_LEN 10
#define STU_NUM 30

typedef struct Student{
	int Number;
	char Name[4];
	int Score[];
}STU;

void Menu(void);
void IR(STU stu[],int n,int m);
void CTAASOEC(STU stu[],int n,int m);
void CTAASOES(STU stu[],int n,int m);
void SORTBYSCORE(STU stu[],int n,int m,int(*compare)(float a,float b));
int ASCENDING(float a,float b);
int DESCENDING(float a,float b);
void SIDOBNM(STU stu[],int n,int m);
void SBNB(STU stu[],int n,int m);
void SBNM();
void SAFEC();
void LR();
void WTAF();
void RFAF();
void E();

int main(){
	Menu();
	int choice;
	while(1){
	switch (choice) {
		case 1:
			void IR(STU stu,int n,int m);
			break;
		case 2:
			void CTAASOEC(STU stu,int n,int m);
			break;
		case 3:
			void CTAASOES(STU stu,int n,int m);
			break;
		case 4:
			void SORTBYSCORE(STU stu,int n,int m,int ASCENDING);
			break;
		case 5:
			void SORTBYSCORE(STU stu,int n,int m,int DESCENDING);
			break;
		case 6:
			void SIDOBNM(STU stu[],int n,int m);
			break;
		case 7:
			void SBNB();
			break;
		case 8:
			void SBNM();
			break;
		case 9:
			void SAFEC();
			break;
		case 10:
			void LR();
			break;
		case 11:
			void WTAF();
			break;
		case 12:
			void RFAF();
			break;
		case 13:
			void E();
			break;
		default:
			printf("Äã¸ÉÂï~");
			continue;
	}
	}
	return 0;
}

void Menu(){
	printf("1.Input record\n");
	printf("2.Calculate total and average score of every course\n");
	printf("3.Calculate total and average score of every student\n");
	printf("4.Sort in descending order by total scor of every student\n");
	printf("5.Sort in ascending order by total scor of every student\n");
	printf("6.Sort in descending order by number\n");
	printf("7.Sort in descending order by name\n");
	printf("8.Search by number\n");
	printf("9.Search by name\n");
	printf("10.Statistic analysis for every course\n");
	printf("11.List record\n");
	printf("12.Write to a file\n");
	printf("13.Read from a file\n");
	printf("0.Exit\n");
	printf("Please enter your choice:");
}
