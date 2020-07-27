# if 0

#include<iostream>

using namespace std;


//结构体声明
struct Stuent 
{
	string name;
	int age;
	float score;
	void PrintStudent()
	{
		cout << "姓名：" <<name << " 年龄：" << age << " 成绩：" << score << endl;
	}
}s3;

struct Teacher
{
	int id;
	string name;
	Stuent stu_arr[3];
};

//值传递 
void changeSruct1(Stuent s) 
{
	s.name = "奥巴马";
}
//地址传递
void changeStruct2(Stuent* s)
{
	s->name = "普京";
}
// 
void ConstPrint(const Stuent* s)
{
	//常量指针：const 修饰*p  说明指针中的内容是不可以改变的。
	//s->age = 1;
	//不可以调用方法，害怕在方法中改变
	//s->PrintStudent()
	//常量指针是只能读取 值，不能改值
	cout << "------------指针常量------------" << endl;
	cout << s->name << endl;
	;
}
int main()
{
	//结构体定义的三种方式
	//1.
	Stuent s1;
	s1.name = "张三";
	s1.age = 18;
	s1.score = 99;
	s1.PrintStudent();
	//2.
	Stuent s2 = { "李四",19,88 };
	s2.PrintStudent();
	//3.
	s3.name = "王五";
	s3.age = 20;
	s3.score =77;
	s3.PrintStudent();

	cout << "---------------" << endl;

	//结构体数组      类型为结构体的数组，用于保存定义好的结构体
	Stuent stuArray[] = { s1,s2,s3 };
	int len = sizeof(stuArray) / sizeof(stuArray[0]);
	for (int i = 0; i < len; i++)
	{
		stuArray[i].PrintStudent();
	}

	cout << "---------------" << endl;
	//结构体指针
	Stuent* p_stu = &s1;
	p_stu->name = "特朗普";
	p_stu->PrintStudent();

	cout << "---------------" << endl;
	
	//结构体嵌套
	Teacher tea = { 1,"老王",{s1,s2,s3} };


	cout << "---------------" << endl;

	// 结构体的函数调用
	changeSruct1(s1);    //值传递，返回后并没有改变结构体的内容
	s1.PrintStudent();
	changeStruct2(&s1);  //地址传递，改变了结构体的内容
	s1.PrintStudent();



	//结构体的const使用


	ConstPrint(&s1);

}	

#endif