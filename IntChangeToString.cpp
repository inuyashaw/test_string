/*** function:integer changes to string ***/
/*** do not use the 'itoa' function ***/
#include<iostream>

using namespace std;

int main()
{
	int num=21234,i=0,j=0;
	char temp[10]={0},str[10]={0};
	while(num)
	{
		temp[i++]=num%10+'0';
		num/=10;
	}
	temp[i]=0;
	cout<<"temp:"<<temp<<endl;
	i-=1;
	while(i>=0)
	{
		str[j++]=temp[i--];
	}
	str[j]=0;
	cout<<"str:"<<str<<endl;
	return 0;
}
