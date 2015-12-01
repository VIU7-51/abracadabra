#include <iostream>
#include <fstream>
#include "String.h"
using namespace std;

int main()
{
    String a("Hello, world!");
    cout<<"String a: \"";    a.Print();
    cout<<"\", Len="<<a.Len()<<endl;

    String b=a;
    cout<<"String b: \"";    b.Print();
    cout<<"\", Len="<<b.Len()<<endl;

    b=a;// b.operator=(a);
    cout<<"String b: \"";    b.Print();
    cout<<"\", Len="<<b.Len()<<endl;

    b=b;// selfassignment
    cout<<"String b: \"";    b.Print();
    cout<<"\", Len="<<b.Len()<<endl;

    a += b;
    cout<<"String a: \"";    a.Print();
    cout<<"\", Len="<<a.Len()<<endl;

    a = "Billy Bonce ";    //a.operator=(String("Billy Bonce "));
    a += " Hi! Hi!";		//a.operator+=(String("Billy Bonce "));
    cout<<"String a: \"";    a.Print();
    cout<<"\", Len="<<a.Len()<<endl;

    a = a + b + " tratata";
    a = a + "Billy Bonce ";
    cout<<"String a: \"";    a.Print();
    cout<<"\", Len="<<a.Len()<<endl;

    a = "Billy Bonce " + b;
    cout<<"String a: \"";    a.Print();
    cout<<"\", Len="<<a.Len()<<endl;

    cout << (a==b) << endl;
    cout << (a!=b) << endl;
    cout << (a>b) << endl;

    a[0]='h';
    a[100]='@';
    cout<<"a[100]="<<a[100]<<endl;
    cout<<"a[0]="<<a[0]<<endl;
    cout<<"String a: \"";    a.Print();
    cout<<"\", Len="<<a.Len()<<endl;

    String *p = new String("Good bye, cruel world!");
    cout<<"Heapling String: \"";    p->Print();
    cout<<"\", Len="<<p->Len()<<endl;

    cout << "Test << :" << a << endl;

    cout<<"Enter name: ";
    cin >> a;
    cout << "Hi, " << a << endl;

    delete p;
}
