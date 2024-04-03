s = input()
a = s.split(";")

ans = 0
for v in a:
    if "-" in v:
        x, y = map(int, v.split("-"))
        ans += y - x + 1
    else:
        ans += 1

print(ans)