#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<iostream>
//using namespace std;
//��������������

//class Base
//{
//public:
//	void show()
//	{
//		std::cout << "Base class" << std::endl;
//	}
//};
//// Base���ǻ��࣬Ҳ�Ǹ�����࣬��������̳е��࣬
////�����ṩ����������Լ̳к���չ�����Ժͷ���
//
////����ͨ������Ϊͨ�õĹ��ܺͽӿڣ������������ʵ�־���ϸ��
//
//class Derived :public Base
//{
//public:
//	void show()
//	{
//		std::cout << "Derived class" << std::endl;
//	}
//};
////����������� Derived���������࣬�����̳�Base ��������Ժͷ���


//���麯��չʾ
//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive()
//	{
//		std::cout << "Benz" << std::endl;
//	}
//};
//
//class BMW :public Car
//{
//public:
//	virtual void Drive()
//	{
//		std::cout << "BMW" << std::endl;
//	}
//};
//
//int main()
//{
//	
//	Benz b1;
//	BMW b2;
//
//	Car* ptr = &b1;
//	ptr->Drive();
//
//	ptr = &b2;
//	ptr->Drive();
//	return 0;
//}


//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		std::cout << "��Ʊ-ȫ��" << std::endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		std::cout << "��Ʊ-���" << std::endl;
//	}
//};
//
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}



//int main()
//{
//	Person Mike;
//	Func(Mike);
//	
//	Student Johnson;
//	Func(Johnson);
//
//	Person p1;
//	Person p2;
//
//	
//	
//	return 0;
//
//}


//int main()
//{
//	int i = 0;
//	static int j = 1;
//	int* p1 = new int;
//	const char* p2 = "xxxxxxxx";
//	printf("ջ:%p\n", &i);
//	printf("��̬��:%p\n", &j);
//	printf("��:%p\n", p1);
//	printf("������:%p\n", p2);
//
//	Person p;
//	Student s;
//	Person* p3 = &p;
//	Student* p4 = &s;
//
//	printf("Person����ַ:%p\n", *(int*)p3);
//	printf("Student����ַ:%p\n", *(int*)p4);
//
//	return 0;
//}


//class Base
//{
//public:
//	virtual void func1() { std::cout << "Base::func1" << std::endl; }
//	virtual void func2() { std::cout << "Base::func2" << std::endl; }
//private:
//	int a;
//};
//
//class Derive :public Base
//{
//public:
//	Derive()
//	{}// ���캯����Ϊ����
//
//		virtual void func1() { std::cout << "Base::func1" << std::endl; }
//		virtual void func3() { std::cout << "Base::func2" << std::endl; }
//		virtual void func4() { std::cout << "Base::func1" << std::endl; }
//private:
//	int b = 0;
//	
//};
//
//
typedef void(*VFPTR)();
void PrintVTable(VFPTR vTable[])
{
	std::cout << "����ַ>" << vTable << std::endl;
	for (int i = 0; vTable[i] != nullptr; i++)
	{
		printf("��%d���麯����ַ :0x%p,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();//�����麯��
	}
	std::cout << std::endl;
}
//
//
//int main()
//{
//	Base b;
//	Derive d;
//	
//	VFPTR * vTableb = (VFPTR*)(*(int*)&b);
//	PrintVTable(vTableb);
//	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTabled);
//
//	return 0;
//}



//��̳�
class Base
{
public:
	virtual void func1() { std::cout << "Base1::func1" << std::endl; }
	virtual void func2() { std::cout << "Base1::func2" << std::endl; }
private:
	int b1;
};

class Base2
{
public:
	virtual void func1() { std::cout << "Base2:;func1" << std::endl; }
	virtual void func2() { std::cout << "Base2:;func1" << std::endl; }
private:
	int d1;
};


class Derive :public Base, public Base2
{
public:
	virtual void func1() { std::cout << "Base2:;func1" << std::endl; }
	virtual void func2() { std::cout << "Base2:;func1" << std::endl; }
private:
	int d1;
};


//int main()
//{
//	Derive d;
//	std::cout << sizeof(Derive) << std::endl;
//
//	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
//	PrintVTable(vTableb1);
//
//	Base2* f = &d;
//	VFPTR* vTable2 = (VFPTR*)(*(int*)(f));
//	PrintVTable(vTable2);
//	return 0;
//}


#include"BinarySearchTree.h"
int main()
{
	//TestBSTreel();
	//key_value::TestBSTree2();
	key_value::TestBSTree3();
	return 0;
}