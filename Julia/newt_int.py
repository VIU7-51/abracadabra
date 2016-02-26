import random

def create_table(f, length=25):
    x = [random.uniform(0, length) for i in range(length)]
    x.sort()
    y = [f(x[i]) for i in range(length)]
    return [x, y]


def get_table(x, n, table):
    for i in range(len(table[0])):
        if x == table[0][i]:
            return table[1][i]
        if x < table[0][i] and n%2 == 0:
            x = [table[0][j] for j in range(i-n/2-1,i+n/2)]
            y = [table[1][j] for j in range(i-n/2-1,i+n/2)]
            return x, y
        if x < table[0][i] and n%2 != 0:
            x = [table[0][j] for j in range(i-n/2-1,i+n/2+1)]
            y = [table[1][j] for j in range(i-n/2-1,i+n/2+1)]
            return x, y


def interpolate(x, n, length=25):
    data = create_table(lambda x: x**2, length)
    if x > data[0][-n/2-1]:
        return "need bigger table"
    X, Y = get_table(x, n, data)
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


print "x = 2.5 answer = ",interpolate(2.5, 2)
print "x = 5.6458 answer = ", interpolate(5.6458, 3)
print "x = 0.345 answer = ", interpolate(0.345, 3)
print "x = 23.45 answer = ", interpolate(23.45, 3)
print "x = 23.45 answer = ",interpolate(23.45, 3, 30)
#table = create_table(lambda x: x**2, 100)
#print get_table(10, 4, table)
