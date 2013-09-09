def prod(M, M2):
    mat3 = [[0, 0], [0, 0]]
    for i in (0, 1):
        for j in (0, 1):
            for k in (0, 1):
                mat3[i][j] = mat3[i][j] + M[i][k] * M2[k][j]

    for i in (0, 1):
        for j in (0, 1):
            M[i][j] = mat3[i][j] % 1000000007


def matpow(n, M):
    if n > 1:
        matpow(n / 2, M)
        prod(M, M)
    if n % 2 != 0:
        prod(M, M4)


def fib(n, M):
    matpow(n - 1, M)
    return M[0][0]

f1 = 0
f2 = 0
M4 = [[1, 1], [1, 0]]
M = [[1, 0], [0, 1]]
T = input()
# print T
i = 1
while i <= T:
    arr = raw_input()
    j = 0
    while arr[j] != ' ':
        j = j + 1
    f1 = (int)(arr[:j])
    f2 = (int)(arr[j:])
    M[0][0] = 1
    M[0][1] = 0
    M[1][0] = 0
    M[1][1] = 1
    f1 = fib(f1 + 1, M) - 1
    M[0][0] = 1
    M[0][1] = 0
    M[1][0] = 0
    M[1][1] = 1
    f2 = fib(f2 + 2, M) - 1
    # print f1
    # print f2
    print (f2 - f1) % 1000000007
    i = i + 1
