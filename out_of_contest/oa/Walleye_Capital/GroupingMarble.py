import bisect

G = 3

def work(g1, g2, g3):
    groups = [g1, g2, g3]
    siz = [0] * G

    lis = []
    for i, group in enumerate(groups):
        group.sort()
        for x in group:
            siz[i] += 1
            if not lis or x > lis[-1][0]:
                lis.append((x, i))
            else:
                j = bisect.bisect_left(lis, (x, i))
                lis[j] = (x, i)

    for _, i in lis:
        siz[i] -= 1

    return sum(siz)

group_1 = [1, 7, 3]
group_2 = [2, 6, 4]
group_3 = [5, 8, 9]
# Expected Output: Minimum moves = 3
print(work(group_1, group_2, group_3))

group_1 = [1]
group_2 = [2]
group_3 = [3]
# Expected Output: Minimum moves = 0
print(work(group_1, group_2, group_3))

group_1 = [2]
group_2 = [1]
group_3 = [3]
# Expected Output: Minimum moves = 1
print(work(group_1, group_2, group_3))

group_1 = [1, 5]
group_2 = [3, 4]
group_3 = [2, 6]
# Expected Output: Minimum moves = 2
print(work(group_1, group_2, group_3))

group_1 = [1, 4]
group_2 = [3]
group_3 = [2]
# Expected Output: Minimum moves = 2
print(work(group_1, group_2, group_3))

group_1 = [3, 5]
group_2 = [1, 4]
group_3 = [2]
# Expected Output: Minimum moves = 3
print(work(group_1, group_2, group_3))

group_1 = [1, 2, 3]
group_2 = [4, 5]
group_3 = [6, 7]
# Expected Output: Minimum moves = 0
print(work(group_1, group_2, group_3))

group_1 = [3, 4]
group_2 = [1]
group_3 = [2]
# Expected Output: Minimum moves = 2
print(work(group_1, group_2, group_3))

group_1 = []
group_2 = [3]
group_3 = [1, 2]
# Expected Output: Minimum moves = 1
print(work(group_1, group_2, group_3))

group_1 = []
group_2 = [1, 2, 4]
group_3 = [3]
# Expected Output: Minimum moves = 1
print(work(group_1, group_2, group_3))
