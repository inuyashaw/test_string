/*** 输入一行字符串，找出其中出现的相同且长度最长的字符串，输出它及其首字符的位置 ***/
/*** 例如:"asdfghjas",输出结果为as和1 ***/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str,tmp;
	cout<<"please input the string:";
	cin>>str;

	int i,j;
	for(i=str.length()-1;i>=1;i--)//i>=1，准许相同的长度为1的子字符串(字符)作为输出
		//如果是i>1,则重复出现的字串长度必须大于1
	{
		for(j=0;j<str.length();j++)
		{
			if(i+j<=str.length())
			{
				size_t t=0;
				size_t num=0;
				tmp=str.substr(j,i);//从长到短去截取字串
				t=str.find(tmp);//正序查找子串
				num=str.rfind(tmp);//逆序查找子串
				if(t!=num)//如果两次查找到的位置不一致,说明存在重复
				{
					cout<<tmp<<' '<<t+1<<endl;
					//t+1,find()/rfind()函数的返回值如同数组下标
					return 0;
				}
			}
		}
	}
}
