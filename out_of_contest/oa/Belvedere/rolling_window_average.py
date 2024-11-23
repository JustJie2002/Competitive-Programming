"""
author : Jie Chen (4th Year CS)
school : Rochester Institute of Technology
created: 09.15.2024 20:48:47
"""
from decimal import Decimal
from collections import deque

args = input().split(";")

window_quantity, trade_count = map(int, args[0].split(","))
trades = []
for trade in args[1:]:
    price, quantity = trade.split(",")
    trades.append((Decimal(price), int(quantity)))

queue = []
current_quantity = 0
current_total_price = 0
q = 0
for price, quantity in trades:
    current_quantity += quantity
    current_total_price += price * quantity
    queue.append([quantity, price])
    while q < len(queue) and (len(queue) - q > trade_count or current_quantity > window_quantity):
        previous_quantity, previous_price = queue[q]
        difference = current_quantity - window_quantity
        difference = min(difference, previous_quantity)
        if len(queue) - q > trade_count:
            difference = previous_quantity
        current_total_price -= difference * previous_price
        current_quantity -= difference
        queue[q][0] -= difference
        if queue[q][0] == 0:
            q += 1
    res = current_total_price / current_quantity
    print("{:.2f}".format(res))

# ~ JustJie