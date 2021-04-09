#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
private :
    string stuname;
    int age;
    string id;
    int score[4];
    double aver;
    double sum;
public :
    void input()
    {
        getline(cin,stuname,',');
        cin>>age;
        cin.get();
        getline(cin,id,',');
        int i=0;
        for(i=0;i<4;i++)
        {
            cin>>score[i];
            cin.get();
        }
    }
    void calculate()
    {
        int i;
        sum=0;
        for(i=0;i<4;i++)
        {
            sum=sum+score[i];
        }
        aver=sum/4;
    }
    void output()
    {
        cout<<stuname<<","<<age<<","<<id<<","<<aver;
    }

};

int main()
{
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}
