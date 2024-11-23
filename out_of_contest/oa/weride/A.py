"""
author : Jie Chen (4th Year CS)
school : Rochester Institute of Technology
created: 09.28.2024 13:12:17
"""

from collections import defaultdict

def totalTriplets(capacity, desiredCapaity):
    countSingle = defaultdict(int)
    countDouble = defaultdict(int)

    capacitySize = len(capacity)
    countZero = [0] * (capacitySize + 1)
    for i in range(capacitySize):
        countZero[i + 1] = countZero[i] + int(capacity[i] == 0)
    
    triplets = 0
    zeroSoFar = int(capacity[-1] == 0)
    for i in range(capacitySize - 2, -1, -1):
        double = capacity[i] * capacity[i + 1]
        if desiredCapaity == 0:
            if capacity[i] == 0:
                triplets += i
                if i != 0:
                    triplets += capacitySize - i - 2
            else:
                if capacity[i + 1] == 0:
                    triplets += i
                else:
                    triplets += countZero[i]
                
                if i - 1 >= 0:
                    if capacity[i - 1] == 0:
                        answer += capacitySize - i - 2
                    else:
                        answer += zeroSoFar - int(capacity[i] == 0)
            continue

        zeroSoFar += int(capacity[i] == 0)
        if capacity[i] == 0:
            continue

        if desiredCapaity % capacity[i] == 0:
            need = desiredCapaity // capacity[i]
            triplets += countDouble[need]

        if double != 0:
            if i < capacitySize - 2:
                if desiredCapaity % double == 0:
                    need = desiredCapaity // double
                    triplets += countSingle[need] - int(desiredCapaity // double == capacity[i + 2])
            countSingle[capacity[i + 1]] += 1
            countDouble[double] += 1
        else:
            continue
    return triplets

capacity = [1, 2, 2, 2, 4]
desire = 8
print(totalTriplets(capacity, desire))

# ~ JustJie