

n = 8
a = [*map(int, "7 5 6 7 10 3 3 3".split())]

res = 0
for i in range(n):
    for j in range(i):
        v = a[i] & a[j] & (a[i] + a[j])
        if v:
            print(a[j], a[i], bin(a[i] & a[j])[2:].zfill(4), bin(a[i] + a[j])[2:])
            print(j, i, v)
            res += v
    
print(res)