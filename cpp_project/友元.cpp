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
		m_livingRoom = "客厅";
		m_bedRoom = "卧室";
	}
public:
	string m_livingRoom;
private:
	string m_bedRoom;
};

//好基友类
class  GoodGuy
{
public:
	GoodGuy()
	{
		ptr_build = new Building;
	}
	void visit2()
	{
		cout << "GoodGuy类访问Building类" << ptr_build->m_livingRoom << endl;
		cout << "GoodGuy类访问Building类" << ptr_build->m_bedRoom << endl;
	}
private:
	Building* ptr_build;
};


void visit1(Building& p)
{
	cout << "全局函数访问" << p.m_livingRoom << endl;
	cout << "全局函数访问" << p.m_bedRoom << endl;

}






int main()
{
	Building b;
	visit1(b);
	GoodGuy g;
	g.visit2();
	
}

#endif