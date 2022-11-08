#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    Լ���������к����Ⱦͱ����Ȱ������������룬֮��Ͳ��������������ˡ�
*/

struct CourseInfo {
    char courseCode[10];    //�γ̱��
    char courseName[20];    //�γ�����
    char courseType[10];    //�γ����
    int  totalPeriod;       //��ѧʱ
    int  classPeriod;       //�ڿ�ѧʱ
    int  experiPeriod;      //�ϻ�ѧʱ
    float creditHour;      //ѧ��
    int  term;              //����ѧ��
};

struct StuCourInfo {
    int stuNo;              //ѧ�ţ�
    char courseCode[10];    //�γ̱��
};

struct CourseInfo courses[100];
struct StuCourInfo stus[100];

int courseCnt = 0; // ¼��Ŀγ���Ŀ
int stuCnt = 0;    // ¼���ѧ��ѡ����Ŀ

// �������
void go();

// ��ӡ�˵�
void menu();

// ¼������
void input();

// ����γ�����
void browseCourses();

// ��ѯѡ��
void getSelectedCourses();

// ��ѯ�γ���Ϣ
void getCourseInfo();

int main(){
    go();
    return 0;
}

void go(){
    while(true){
        menu();
        printf("�밴�ղ˵���ʾ�������Ĳ�����ţ�\n");
        int choice = 0;
        scanf("%d", &choice);
        if(choice == 0){
            printf("���Ѿ��˳�ϵͳ��\n");
            return;
        }else if(choice == 1){
            input();
        }else if(choice == 2){
            browseCourses();
        }else if(choice == 3){
            getCourseInfo();
        }else if(choice == 4){
            getSelectedCourses();
        }else{
            printf("�������\n");
        }
    }
}

void menu(){
    printf("***ѡ��ϵͳ***\n");
    printf("1-->¼������\n");
    printf("2-->����γ�\n");
    printf("3-->��ѯ�γ�\n");
    printf("4-->��ѯѡ��\n");
    printf("0-->�˳�\n");
}

void input(){
    printf("11-->¼��γ�����\n");
    printf("12-->¼��ѡ������\n");
    printf("������¼������ѡ��11/22����\n");
    int choice = 0;
    scanf("%d", &choice);
    int cnt = 0;
    printf("������¼������������\n");
    scanf("%d", &cnt);
    if(choice == 11){
        courseCnt = cnt;
        printf("��¼��γ���Ϣ����ʽʾ����1 C���� ������� 30 20 10 1 1����\n");
        for(int i = 0; i < cnt; i++){
            scanf("%s", &courses[i].courseCode);
            scanf("%s", &courses[i].courseName);
            scanf("%s", &courses[i].courseType);
            scanf("%d", &courses[i].totalPeriod);
            scanf("%d", &courses[i].classPeriod);
            scanf("%d", &courses[i].experiPeriod);
            scanf("%f", &courses[i].creditHour);
            scanf("%d", &courses[i].term);
        }

        FILE * fp=fopen ("course.txt", "w") ; //���ļ�
        if(NULL==fp)
        {
            printf ("Failed to open the file !\n");
            exit(0);
        }

        for(int i = 0; i < cnt; i++){
            fputs(courses[i].courseCode, fp);
            fputs(" ", fp);
            fputs(courses[i].courseName, fp);
            fputs(" ", fp);
            fputs(courses[i].courseType, fp);
            fputs(" ", fp);

            char strTotalPeriod[10];
            itoa(courses[i].totalPeriod, strTotalPeriod, 10);
            fputs(strTotalPeriod, fp);
            fputs(" ", fp);

            char strClassPeriod[10];
            itoa(courses[i].classPeriod, strClassPeriod, 10);
            fputs(strClassPeriod, fp);
            fputs(" ", fp);

            char strExperiPeriod[10];
            itoa(courses[i].experiPeriod, strExperiPeriod, 10);
            fputs(strExperiPeriod, fp);
            fputs(" ", fp);

            char strCreditHour[10];
            sprintf(strCreditHour, "%.1f", courses[i].creditHour);
            fputs(strCreditHour, fp);
            fputs(" ", fp);

            char strTerm[10];
            itoa(courses[i].term, strTerm, 10);
            fputs(strTerm, fp);
            fputs("\n", fp);
        }
        fclose(fp); //�ر��ļ�
        printf("�����Ѿ�¼����ϣ�\n");
    }else if(choice == 12){
        stuCnt = cnt;
        printf("��¼��ѡ����Ϣ����ʽʾ����201901 1����\n");
        for(int i = 0; i < cnt; i++){
            scanf("%d", &stus[i].stuNo);
            scanf("%s", &stus[i].courseCode);

        }

        FILE * fp=fopen ("student.txt", "w") ; //���ļ�
        if(NULL==fp)
        {
            printf ("Failed to open the file !\n");
            exit(0);
        }

        for(int i = 0; i < cnt; i++){
            char strStuNo[10];
            itoa(stus[i].stuNo, strStuNo, 10);
            fputs(strStuNo, fp);
            fputs(" ", fp);

            fputs(stus[i].courseCode, fp);
            fputs(" ", fp);

            fputs("\n", fp);
        }
        fclose(fp); //�ر��ļ�
        printf("�����Ѿ�¼����ϣ�\n");
    }else{
        printf("�������\n");
    }
    printf("\n");
}

