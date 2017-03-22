/*** 编写一个方法，实现基本的字符串压缩功能 ***/
/*** 例如:字符串“aabcccaaa“，压缩后”a2b1c3a3“ ***/
/*** 若压缩后的字符串没有变短，则返回原先的字符串 ***/
#include<iostream>
#include<string>

using namespace std;

string ZipString(string src)
{
	string temp;
	auto begin=src.begin();
	while(begin!=src.end())//string::end()指向的是最后一个字符的后一位
	{
		auto ahead=begin+1;
		while(ahead!=src.end() && *ahead==*begin)
			ahead++;
		temp.push_back(*begin);//string::push_back()，栈的处理方式，先进后出
		temp+=to_string(ahead-begin);//to_string()把数字类型变为相应的字符串
		begin=ahead;
	}
	return temp.size()<src.size()?temp:src;
}

int main()
{
	string src="fsdsssssaaakk";
	string des=ZipString(src);
	cout<< des<<endl;

	return 0;
}
