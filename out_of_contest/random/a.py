import heapq

n, m = map(int, input().split())
price = [*map(int, input().split())]
req = [*map(int, input().split())]
dis = [*map(int, input().split())]

tot = 0
price.sort(reverse = True)

heap = [(-r, -q) for r, q in zip(req, dis)]
heapq.heapify(heap)

for p in price:
    while heap and -heap[0][0] > p:
        heapq.heappop(heap)
    if heap:
        r, q = heapq.heappop(heap)
        print(r, q)
        tot += p + q
    else:
        tot += p
print(tot)