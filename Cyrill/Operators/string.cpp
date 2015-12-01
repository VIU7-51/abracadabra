#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;

istream & operator>>(istream &is, String &str)
{
    char buf[4096];
    is.getline(buf, sizeof buf);
    str = buf;
    return is;
}

ostream & operator<<(ostream &os, const String &str)
{
    return os << str.s;
}

const char & String::operator[] (int i)const
{
    if(0<=i && i<n) return s[i];
    cerr << "Index out of range" << endl;
    return s[n];
}

char & String::operator[] (int i)
{
    if(0<=i && i<n) return s[i];
    cerr << "Index out of range" << endl;
    static char dummy;
    dummy = '\0';
    return dummy;
}

bool  operator==(const String &lh, const String &rh)
{
    return lh.n==rh.n && strcmp(lh.s, rh.s)==0;
}

bool  operator>(const String &lh, const String &rh)
{
    return strcmp(lh.s, rh.s)>0;
}

bool  operator<=(const String &lh, const String &rh)
{
    return !(lh>rh);
}

bool  operator<(const String &lh, const String &rh)
{
    return rh>lh;
}

bool  operator>=(const String &lh, const String &rh)
{
    return !(lh<rh);
}

bool  operator!=(const String &lh, const String &rh)
{
    return !(lh==rh);
}

String operator+(const String &lh, const String &rh)
{
    String t = lh;
    return t += rh;
}

String & String::operator+=(const String &str)
{
    char *t = new char[n+str.n+1];
    strcpy(t,s);
    strcat(t,str.s);
    delete[] s;
    s = t; n += str.n;
    return *this;
}

String & String::operator=(const String &str)
{
    if(this == &str) 
        return *this;
    delete[] s;
    n = str.n;
    s = new char[n+1];
    strcpy(s,str.s);
    return *this;
}

String::String(const String &str)
{
    n = str.n;
    s = new char[n+1];
    strcpy(s,str.s);
}

String::String(const char *str)
{
    n = strlen(str);
    s = new char[n+1];
    strcpy(s,str);
}


String::~String()
{
    delete[] s;
}

void String::Print()const
{
    cout<<s;
}
