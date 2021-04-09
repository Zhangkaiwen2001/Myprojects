//
// Created by Wentw on 2018/12/27.
//

#include "Tea_Cou_Data.h"

Tea_Cou_Data::Tea_Cou_Data()
{
    for(int i=0;i<N;i++)
        for(int j =0;j<M;j++)
            Matrix[i][j]=false;
}

long long int Tea_Cou_Data::the_sizeofCourse() {
    return Courses.size();
}
long long int Tea_Cou_Data::the_sizeofTeacher() {
    return Teachers.size();
}

bool Tea_Cou_Data::the_conofMatrix(int i,int j) {
    return Matrix[i][j];
}

void Tea_Cou_Data::importdata()
{
    ifstream infile_t("teachers.dat");
    string name;
    if(infile_t)
    {
        while(!infile_t.eof())
        {
            infile_t>>name;
            Teachers.push_back(name);
        }
        Teachers.pop_back();
        infile_t.close();
        cout<<"Succeefully imported teacher information"<<endl;
    } else
        cout<<"No teacher file"<<endl;

    ifstream infile_c("courses.dat");
    if(infile_c)
    {
        while (!infile_c.eof())
        {
            infile_c>>name;
            Courses.push_back(name);
        }
        Courses.pop_back();
        infile_c.close();
        cout<<"Succeefully imported course information"<<endl;
    } else
        cout<<"No course file"<<endl;

    ifstream infile_m("matrix.dat");
    if(infile_m)
    {
        infile_m.read(reinterpret_cast<char*>(Matrix),N*M* sizeof(bool));
        cout<<"Succeefully imported relationship information"<<endl;
    }
    else
        cout<<"No relationship file"<<endl;
    infile_m.close();
}

void Tea_Cou_Data::Add_Course()
{
    cout<<"Input the name of course:";
    string nam_c;
    cin>>nam_c;
    cout<<endl;
    Courses.push_back(nam_c);
    ofstream file;
    file.open("courses.dat",ios::app);
    file<<nam_c<<" ";
    file.close();
}

void Tea_Cou_Data::Add_Teacher()
{
    cout<<"Input the name of teacher:";
    string nam_t;
    cin>>nam_t;
    cout<<endl;
    Teachers.push_back(nam_t);
    ofstream file;
    file.open("teachers.dat",ios::app);
    file<<nam_t<<" ";
    file.close();
}

void Tea_Cou_Data::link_node()
{
    int num_t,num_c;
    cout<<"Input the number of teacher:";
    cin>>num_t;
    cout<<endl<<"Input the number of course:";
    cin>>num_c;
    long long int m_t=Teachers.size();
    long long int m_c=Courses.size();
    if(num_c<m_c&&num_t<m_t)
        Matrix[num_t][num_c]= true;
    else
    {
        cout<<"Add failed"<<endl;
    }
    ofstream file;
    file.open("matrix.dat");
    if(file)
    {
        file.write(reinterpret_cast<char*>(Matrix),N*M* sizeof(bool));
    }
    file.close();
}

void Tea_Cou_Data::delete_teacher()
{
    cout<<"Enter the name of teacher:";
    string name;
    cin>>name;
    auto it=find(Teachers.begin(),Teachers.end(),name);
    if(it!=Teachers.end())
    {
        auto index=distance(Teachers.begin(),it);
        for(int i=0;i<Courses.size();i++)
            Matrix[index][i]= false;
        cout<<"Successfully deleted"<<endl;
    }
    else
        cout<<"Teacher does not exist"<<endl;
}
void Tea_Cou_Data::delete_courses()
{
    cout<<"Enter the name of course："<<endl;
    string name;
    cin>>name;
    auto it=find(Courses.begin(),Courses.end(),name);
    if(it!=Courses.end())
    {
        auto index=distance(Courses.begin(),it);
        for(int i=0;i<Teachers.size();i++)
            Matrix[i][index]= false;
        cout<<"Successfully deleted"<<endl;
    }
    else
        cout<<"Course does not exist"<<endl;
}
void Tea_Cou_Data::delete_relationship()
{
    string name1,name2;
    cout<<"Enter the name of teacher:";    cin>>name1;
    cout<<"Enter the name of course:";     cin>>name2;
    auto it1=find(Teachers.begin(),Teachers.end(),name1);
    auto it2=find(Courses.begin(),Courses.end(),name2);
    if(it1!=Teachers.end()&&it2!=Courses.end())
    {
        auto index1=distance(Teachers.begin(),it1);
        auto index2=distance(Courses.begin(),it2);
        Matrix[index1][index2]=false;
        fstream file;
        file.open("matrix.dat");
        if(file)
        {
            file.write(reinterpret_cast<char*>(Matrix),N*M* sizeof(bool));
        }
        file.close();
    }

}

string Tea_Cou_Data::the_nameofCourse(int num) {
    return Courses[num];
}

string Tea_Cou_Data::the_nameofTeacher(int num) {
    return Teachers[num];
}

void Tea_Cou_Data::Show_teacherandcourse() {
    cout<<"Teacher:";
    for(int i=0;i<Teachers.size();i++)
        cout<<Teachers[i]<<" ";
    cout<<endl;
    cout<<"Courses:";
    for(int i=0;i<Courses.size();i++)
        cout<<Courses[i]<<" ";
    cout<<endl;
}