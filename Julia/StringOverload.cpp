#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define StringSize strlen(string)+strlen(that.string)

class String {
public:
    String();
    String(char*);
    String operator=(char*);
    String operator=(String);
    String operator+(String);
    friend ostream& operator<<(ostream &os, String s);
private:
    char *string;
};
String::String() {
    string = new char[0];
}
String::String(char *c) {
    string = c;
}
String String::operator=(char *that) {
    delete []string;
    string = that;
    return *this;
}
String String::operator=(String that) {
    string = that.string;
    return *this;
}
String String::operator+(String that) {
    String temp;
    delete []temp.string;
    temp.string = new char[StringSize];
    int j = 0;
    for(int i = 0; i<strlen(string); i++, j++) temp.string[j] = string[i];
    for(int i = 0; i<strlen(that.string); i++, j++) temp.string[j] = that.string[i];
    return temp;
}
ostream& operator<<(ostream &os, String s) {
    os<<s.string;
    return os;
}

int main() {
    String a, b;
    String c("BAZINGA");
    a = "Hello";
    cout<<c+a<<endl;
    b = a;
    c = a+b;
    cout<<c<<endl;
    return 0;
}
