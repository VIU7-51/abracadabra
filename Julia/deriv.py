# -*- coding: cp1251 -*-
from math import exp, log

def generate_X(length, step, first=1):
    X = [first + i*step for i in range(length)]
    return X

def derivate_exp3x():
    f = lambda x: exp(3*x)
    X = generate_X(10, 0.15)
    Y = [f(x) for x in X]
    derivative = [3*f(x) for x in X]
    n = len(X)
    h = X[1]-X[0]

    right_h = [(Y[i+1]-Y[i]) / h for i in range(n-1)]
    right_2h = [(Y[i+2]-Y[i]) / (2*h) for i in range(n-2)]
    Runge_right = [right_h[i] + (right_h[i] - right_2h[i]) for i in range(n-2)]

    central = [(-3.*Y[0] + 4.*Y[1] - Y[2]) / (2.*h)]
    central.extend([(Y[i+1]-Y[i-1]) / (2*h) for i in range(1, n-1)])
    central.append((Y[-3] - 4*Y[-2] + 3*Y[-1]) / (2*h))

    xi = [x*3. for x in X]
    eta = [log(y) for y in Y]
    xi_x = 3
    eta_y = [1./y for y in Y]
    eta_xi = [(-3*eta[0] + 4*eta[1] - eta[2]) / (xi[2]-xi[0])]
    eta_xi.extend([(eta[i+1] - eta[i-1]) / (xi[i+1] - xi[i-1]) for i in range(1, n-1)])
    eta_xi.append((eta[-3] - 4*eta[-2] + 3*eta[-1]) / (xi[-1] - xi[-3]))
    y_x = [eta_xi[i]*xi_x/eta_y[i] for i in range(n)]

    write_table(X, Y, derivative, right_h, Runge_right, central, y_x)

def write_table(*args):
    with open('deriv_exp3x.txt', 'w') as fout:
        fout.write("\t\tx\t\t\ty=exp(3x)\t\t\ty'\t\t\tправая\
\t\tRunge правая\tцентральная\t\tвыравнивающие")
        fout.write('\n')
        for i in range(len(args[0])):
            for j in args:
                try:
                    fout.write("{0:10.4f}".format(j[i]))
                    fout.write('\t\t')
                except IndexError:
                    fout.write('\t\t-\t\t')
            fout.write('\n')

if __name__ == '__main__':
    derivate_exp3x()
