#include <iostream>
#include <cmath>

using namespace std;

class Integral{
public:
    Integral(int);
    int step;
    double LeftRect(double (*f)(double), double, double);
    double MidRect(double (*f)(double), double, double);
    double RightRect(double (*f)(double), double, double);
    double SimpsRule(double (*f)(double), double, double);
};

Integral::Integral(int s) {
    step = s;
}

double Integral::LeftRect(double (*f)(double), double a, double b) {
    double result = 0;
    double h = (b-a)/step;

    for (int i=0; i<step;i++)
        result += h * f(a+i*h);
    return result;
}

double Integral::MidRect(double (*f)(double), double a, double b) {
    double result = 0;
    double h = (b-a)/step;

    for (int i=0; i<step;i++)
        result += h * f(a+(i+0.5)*h);
    return result;
}

double Integral::RightRect(double (*f)(double), double a, double b) {
    double result = 0;
    double h = (b-a)/step;

    for (int i=1; i<=step;i++)
        result += h * f(a+i*h);
    return result;
}

double Integral::SimpsRule(double (*f)(double), double a, double b) {

    //По формуле отсюда: https://ru.wikipedia.org/wiki/Формула_Симпсона
    return  ((b-a)/6)*(f(a) + 4*f((a+b)/2) + f(b));

}

double testFunction(double x){
    return x*2;
}

int main() {

    Integral* integral = new Integral(1);
    for (int i = integral->step; i<5; i++){
        cout << "Left: " << integral->LeftRect(&testFunction, 0, 10);
        cout << " Mid: " << integral->MidRect(&testFunction, 0, 10);
        cout << " Right: " << integral->RightRect(&testFunction, 0, 10);
        cout << " Simpsons: " << integral->SimpsRule(&testFunction, 0, 10);
        cout << "\n";
        integral->step++;
    }

    return 0;
}