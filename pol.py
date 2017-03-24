from fractions import gcd

c1 = 23
c2 = 27

def inverse(x, m):
    a, b, u = 0, m, 1
    while x > 0:
        x, a, b, u = b % x, u, x, a - b // x * u
    if b == 1: return a % m
    return 0 

 
def rho(g,t,p):

    def f(xab):
        x, a, b = xab[0], xab[1], xab[2]
        if x % 3 == 0:
            return [(t*x)%p, (a+1)%(p-1), b]
        if x%3 == 1:
            return [(g*x)%p, a, (b+1)%(p-1)]
        return [(x*x)%p, (2*a)%(p-1), (2*b)%(p-1)]

    i, j, k = 1, [1,0,0], f([1,0,0])
    while j[0] <> k[0]:
        i, j, k = i+1, f(j), f(f(k))
    d = gcd(j[1] - k[1], p - 1)
    m, l = 0, ((k[2]-j[2])%((p-1)/d) * inverse((j[1]-k[1])%((p-1)/d),(p-1)/d)) % ((p-1)/d)

    while m <= d:
        if pow(g,l,p) == t:
            return (pow(c1,p-1-l,p)*c2) % p;
        m, l = m+1, (l+((p-1)/d))%(p-1)
    return False
 
print rho(2,3,29)
