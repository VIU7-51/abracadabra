import random
from collections import namedtuple

def create_table(f, range_=15):
    n = 100
    x = [random.uniform(0, range_) for i in range(n)]
    x.sort()
    y = [f(x[i]) for i in range(n)]
    return [x, y]

def spline(x):
    X, Y = create_table(lambda x: x**2)
    n = len(X)
    a, b, c, d = find_coef(X, Y)

    Spline = namedtuple('Spline', ['a', 'b', 'c', 'd', 'x'])
    splines = []
    for i in range(n):
        splines.append(Spline(a[i], b[i], c[i], d[i], X[i]))

    s = Spline(0,0,0,0,0)
    if x < X[0]:
        s = splines[0]
    elif x > X[n-1]:
        s = splines[n-1]
    else:
        for i in range(n):
            if X[i] > x:
                s = splines[i]
                break

    dx = x - s.x
    return s.a + s.b*dx + s.c/2.0*dx**2 + s.d/6.0*dx**3



def find_coef(X, Y):
    xi, eta = find_helpers(X, Y)
    c = [0.0]*len(X)
    d = [0.0]*len(X)
    b = [0.0]*len(X)
    for i in range(len(X)-2, 0, -1):
        c[i] = (xi[i] * c[i+1] + eta[i])
    for i in range(len(X)-1, 0, -1):
        hi = (X[i] - X[i-1])
        d[i] = (c[i] - c[i-1]) / hi
        b[i] = ((Y[i] - Y[i-1]) / hi + hi * (c[i-1] + 2 * c[i]) / 6.)
    return Y[:], b, c, d


def find_helpers(X, Y):
    F = find_F(X, Y)
    xi = [0.0]
    eta = [0.0]
    for i in range(1, len(X)-1):
        hi = (X[i] - X[i-1])
        hi1 = (X[i+1] - X[i])
        K = 2. * (hi + hi1) - hi * xi[i-1]
        xi.append(-(X[i+1] - X[i]) / K)
        eta.append((F[i] - hi * eta[i-1]) / K)
    return xi, eta

def find_F(X, Y):
    F = [0.0]*len(X)
    for i in range(1, len(X)-1):
        hi = (X[i] - X[i-1])
        hi1 = (X[i+1] - X[i])
        F[i] = 6.*((Y[i+1]-Y[i])/hi1 - (Y[i]-Y[i-1])/hi)
    return F


if __name__ == '__main__':
    print spline(2.5)
