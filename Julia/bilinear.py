import random

def create_xy(length=30):
    n = 20
    x = [random.uniform(0, n) for i in range(length)]
    y = [random.uniform(0, n) for i in range(length)]
    x.sort()
    y.sort()
    return [x, y]

def choose_data(x, table, n):
    nodes = n + 1
    for i in range(len(table)):
        if x == table[i]:
            return table[i]
        if x < table[i] and n%2 == 0:
            data = [table[j] for j in range(i-nodes/2,i+nodes/2+1)]
            return data
        if x < table[i] and n%2 != 0:
            data = [table[j] for j in range(i-nodes/2,i+nodes/2)]
            return data

def bilinear_int(x, y, data, n=3):
    X, Y, Z = data[0], data[1], data[2]
    int_XZ = []
    for i in range(n+1):
        int_XZ.append(interpolate(x, [X, Z[i]], n))
    return interpolate(y, [Y, int_XZ], n)

def interpolate(x, data, n):
    X = data[0]
    Y = data[1]
    step = 1
    Y = [Y]
    result = [Y[0][0]]
    for i in range(1, n+1):
        Y.append(list())
        for j in range(n):
            if j + step > n:
                break
            Y[i].append((Y[i-1][j+1]-Y[i-1][j])/(X[j+step]-X[j]))
        result.append(Y[i][0])
        for a in range(step):
            result[step] *= (x - X[a])
        step += 1
    return sum(result)

if __name__ == '__main__':
    f = lambda a, b: a**2 + b**2

    x = float(raw_input('Enter x='))
    y = float(raw_input('Enter y='))
    n = int(raw_input('Enter n='))

    allX, allY = create_xy()
    X = choose_data(x, allX, n)
    Y = choose_data(y, allY, n)
    Z = [[f(X[j],Y[i]) for j in range(n+1)] for i in range(n+1)]

    print 'x=%f, y=%f, z=%f' %(x, y, bilinear_int(x, y, [X,Y,Z], n))
    print 'real answer = ', f(x,y)
