# include <iostream>

using namespace std;

//��������ص�Ŀ����Ϊ�˸��Զ�����������ͣ�����ĳ�ֹ��ܡ�
class Person
{
public:
	int age;
	string* ptr_name;
public:
	Person(int age)
	{
		this->age = age;
	}
	Person(int age, string* ptr_name)
	{
		this->age = age;
		this->ptr_name = ptr_name;
	}
	Person()
	{

	}
	//����Person�����������캯�������ʱ��ֲ�����p3���ٺ󣬿�����������һ��������Ӱ�졣
	Person operator+(const Person& p)   //*this+p
	{
		Person p3;
		p3.age = this->age + p.age;
		return p3;
	}


	//��������������ǳ�Ա���� 
	//��Ա���� ʵ�ֲ���  p << cout ����������Ҫ��Ч��
	//void operator<<(Person& p){
	//}

	//ǰ��++
	Person& operator++()
	{
		++this->age;
		return *this;
	}

	//����
	Person operator++(int)
	{
		//
		Person temp = *this;        //������ʱ����
		this->age++;
		//���ؾֲ��������ʱ�򽫷���ֵ����������ΪPerson���ͣ����ʱ��ᷢ���������캯��������ʱ�������ٺ󲻻�Ӱ�쵽����һ��������������������ͣ����õ��Ǿֲ����������ʱ����ִ��������ٶ��󣬱�����ָ��Ұָ���ˡ���
		return temp;                

	}



	void Print(string name)
	{
		cout << name <<":      " <<this->age << endl;
	}

	void operator() (string test)
	{
		cout << test << endl;
	}

	
	//��ֵ���������
	Person& operator=(const Person& p)
	{
		//���ԭ����ptr_name��Ϊ�����ͷ��ڴ�
		if (ptr_name != NULL)
		{
			delete ptr_name;
			ptr_name = NULL;
		}
		this->age = p.age;
		//��һ���µ��ڴ�
		this->ptr_name = new string(*p.ptr_name);

		return *this;

		
	}

	//  ==���������(��Ա������Ҳ����ȫ�ֺ�������)
	bool operator== (const Person& p)const
	{
		if (*this->ptr_name == *p.ptr_name && this->age == p.age)
		{
			return true;
		}
		return false;
	}
	
	
};

//!=��������أ�ȫ�ֺ�����Ҳ���Գ�Ա�������أ�
bool operator!=(const Person& p1,const Person& p2)
{
	if (*p1.ptr_name == *p2.ptr_name && p1.age == p2.age)
	{
		return false;
	}
	return true;
}

//ȫ�ֺ������������+
Person operator+ (const Person& p1, const Person& p2)
{
	Person p3;
	p3.age = p1.age + p2.age;
	return p3;
}


//��������+
Person operator+(const Person& p1,  int d)
{
	Person p3;
	p3.age = p1.age +  d;
	return p3;
}



//���������
//��ʽ��̷�������
ostream& operator<<(ostream& out, const Person& p)
{
	out << p.age;
	return out;
}



int main()
{
	Person p1 = Person(10);
	Person p2 = Person(20);
	Person p3 = p1 + p2;         //   <=>p1.operator+(p2);  ��Ա��������+�����
	p3.Print("p3");
	Person p4 = operator+(p1,p3);  // <=> p4 = p1+p3 ;ȫ�ֺ�������+�����
	p4.Print("p4");
	cout << p4 << endl;;

	cout << "p1:       " << p1.age << endl;
	cout << "p1++:       " << p1++<< endl;
	cout << "++p1:       " << ++p1<< endl;

	string name = "���곿";
	Person p5 = Person(18,&name );
	Person p6, p7;
	p6 = p7 = p5;

	cout << (p6 == p7) << endl;
	*p6.ptr_name = "��˼��";        
	cout << (p6 == p7) << endl;
	cout << (p6 != p7) << endl;


	//����������÷º���
	Person()("���Էº���");
}