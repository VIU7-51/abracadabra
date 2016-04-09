import random
import matplotlib.pyplot as plt

from math import cos, pi

def create_table(f, length=50):
    x = [i for i in range(length)]
    x.sort()
    y = [f(x[i]) for i in range(length)]
    rho = [random.random() for i in range(length)]
    return [x, y, rho]

def gauss(A):
    n = len(A)
    for i in range(n):
        maxEl = abs(A[i][i])
        maxRow = i
        for k in range(i+1, n):
            if abs(A[k][i]) > maxEl:
                maxEl = abs(A[k][i])
                maxRow = k

        for k in range(i, n+1):
            tmp = A[maxRow][k]
            A[maxRow][k] = A[i][k]
            A[i][k] = tmp

        for k in range(i+1, n):
            c = -A[k][i]/A[i][i]
            for j in range(i, n+1):
                if i == j:
                    A[k][j] = 0
                else:
                    A[k][j] += c * A[i][j]

    x = [0 for i in range(n)]
    for i in range(n-1, -1, -1):
        x[i] = A[i][n]/A[i][i]
        for k in range(i-1, -1, -1):
            A[k][n] -= A[k][i] * x[i]
    return x


def leastsq(x, n, data):
    X, Y, rho = data[0], data[1], data[2]
    m = len(X)
    A = []
    for i in range(n+1):
        A.append([])
        for j in range(i, i+n+1):
            A[i].append(sum([rho[t]*X[t]**j for t in range(m)]))
        A[i].append(sum([rho[t]*Y[t]*X[t]**i for t in range(m)]))
    As = gauss(A)
    res = 0
    for i, a in enumerate(As):
        res += a*x**i
    return res


if __name__ == '__main__':
    f1 = lambda a: -0.5 *a +12
    f2 = lambda a: a**2
    f3 = lambda a: a**2 * cos(2*pi/5*a)

    table1 = create_table(f1)
    table2 = create_table(f2)
    table3 = create_table(f3)
    forpltX = [i for i in range(50)]
    forpltY1 = [leastsq(x, 1, table1) for x in forpltX]
    forpltY2 = [leastsq(x, 2, table2) for x in forpltX]
    forpltY3 = [leastsq(x, 15, table3) for x in forpltX]
    for i in range(len(forpltX)):
        print "{0:2d} {1:6.2f} {2:8.2f} {3:8.2f}".format(forpltX[i],
                                forpltY1[i], forpltY2[i], forpltY3[i])

    fig1 = plt.figure(1)
    plt.plot(forpltX, forpltY1, label='least squares')
    plt.plot(table1[0], table1[1], label='original')
    plt.legend()
    fig1.show()
    fig2 = plt.figure(2)
    plt.plot(forpltX, forpltY2, label='least squares')
    plt.plot(table2[0], table2[1], label='original')
    plt.legend()
    fig2.show()
    fig3 = plt.figure(3)
    plt.plot(forpltX, forpltY3, label='least squares')
    plt.plot(table3[0], table3[1], label='original')
    plt.legend()
    fig3.show()
    raw_input()
#sudo apt-get install python-matplotlib
