# if 0

#include<iostream>

using namespace std;


//�ṹ������
struct Stuent 
{
	string name;
	int age;
	float score;
	void PrintStudent()
	{
		cout << "������" <<name << " ���䣺" << age << " �ɼ���" << score << endl;
	}
}s3;

struct Teacher
{
	int id;
	string name;
	Stuent stu_arr[3];
};

//ֵ���� 
void changeSruct1(Stuent s) 
{
	s.name = "�°���";
}
//��ַ����
void changeStruct2(Stuent* s)
{
	s->name = "�վ�";
}
// 
void ConstPrint(const Stuent* s)
{
	//����ָ�룺const ����*p  ˵��ָ���е������ǲ����Ըı�ġ�
	//s->age = 1;
	//�����Ե��÷����������ڷ����иı�
	//s->PrintStudent()
	//����ָ����ֻ�ܶ�ȡ ֵ�����ܸ�ֵ
	cout << "------------ָ�볣��------------" << endl;
	cout << s->name << endl;
	;
}
int main()
{
	//�ṹ�嶨������ַ�ʽ
	//1.
	Stuent s1;
	s1.name = "����";
	s1.age = 18;
	s1.score = 99;
	s1.PrintStudent();
	//2.
	Stuent s2 = { "����",19,88 };
	s2.PrintStudent();
	//3.
	s3.name = "����";
	s3.age = 20;
	s3.score =77;
	s3.PrintStudent();

	cout << "---------------" << endl;

	//�ṹ������      ����Ϊ�ṹ������飬���ڱ��涨��õĽṹ��
	Stuent stuArray[] = { s1,s2,s3 };
	int len = sizeof(stuArray) / sizeof(stuArray[0]);
	for (int i = 0; i < len; i++)
	{
		stuArray[i].PrintStudent();
	}

	cout << "---------------" << endl;
	//�ṹ��ָ��
	Stuent* p_stu = &s1;
	p_stu->name = "������";
	p_stu->PrintStudent();

	cout << "---------------" << endl;
	
	//�ṹ��Ƕ��
	Teacher tea = { 1,"����",{s1,s2,s3} };


	cout << "---------------" << endl;

	// �ṹ��ĺ�������
	changeSruct1(s1);    //ֵ���ݣ����غ�û�иı�ṹ�������
	s1.PrintStudent();
	changeStruct2(&s1);  //��ַ���ݣ��ı��˽ṹ�������
	s1.PrintStudent();



	//�ṹ���constʹ��


	ConstPrint(&s1);

}	

#endif