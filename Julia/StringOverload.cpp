#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

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
}
String String::operator=(String that) {
    delete []string;
    string = that.string;
}
String String::operator+(String that) {
    String temp;
    vector<char> v;
    for(int i = 0; string[i] != 0; i++) {
        v.push_back(string[i]);
    }
    for(int i = 0; that.string[i] != 0; i++) {
        v.push_back(that.string[i]);
    }
    delete []temp.string;
    temp.string = new char[v.size()];
    for(int i = 0; i<v.size(); i++) temp.string[i] = v[i];
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
    cout<<c<<endl;
    b = a;
    cout<<a+b;
    return 0;
}
