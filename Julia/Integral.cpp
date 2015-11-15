#include <iostream>
#include <math.h>
using namespace std;

typedef double (*function)(double);
typedef double Interval;

class Integral{
public:
    Integral();
    void SetStep(int);
    double RightRectangle(function, double, double);
    double LeftRectangle(function, double, double);
    double MidRectangle(function, double, double);
    double SimpsonsRule(function, double, double);
private:
    int step;
};
Integral::Integral(){
    step = 10;
}

void Integral::SetStep(int newStep){
    step = newStep;
}

double Integral::LeftRectangle(function f, double a, double b){
    double result = 0;
    Interval h = (b-a)/step;
    for (int i = 0; i < step; i++) {
        result += h * f(a+i*h);
    }
    return result;
}

double Integral::RightRectangle(function f, double a, double b){
    double result = 0;
    Interval h = (b-a)/step;
    for (int i = 1; i <= step; i++) {
        result += h * f(a+i*h);
    }
    return result;
}

double Integral::MidRectangle(function f, double a, double b){
    double result = 0;
    Interval h = (b-a)/step;
    for (int i = 0; i < step; i++) {
        result += h * f(a+h*(i+0.5));
    }
    return result;
}

double Integral::SimpsonsRule(function f, double a, double b){
    double result = f(a)+f(b);
    Interval h = (b-a)/step;
    for (int i = 1; i < step; i+=2) {
        result += 4 * f(a+h*i);
    }
    for (int i = 2; i < step-1; i+=2) {
        result += 2 * f(a+h*i);
    }
    return result*h/3;
}

double sine(double x){
    return 3+2*sin(2*x);
}

int main(){
    Integral in;
    cout<<"Ideal = 16.8390715"<<endl;
    cout<<in.LeftRectangle(&sine, 0, 5)<<" right"<<endl;
    cout<<in.RightRectangle(&sine, 0, 5)<<" left"<<endl;
    cout<<in.MidRectangle(&sine, 0, 5)<<" mid"<<endl;
    cout<<in.SimpsonsRule(&sine, 0, 5)<<" SR\n"<<endl;
    in.SetStep(20);
    cout<<in.LeftRectangle(&sine, 0, 5)<<" right"<<endl;
    cout<<in.RightRectangle(&sine, 0, 5)<<" left"<<endl;
    cout<<in.MidRectangle(&sine, 0, 5)<<" mid"<<endl;
    cout<<in.SimpsonsRule(&sine, 0, 5)<<" SR\n"<<endl;
    return 0;
}
