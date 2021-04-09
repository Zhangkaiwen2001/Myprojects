#include <iostream>
using namespace std;
class Animal
{
public:
    static int number;
    Animal()
    {
        number++;
    }
    virtual ~Animal()//如果不加virtual,删除c2的时候就不能调用Cat的析构函数了
    {
        number--;
    }
};
class Dog:public Animal
{
public:
    static int number;
    Dog()
    {
        number++;
    }
    ~Dog()
    {
        number--;
    }
};
class Cat:public Animal
{
public:
    static int number;
    Cat()
    {
        number++;
    }
    ~Cat()
    {
        number--;
    }
};
int Animal::number=0,Dog::number=0,Cat::number=0; //静态成员变量只能在类外初始化，不能在类里面！！！
void print()
{
    cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main()
{
    print();
    Dog d1, d2;
    Cat c1;
    print();
    Dog* d3 = new Dog();
    Animal* c2 = new Cat;
    Cat* c3 = new Cat;
    print();
    delete c3;
    delete c2;
    delete d3;
    print();
}
