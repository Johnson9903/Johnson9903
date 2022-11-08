/********** Begin **********/
#include<stdio.h>

int main(){
    int y,m,d;
    int day;
    scanf("%d-%d-%d",&y,&m,&d);
    if((y%4==0&&y%100!=0)||(y%400==0)){
        switch(m){
        case 1:
            day = d;
            break;
        case 2:
            day = 31+d;
            break;
        case 3:
            day = 31+29+d;
            break;
        case 4:
            day = 31*2+29+d;
            break;
        case 5:
            day = 31*2+29+30+d;
            break;
        case 6:
            day = 31*3+29+30+d;
            break;
        case 7:
            day = 31*3+29+30*2+d;
            break;
        case 8:
            day = 31*4+29+30*2+d;
            break;
        case 9:
            day = 31*4+29+30*3+d;
            break;
        case 10:
            day = 31*5+29+30*3+d;
            break;
        case 11:
            day = 31*5+29+30*4+d;
            break;
        case 12:
            day = 31*6+29+30*4+d;
            break;
        }
        }else{
            switch(m){
        case 1:
            day = d;
            break;
        case 2:
            day = 31+d;
            break;
        case 3:
            day = 31+28+d;
            break;
        case 4:
            day = 31*2+28+d;
            break;
        case 5:
            day = 31*2+28+30+d;
            break;
        case 6:
            day = 31*3+28+30+d;
            break;
        case 7:
            day = 31*3+28+30*2+d;
            break;
        case 8:
            day = 31*4+28+30*2+d;
            break;
        case 9:
            day = 31*4+28+30*3+d;
            break;
        case 10:
            day = 31*5+28+30*3+d;
            break;
        case 11:
            day = 31*5+28+30*4+d;
            break;
        case 12:
            day = 31*6+28+30*4+d;
            break;
        }
        }
        printf("%d",day);
        
    return 0;
}
/********** End **********/
