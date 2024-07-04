#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<iostream>
//using namespace std;
//关于派生类例子

//class Base
//{
//public:
//	void show()
//	{
//		std::cout << "Base class" << std::endl;
//	}
//};
//// Base就是基类，也是父类或超类，是派生类继承的类，
////基类提供了派生类可以继承和扩展的属性和方法
//
////基类通常定义为通用的功能和接口，派生类则可以实现具体细节
//
//class Derived :public Base
//{
//public:
//	void show()
//	{
//		std::cout << "Derived class" << std::endl;
//	}
//};
////从这个代码中 Derived就是派生类，它将继承Base 基类的属性和方法


//纯虚函数展示
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
//		std::cout << "买票-全价" << std::endl;
//	}
//};
//
//class Student :public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		std::cout << "买票-半价" << std::endl;
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
//	printf("栈:%p\n", &i);
//	printf("静态区:%p\n", &j);
//	printf("堆:%p\n", p1);
//	printf("常量区:%p\n", p2);
//
//	Person p;
//	Student s;
//	Person* p3 = &p;
//	Student* p4 = &s;
//
//	printf("Person虚表地址:%p\n", *(int*)p3);
//	printf("Student虚表地址:%p\n", *(int*)p4);
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
//	{}// 构造函数改为公有
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
	std::cout << "虚表地址>" << vTable << std::endl;
	for (int i = 0; vTable[i] != nullptr; i++)
	{
		printf("第%d个虚函数地址 :0x%p,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();//调用虚函数
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



//多继承
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