void browseCourses(){
    printf("�γ���Ϣ���£�ÿ����ʾ10�����������������ʾ����");
    FILE * fp=fopen ("course.txt", "r") ; //���ļ�
    if(NULL==fp)
    {
        printf ("Failed to open the file !\n");
        exit(0);
    }

    for(int i = 0; i < courseCnt; i++){
        fscanf(fp, "%s %s %s %d %d %d %f %d\n",
               &courses[i].courseCode,
               &courses[i].courseName,
               &courses[i].courseType,
               &courses[i].totalPeriod,
               &courses[i].classPeriod,
               &courses[i].experiPeriod,
               &courses[i].creditHour,
               &courses[i].term);
    }
    fclose(fp); //�ر��ļ�

    for(int i = 0; i < courseCnt; i++){
        if(i != 0 && (i%10 == 0)){
            printf("�������������������ʾ...\n");
            getchar();
            getchar();
        }
        printf("%s %s %s %d %d %d %f %d\n",
               courses[i].courseCode,
               courses[i].courseName,
               courses[i].courseType,
               courses[i].totalPeriod,
               courses[i].classPeriod,
               courses[i].experiPeriod,
               courses[i].creditHour,
               courses[i].term);
    }
    printf("�����Ѿ�ȫ����ʾ��\n\n");
}

void getSelectedCourses(){
    printf("������γ̺ţ�\n");
    char classCode[10];
    scanf("%s", classCode);
    printf("ѡ�޿γ̺�Ϊ%s��ѧ�����£�\n", classCode);
    FILE * fp=fopen ("student.txt", "r") ; //���ļ�
    if(NULL==fp)
    {
        printf ("Failed to open the file !\n");
        exit(0);
    }
    for(int i = 0; i < stuCnt; i++){
        fscanf(fp, "%d %s\n", &stus[i].stuNo, &stus[i].courseCode);
    }
    fclose(fp); //�ر��ļ�
    for(int i = 0; i < stuCnt; i++){
        if(strcmp(classCode, stus[i].courseCode) == 0){
            printf("%d\n", stus[i].stuNo);
        }
    }
    printf("�����Ѿ�ȫ����ʾ��\n\n");
}

