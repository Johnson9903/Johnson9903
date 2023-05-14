#include <stdio.h>
#include <string.h>

/* 返回第1个重复出现两次的字符 */
char findFirstRepeat(char* pStr);

int main(void)
{
    char str[501], c;
    int i = 0;
    while ((c = getchar()) != '\n')
        str[i++] = c;
    str[i] = '\0';
    c = findFirstRepeat(str);
    putchar(c);
    return 0;
}
//**************begin********************
char findFirstRepeat(char* pStr){
    for(int i = 1;i<strlen(pStr);i++)
    {
        for(int j = 0;j<i;j++)
        {
            if(pStr[i] == pStr[j])
            {
                return pStr[i];
            }
        }
    }
    return '\n';
}
//*************end*************************
