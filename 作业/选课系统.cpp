#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    约定程序运行后，首先就必须先把所有数据输入，之后就不能再输入数据了。
*/

struct CourseInfo {
    char courseCode[10];    //课程编号
    char courseName[20];    //课程名称
    char courseType[10];    //课程类别
    int  totalPeriod;       //总学时
    int  classPeriod;       //授课学时
    int  experiPeriod;      //上机学时
    float creditHour;      //学分
    int  term;              //开课学期
};

struct StuCourInfo {
    int stuNo;              //学号；
    char courseCode[10];    //课程编号
};

struct CourseInfo courses[100];
struct StuCourInfo stus[100];

int courseCnt = 0; // 录入的课程数目
int stuCnt = 0;    // 录入的学生选课数目

// 程序入口
void go();

// 打印菜单
void menu();

// 录入数据
void input();

// 浏览课程数据
void browseCourses();

// 查询选课
void getSelectedCourses();

// 查询课程信息
void getCourseInfo();

int main(){
    go();
    return 0;
}

void go(){
    while(true){
        menu();
        printf("请按照菜单提示输入您的操作编号：\n");
        int choice = 0;
        scanf("%d", &choice);
        if(choice == 0){
            printf("您已经退出系统！\n");
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
            printf("输入错误！\n");
        }
    }
}

void menu(){
    printf("***选课系统***\n");
    printf("1-->录入数据\n");
    printf("2-->浏览课程\n");
    printf("3-->查询课程\n");
    printf("4-->查询选课\n");
    printf("0-->退出\n");
}

void input(){
    printf("11-->录入课程数据\n");
    printf("12-->录入选课数据\n");
    printf("请输入录入您的选择（11/22）：\n");
    int choice = 0;
    scanf("%d", &choice);
    int cnt = 0;
    printf("请输入录入数据条数：\n");
    scanf("%d", &cnt);
    if(choice == 11){
        courseCnt = cnt;
        printf("请录入课程信息（格式示例：1 C语言 编程语言 30 20 10 1 1）：\n");
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

        FILE * fp=fopen ("course.txt", "w") ; //打开文件
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
        fclose(fp); //关闭文件
        printf("数据已经录入完毕！\n");
    }else if(choice == 12){
        stuCnt = cnt;
        printf("请录入选课信息（格式示例：201901 1）：\n");
        for(int i = 0; i < cnt; i++){
            scanf("%d", &stus[i].stuNo);
            scanf("%s", &stus[i].courseCode);

        }

        FILE * fp=fopen ("student.txt", "w") ; //打开文件
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
        fclose(fp); //关闭文件
        printf("数据已经录入完毕！\n");
    }else{
        printf("输入错误！\n");
    }
    printf("\n");
}

void browseCourses(){
    printf("课程信息如下（每次显示10个，按任意键继续显示）：");
    FILE * fp=fopen ("course.txt", "r") ; //打开文件
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
    fclose(fp); //关闭文件

    for(int i = 0; i < courseCnt; i++){
        if(i != 0 && (i%10 == 0)){
            printf("请输入任意键，继续显示...\n");
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
    printf("数据已经全部显示！\n\n");
}

void getSelectedCourses(){
    printf("请输入课程号：\n");
    char classCode[10];
    scanf("%s", classCode);
    printf("选修课程号为%s的学生如下：\n", classCode);
    FILE * fp=fopen ("student.txt", "r") ; //打开文件
    if(NULL==fp)
    {
        printf ("Failed to open the file !\n");
        exit(0);
    }
    for(int i = 0; i < stuCnt; i++){
        fscanf(fp, "%d %s\n", &stus[i].stuNo, &stus[i].courseCode);
    }
    fclose(fp); //关闭文件
    for(int i = 0; i < stuCnt; i++){
        if(strcmp(classCode, stus[i].courseCode) == 0){
            printf("%d\n", stus[i].stuNo);
        }
    }
    printf("数据已经全部显示！\n\n");
}

void getCourseInfo(){
    printf("31-->根据课程编号查询课程\n");
    printf("32-->根据课程名称查询课程\n");
    printf("33-->根据课程类别查询课程\n");
    printf("34-->根据开课学期查询课程\n");
    printf("35-->根据课程学分查询课程\n");

    FILE * fp=fopen ("course.txt", "r") ; //打开文件
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
    fclose(fp); //关闭文件

    printf("请输入您的查询条件编号：\n");
    int choice = 0;
    scanf("%d", &choice);
    if(choice == 31){
        printf("请输入课程编号：\n");
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
        printf("数据已经全部显示！\n");
    }else if(choice == 32){
        printf("请输入课程名称：\n");
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
        printf("数据已经全部显示！\n");
    }else if(choice == 33){
        printf("请输入课程类别：\n");
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
        printf("数据已经全部显示！\n");
    }else if(choice == 34){
        printf("请输入开课学期：\n");
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
        printf("数据已经全部显示！\n");
    }else if(choice == 35){
        printf("请输入学分：\n");
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
        printf("数据已经全部显示！\n");
    }else{
        printf("输入错误！\n");
    }
    printf("\n");
}

