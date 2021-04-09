#include <iostream>

using namespace std;

class computer
{
private:
    string name;
public:
    virtual void print()
    {
        cout<<"name: "<<name<<endl;
    }
    computer(string n)
    {
        name=n;
    }
};
class Macintosh:public computer
{
private:
    string color;
public:
    void print()
    {
        computer::print();
        cout<<"color:"<<color;
    }
    Macintosh(string n,string c):computer(n)
    {
        color = c;
    }
};
int main()
{
    computer *p;
    Macintosh imac("Joe's IMAC","Blue");

    p = &imac;
    p->print();
    return 0;
}

