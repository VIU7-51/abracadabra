import random

def create_table(f, length=25):
    x = [random.uniform(0, length) for i in range(length)]
    x.sort()
    y = [f(x[i]) for i in range(length)]
    return [x, y]

def get_data(x, table, n=3):
    assert(n < len(table[0]))
    X, Y = table[0], table[1]
    nodes = n + 1
    for i in range(len(X)):
        if x == X[i]:
            return Y[i]
        if x > X[i] and n%2 == 0:
            x = [X[j] for j in range(i-nodes/2,i+nodes/2+1)]
            y = [Y[j] for j in range(i-nodes/2,i+nodes/2+1)]
            return x, y
        if x > X[i] and n%2 != 0:
            x = [X[j] for j in range(i-nodes/2,i+nodes/2)]
            y = [Y[j] for j in range(i-nodes/2,i+nodes/2)]
            return x, y

def interpolate(x, data, n=3):
    X, Y = data[0], data[1]
    step = 1
    Y = [Y]
    result = [Y[0][0]]
    for i in range(1, n+1):
        Y.append([])
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
    f = lambda a: a**2
    table = create_table(f)
    x = float(raw_input('Enter x='))
    n = int(raw_input('Enter n='))
    data = get_data(x, table, n)
    print 'y = %f real y = %f' % (interpolate(x, data, n), f(x))
