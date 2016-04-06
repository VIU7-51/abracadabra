import random
import matplotlib.pyplot as plt

from math import cos, pi

def create_table(f, length=50):
    x = [i for i in range(length)]
    x.sort()
    y = [f(x[i]) for i in range(length)]
    rho = [random.random() for i in range(length)]
    return [x, y, rho]

def leastsq(x, data):
    X, Y, rho = data[0], data[1], data[2]
    m = len(X)
    #xy = sum([X[i]*Y[i] for i in range(n)])
    #x2 = sum([i**2 for i in X])
    #denominator = x2 - sum(X)**2/n
    #slope = (xy - sum(X)*sum(Y)/n) / denominator
    #intercept = (sum(Y) - slope * sum(X))/n
    rhoX2 = sum([rho[i]*X[i]*X[i] for i in range(m)])
    rhoXY = sum([rho[i]*X[i]*Y[i] for i in range(m)])
    rhoX = sum([rho[i]*X[i] for i in range(m)])
    rhoY = sum([rho[i]*Y[i] for i in range(m)])
    denominator = (sum(rho) * rhoX2 - rhoX**2)
    slope = (sum(rho)*rhoXY - rhoX * rhoY) / denominator
    intercept = (rhoY * rhoX2 - rhoX * rhoXY) / denominator
    return slope * x + intercept

if __name__ == '__main__':
    #f = lambda a: 6 *a + 2
    f = lambda a: a**2 * cos(2*pi/5*a)
    #f = lambda a: a**2
    table = create_table(f)
    forpltX = [i for i in range(50)]
    forpltY = [leastsq(x, table) for x in forpltX]
    plt.plot(forpltX, forpltY, label='least squares')
    plt.plot(table[0], table[1], label='original')
    plt.legend()
    plt.show()
#sudo apt-get install python-matplotlib
