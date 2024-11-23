import datetime as dt

def convert(time):
    return time.hour * 60 * 60 + time.minute * 60 + time.second

def work(evts, days, market_open, market_close):
    n = len(days)

    when_open = convert(market_open)
    when_done = convert(market_close)
    duration = when_done - when_open

    def datetime_to_date(date_time):
        return dt.date(date_time.year, date_time.month, date_time.day)
    
    def datetime_to_time(date_time):
        time = dt.time(date_time.hour, date_time.minute, date_time.second)
        return convert(time)

    def find_lower(start):
        lo, hi = 0, n - 1
        while lo < hi:
            mid = (lo + hi) // 2
            if days[mid] >= start:
                hi = mid
            else:
                lo = mid + 1
        return hi
    
    def find_upper(end):
        lo, hi = 0, n - 1
        while lo < hi:
            mid = (lo + hi + 1) // 2
            if days[mid] <= end:
                lo = mid
            else:
                hi = mid - 1
        return lo

    ans = []
    for start, end in evts:
        start_date = datetime_to_date(start)
        end_date = datetime_to_date(end)
        i = find_lower(start_date)
        j = find_upper(end_date)
        if i > j:
            ans.append(0)
            continue

        res = 0
        if start_date == days[i]:
            if i == j:
                L = max(datetime_to_time(start), when_open)
                R = min(datetime_to_time(end), when_done)
                res = max(0, R - L)
            else:
                L = max(datetime_to_time(start), when_open)
                R = when_done
                res = max(0, R - L)
                i += 1
                if end_date == days[j]:
                    L = when_open
                    R = min(datetime_to_time(end), when_done)
                    res += max(0, R - L)
                    j -= 1
                if i <= j:
                    res += (j - i + 1) * duration
        else:
            if end_date == days[j]:
                L = when_open
                R = min(datetime_to_time(end), when_done)
                res += max(0, R - L)
                j -= 1
            if i <= j:
                res += (j - i + 1) * duration
        ans.append(res)
    
    return ans

events = [(dt.datetime(2024, 7, 1, 9, 30, 0), dt.datetime(2024, 7, 4, 16, 0, 0))]
good_days = [dt.date(2024, 7, 1), dt.date(2024, 7, 2), dt.date(2024, 7, 3)]
market_open_time = dt.time(10, 0)
market_close_time = dt.time(15, 0)
print(work(
    events,
    good_days,
    market_open_time,
    market_close_time
))