


LIM = 2 ** 15

res = []
for i in range(LIM):
    s = str(i)
    if s == s[::-1]:
        res.append(i)

print(len(res))