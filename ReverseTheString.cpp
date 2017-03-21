/*** 字符串reverse，单词倒置，标点符号不倒置 ***/
/*** 例如：i come from beijing. 倒置后变为:beijing. from come i ***/
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int i=0,j=0,begin,end;
	char str[]="i come. from beijing. i love. tom";
	char temp;
	j=strlen(str)-1;
        //字符串全部翻转
	while(j>i)
	{
		temp=str[i];
		str[i++]=str[j];
		str[j--]=temp;
	}
        //单词的部分翻转，这里标点符号都紧跟于单词的后面
	i=0;
	while(str[i])
	{
		if(str[i]!=' ')
		{
			begin=i;
			while(str[i] && str[i]!=' ')//结尾和空格的处理
				i++;//找到空格
			i=i-1;//空格符回退一个
			end=i;
		}
		while(end>begin)
		{
			temp=str[begin];
			str[begin++]=str[end];
			str[end--]=temp;
		}
                i++;
	}
        cout<<str<<endl;
}
