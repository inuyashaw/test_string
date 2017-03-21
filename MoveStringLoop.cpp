/*** 编写一个函数，作用是把一个char组成的字符串循环右移n个 ***/
/*** 例如“abcdefg”，n=2，移位后应该是“fgabcde” ***/

#include<iostream>
#include<string.h>
#ifndef MAX_LEN 
#define MAX_LEN 1024
#endif

using namespace std;

void LoopMove(char* pStr,int n)
{
char temp[MAX_LEN]={0};
strcpy(temp,pStr+(strlen(pStr)-n));
strcpy(temp+n,pStr);
*(temp+strlen(pStr))='\0';
strcpy(pStr,temp);
}


int main(int argc,char*argv[])
{
 char buf[20]="dsfjkhsdl";
cout<<buf<<endl;
 LoopMove(buf,4);
 cout<<buf<<endl;

 return 0;
}
