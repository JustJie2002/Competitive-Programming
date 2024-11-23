import math

center = None

class Point:
    def __init__(self,x,y):
        self.x=x
        self.y=y

r=0

def existsY(x,a):
    # return abs(x - center.x)<=abs(a)
    return pow(x - center.x, 2) / (a*a) <= 1
    # return (-b * math.sqrt(1 - pow(x - center.x, 2) / pow(a, 2)) + center.y) <= (b * math.sqrt(1 - pow(x - center.x, 2) / pow(a, 2)) + center.y)
    # return x
    # return -a<=2*(x - center.x)<=a

def existsX(y,b):
    # return (-a * math.sqrt(1 - pow(y - center.y, 2) / pow(b, 2)) + center.x) <= (a * math.sqrt(1 - pow(y - center.y, 2) / pow(b, 2)) + center.x)
    
    return pow(y - center.y, 2) / (b*b) <= 1
    # return -b<=2*(y- center.y)<=b

def dist(x1,x2,y1,y2):
    return math.sqrt((x2-x1)**2+(y2-y1)**2)

def bsearch(lo,hi,a,b,left=False,findingX=False):
    EPS = 10 ** -3
    if left: # low
        while abs(lo - hi) > EPS:
            mid = (lo + hi) / 2
            if findingX:
                print(mid)
                x=mid
                # print(x)
                if existsY(x,a):
                    hi=mid
                else:
                    lo=mid
            else:
                y=mid
                if existsX(y,b):
                    hi=mid
                else:
                    lo=mid

    else:
        while abs(lo - hi) > EPS:
            mid = (lo + hi) / 2
            if findingX:
                x=mid
                if existsY(x,a):
                    # if lo==mid:
                    #     return mid
                    lo=mid
                else:
                    hi=mid
            else:
                y=mid
                if existsX(y,b):
                    # if lo==mid:
                    #     return mid
                    lo=mid
                else:
                    hi=mid
    return mid

x1,y1,x2,y2,a=map(int,input().split())
p1=Point(x1,y1)
p2=Point(x2,y2)
if x1 > x2 or (x1 == x2 and y1 < y2):
    p1, p2 = p2, p1

center = Point((p2.x + p1.x) / 2, (p2.y + p1.y) / 2)
# print(center.x, center.y)

d=dist(x1,x2,y1,y2)
n=(a-d)/2
b=math.sqrt(n*(n+d))
r=d+2*n
a /= 2
# print(d)
# print(n)
# print(b)

lowx=bsearch(-200,p1.x,a,b,left=True,findingX=True)
highx=bsearch(p1.x,200,a,b,left=False,findingX=True)
lowy=bsearch(-200,p1.y,a,b,left=True,findingX=False)
highy=bsearch(p1.y,200,a,b,left=False,findingX=False)

print(lowx, lowy, highx, highy)