from sys import stdin

def fac(n):
    if n == 0:
        return 1
    res = 1
    for i in range(1, n + 1):
        res *= i
    return res

n, k = map(int, stdin.readline().split())
print(fac(n) // (fac(k) * fac(n - k)))