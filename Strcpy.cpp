/*** realization the 'strcpy' function ***/
/*** char *strcpy(char* strDest,const char* strSrc); ***/

#include<iostream>
#include<assert.h>
#include<stdio.h>

using namespace std;

char* strcpy(char* strDest,const char*strSrc)
{
	assert((strDest!=NULL) && (strSrc!=NULL));
	char* address=strDest;
	//unsafe! if strSrc`s buffer is bigger than strDest`s 
	while((*strDest++=*strSrc++)!='\0');
	return address;
}

char* strcpy1(char* strDest,const char* strSrc)
{
	assert((strDest!=NULL) && (strSrc!=NULL));
	char*address=strDest;
	while((*strDest!='\0') && (*strSrc!='\0'))
	{
		*strDest++=*strSrc++;
	}
	return address;
}

int main()
{
	char str1[20]="hello world";
	char str2[7]="ni hao";
	strcpy1(str2,str1);
	int i=0;
	for(;i<7;i++)
	{
		printf("%c",str2[i]);
	}
}
