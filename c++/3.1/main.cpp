#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s)
{
    int i = 0;
    for(; s[i]; ++i);
    return i;
}
void strcpy(char * d,const char * s)
{
    int i = 0;
    for( i = 0; s[i]; ++i)
        d[i] = s[i];
    d[i] = 0;

}
int strcmp(const char * s1,const char * s2)
{
    for(int i = 0; s1[i] && s2[i] ; ++i)
    {
        if( s1[i] < s2[i] )
            return -1;
        else if( s1[i] > s2[i])
            return 1;
    }
    return 0;
}
void strcat(char * d,const char * s)
{
    int len = strlen(d);
    strcpy(d+len,s);
}
class MyString
{
private:
    char *p;
public:
    MyString(const char * s = NULL)
    {
        if (s)
        {
            p = new char[strlen(s) + 1];
            strcpy(p, s);
        }
        else
        {
            p = new char[1];
            p[0] = '\0';
        }
    }
    ~MyString()
    {
        if (p)
            delete[] p;
    }
    MyString(const MyString &s)
    {
        if (s.p)
        {
            p = new char[strlen(s.p) + 1];
            strcpy(p, s.p);
        }
        else
        {
            p = new char[1];
            p[0] = '\0';
        }
    }
    MyString & operator=(const char * s)
    {
        if (p == s)
            return *this;
        delete[] p;
        if (s)
        {
            p = new char[strlen(s) + 1];
            strcpy(p, s);
        }
        else
        {
            p = new char[1];
            p[0] = '\0';
        }
        return *this;
    }
    MyString & operator=(const MyString & s)
    {
        if (p == s.p)
            return *this;
        delete[] p;
        if (s.p)
        {
            p = new char[strlen(s.p) + 1];
            strcpy(p, s.p);
        }
        else
        {
            p = new char[1];
            p[0] = '\0';
        }
        return *this;
    }
    friend MyString  operator+(MyString &a, MyString &b)
    {
        char *temp = new char[strlen(a.p) + strlen(b.p)];
        strcpy(temp, a.p);
        strcat(temp, b.p);
        return MyString(temp);
    }
    friend ostream & operator<<(ostream &os, MyString & s)
    {
        os << s.p;
        return os;
    }
    char & operator[](int i)
    {
        return p[i];
    }
    MyString & operator+=(const char *s)
    {
        char* temp = new char[strlen(p)+1];
        strcpy(temp, p);
        delete[] p;
        p = new char[strlen(temp) + strlen(s)+1];
        strcpy(p, temp);
        strcat(p, s);
        return *this;
    }
    friend MyString  operator+(const char * str, MyString s )
    {
        char *temp = new char[strlen(str) + strlen(s.p)+1];
        strcpy(temp,str);
        strcat(temp, s.p);
        return MyString(temp);
    }
    friend MyString operator+(MyString s, const char *str)
    {
        char *temp = new char[strlen(s.p) + strlen(str) + 1];
        strcpy(temp, s.p);
        strcat(temp, str);
        return MyString(temp);
    }
    friend bool operator<(MyString &s1, MyString &s2)
    {
        if (strcmp(s1.p, s2.p) < 0)
            return true;
        else
            return false;
    }
    friend bool operator>(MyString &s1, MyString &s2)
    {
        if (strcmp(s1.p, s2.p) > 0)
            return true;
        else
            return false;
    }
    friend bool operator==(MyString &s1, MyString &s2)
    {
        if (strcmp(s1.p, s2.p) == 0)
            return true;
        else
            return false;
    }
    char * operator () (int start, int length)
    {
        char * temp = new char[length+1];
        for (int i = start; i < start+length; i++)
        {
            temp[i - start] = p[i];
        }
        temp[length] = '\0';
        return temp;
    }
};
int CompareString( const void * e1, const void * e2)
{
    MyString * s1 = (MyString * ) e1;
    MyString * s2 = (MyString * ) e2;
    if( * s1 < *s2 )
        return -1;
    else if( *s1 == *s2)
        return 0;
    else if( *s1 > *s2 )
        return 1;
}
int main()
{
    MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
    MyString SArray[4] = {"big","me","about","take"};
    cout << "1. " << s1 << s2 << s3<< s4<< endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A' ;
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray,4,sizeof(MyString),CompareString);
    for( int i = 0; i < 4; i ++ )
        cout << SArray[i] << endl;
    //s1的从下标0开始长度为4的子串
    cout << s1(0,4) << endl;
    //s1的从下标5开始长度为10的子串
    cout << s1(5,10) << endl;
    return 0;
}
