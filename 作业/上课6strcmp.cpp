#include<stdio.h>
#include<string.h>

int main(){
	char i[10];
	printf("ÄãÊÇÕæikunÂğ£¿\n");
	scanf("%s",i);
	if(strcmp(i,"¼¦")==0||strcmp(i,"³ª")==0||strcmp(i,"Ìø")==0||strcmp(i,"rap")==0||strcmp(i,"ÀºÇò")==0){
		printf("Äã¸ÉÂï~àËàË°¥Ó´");
	}else{
		printf("¸ç¸çµÄµ°²»¸øÄã³Ô");
	}
	return 0;
}
