/*** 实现一个string类 ***/
/*** 在String类的实现的时候，涉及深拷贝和浅拷贝的问题还涉及到如何避免内存泄漏的问题，需要特别注意的是a、如果参数为null，需要分配1个字节的空间 b、在赋值运算符函数中，需要判断是不是赋值给了自己 ***/

#include<iostream>

using namespace std;

class String
{
	public:
		String(const char*str=NULL);//普通构造函数
		String(const String& other);//拷贝构造函数
		String& operator=(const String& other);//赋值运算符函数
		~String(void);//析构函数
	private:
		char* m_data;
};

String::String(const char* str)
{
	if(str==NULL)
	{
		//对空字符串自动申请存放结束标志'\0'的空间，判断m_data是否为NULL(new可能出异常)
		m_data=new char[1];
		if(m_data==NULL)
		{
			printf("new error\n");
			return -1;
		}
		*m_data='\0';
	}
	else
	{
		m_data=new char[strlen(str)+1];
		if(m_data==NULL)
		{
			printf("new error\n");
			return -1;
		}

		strcpy(m_data,str);
	}
}

String::String(const String& other)//拷贝构造，注意const 引用
{
	m_data=new char[strlen(other.m_data)+1];
	if(m_data==NULL)
	{
		printf("new error\n");
		return -1;
	}

	strcpy(m_data,other.m_data);
}

String& String::operator=(const String& other)//赋值运算符函数，注意const 引用
{
	//检查自赋值
	if(this==&other)
		return *this;
	//释放已有内存
	delete [] m_data;
	m_data=new char[strlen(other.m_data)+1];
	if(m_data==NULL)
	{
		printf("new error\n");
		return -1;
	}

	strcpy(m_data,other.m_data);
	return *this;
}

String::String(void)
{
	delete [] m_data;
}