void getCourseInfo(){
    printf("31-->���ݿγ̱�Ų�ѯ�γ�\n");
    printf("32-->���ݿγ����Ʋ�ѯ�γ�\n");
    printf("33-->���ݿγ�����ѯ�γ�\n");
    printf("34-->���ݿ���ѧ�ڲ�ѯ�γ�\n");
    printf("35-->���ݿγ�ѧ�ֲ�ѯ�γ�\n");

    FILE * fp=fopen ("course.txt", "r") ; //���ļ�
    if(NULL==fp)
    {
        printf ("Failed to open the file !\n");
        exit(0);
    }

    for(int i = 0; i < courseCnt; i++){
        fscanf(fp, "%s %s %s %d %d %d %f %d\n",
               &courses[i].courseCode,
               &courses[i].courseName,
               &courses[i].courseType,
               &courses[i].totalPeriod,
               &courses[i].classPeriod,
               &courses[i].experiPeriod,
               &courses[i].creditHour,
               &courses[i].term);
    }
    fclose(fp); //�ر��ļ�

    printf("���������Ĳ�ѯ������ţ�\n");
    int choice = 0;
    scanf("%d", &choice);
    if(choice == 31){
        printf("������γ̱�ţ�\n");
        char courseCode[10];
        scanf("%s", courseCode);
        for(int i = 0; i < courseCnt; i++){
            if(strcmp(courseCode, courses[i].courseCode) == 0){
                printf("%s %s %s %d %d %d %f %d\n",
                   courses[i].courseCode,
                   courses[i].courseName,
                   courses[i].courseType,
                   courses[i].totalPeriod,
                   courses[i].classPeriod,
                   courses[i].experiPeriod,
                   courses[i].creditHour,
                   courses[i].term);
            }
        }
        printf("�����Ѿ�ȫ����ʾ��\n");
    }else if(choice == 32){
        printf("������γ����ƣ�\n");
        char courseName[10];
        scanf("%s", courseName);
        for(int i = 0; i < courseCnt; i++){
            if(strcmp(courseName, courses[i].courseName) == 0){
                printf("%s %s %s %d %d %d %f %d\n",
                   courses[i].courseCode,
                   courses[i].courseName,
                   courses[i].courseType,
                   courses[i].totalPeriod,
                   courses[i].classPeriod,
                   courses[i].experiPeriod,
                   courses[i].creditHour,
                   courses[i].term);
            }
        }
        printf("�����Ѿ�ȫ����ʾ��\n");
    }else if(choice == 33){
        printf("������γ����\n");
        char courseType[10];
        scanf("%s", courseType);
        for(int i = 0; i < courseCnt; i++){
            if(strcmp(courseType, courses[i].courseType) == 0){
                printf("%s %s %s %d %d %d %f %d\n",
                   courses[i].courseCode,
                   courses[i].courseName,
                   courses[i].courseType,
                   courses[i].totalPeriod,
                   courses[i].classPeriod,
                   courses[i].experiPeriod,
                   courses[i].creditHour,
                   courses[i].term);
            }
        }
        printf("�����Ѿ�ȫ����ʾ��\n");
    }else if(choice == 34){
        printf("�����뿪��ѧ�ڣ�\n");
        int term = 0;
        scanf("%d", &term);
        for(int i = 0; i < courseCnt; i++){
            if(term == courses[i].term){
                printf("%s %s %s %d %d %d %f %d\n",
                   courses[i].courseCode,
                   courses[i].courseName,
                   courses[i].courseType,
                   courses[i].totalPeriod,
                   courses[i].classPeriod,
                   courses[i].experiPeriod,
                   courses[i].creditHour,
                   courses[i].term);
            }
        }
        printf("�����Ѿ�ȫ����ʾ��\n");
    }else if(choice == 35){
        printf("������ѧ�֣�\n");
        float creditHour = 0.0;
        scanf("%f", &creditHour);
        for(int i = 0; i < courseCnt; i++){
            if(creditHour == courses[i].creditHour){
                printf("%s %s %s %d %d %d %f %d\n",
                   courses[i].courseCode,
                   courses[i].courseName,
                   courses[i].courseType,
                   courses[i].totalPeriod,
                   courses[i].classPeriod,
                   courses[i].experiPeriod,
                   courses[i].creditHour,
                   courses[i].term);
            }
        }
        printf("�����Ѿ�ȫ����ʾ��\n");
    }else{
        printf("�������\n");
    }
    printf("\n");
}

