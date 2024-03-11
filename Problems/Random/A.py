from collections import deque

def work(pins, screen_length):
    pins.sort(key = lambda x : x[1])

    def decide(side: str):
        return 0 if side == 'L' else 1

    groups = [deque() for _ in range(2)]
    ans = 0
    for top, bot, side in pins:
        if bot - top + 1 > screen_length:
            continue
        groups[decide(side)].append((top, bot))

        max_top = bot - screen_length + 1
        for i in range(2):
            while groups[i] and groups[i][0][0] < max_top:
                groups[i].popleft()
        
        ans = max(ans, len(groups[0]) + len(groups[1]))
    
    return ans

pins = [(1,4,"L"),(2,3,"R"),(4,8,"R"),(6,9,"L")]
screen_length = 5
print(work(pins, screen_length))