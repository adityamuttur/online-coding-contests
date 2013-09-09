P = input()
while P > 0:
    T = raw_input()
    i = 0
    while T[i] != ' ':
        i+=1
    n = int(T[:i+1])
    m = int(T[i+1:])
    ans = ((2**(n-m)) - 1)
    ans *= (2*(2**m))
    ans = str(ans)
    ans += '.00'
    print(ans)
    P -= 1
    T = ""
