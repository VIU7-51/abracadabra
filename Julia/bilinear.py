import random

def create_xy(length=30):
    n = 20
    x = [random.uniform(0, n) for i in range(length)]
    y = [random.uniform(0, n) for i in range(length)]
    x.sort()
    y.sort()
    return [x, y]

def choose_data(x, table, n):
    for i in range(len(table)):
        if x == table[i]:
            return table[i]
        if x < table[i] and n%2 == 0:
            data = [table[j] for j in range(i-n/2-1,i+n/2)]
            return data
        if x < table[i] and n%2 != 0:
            data = [table[j] for j in range(i-n/2-1,i+n/2+1)]
            return data

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

def bilinear_int(x, y, n=3):
    f = lambda x, y: 2*x + 3*y
    allX, allY = create_xy()
    X = choose_data(x, allX, n)
    Y = choose_data(y, allY, n)
    int_XZ = []
    for i in range(n+1):
        z = [f(X[j], Y[i]) for j in range(len(X))]
        int_XZ.append(interpolate(x, [X, z], n))
    return interpolate(y, [Y, int_XZ], n)


if __name__ == '__main__':
    print 'x=3, y=16, z=', bilinear_int(3.145, 16.543)
    print 'real answer = ', 2*3.145+16.543*3
