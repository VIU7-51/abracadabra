#include <iostream>
#include <string>
#include <math.h>
using namespace std;

#define f(x) (exp(x/5) - x)
#define df(x) (exp(x/5)/5 - 1)

double iter(double x0, double eps);
double tang(double x0, double eps);

int main()
{
    double x = iter(1.3, 0.00001);
    cout<<x<<"   -x\n";
    cout<<f(x)<<"    -f(x)\n";
    double y = tang(12.7, 0.00001);
    cout<<y<<"    -y\n";
    cout<<f(y)<<"    -f(y)";
}

double iter(double x0, double eps)
{
    double x1, dx;
        do
        {
        	x1 = x0;
            x0 = f(x1);
            dx = fabs(x1-x0);
        } while(dx > eps);
    return x0;
}

double tang(double x0, double eps)
{
    double x1, dx;
    do
    {
        dx = f(x0) / df(x0);
        x1 = x0-dx;
        x0 = x1;
    } while(fabs(dx)>eps);
    return x0;
}
