# if  0
#include<iostream>

using namespace std;
class Building
{
	friend void visit1(Building& p);
	friend class GoodGuy;
	
public:
	Building()
	{
		m_livingRoom = "����";
		m_bedRoom = "����";
	}
public:
	string m_livingRoom;
private:
	string m_bedRoom;
};

//�û�����
class  GoodGuy
{
public:
	GoodGuy()
	{
		ptr_build = new Building;
	}
	void visit2()
	{
		cout << "GoodGuy�����Building��" << ptr_build->m_livingRoom << endl;
		cout << "GoodGuy�����Building��" << ptr_build->m_bedRoom << endl;
	}
private:
	Building* ptr_build;
};


void visit1(Building& p)
{
	cout << "ȫ�ֺ�������" << p.m_livingRoom << endl;
	cout << "ȫ�ֺ�������" << p.m_bedRoom << endl;

}






int main()
{
	Building b;
	visit1(b);
	GoodGuy g;
	g.visit2();
	
}

#endif