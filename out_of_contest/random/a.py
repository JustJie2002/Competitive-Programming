class UnionFind:
    def __init__(self,size,start):
        self.parent=[-1]*size
        self.sz=[1]*size
        self.parent[start]=-2

    def unite(self,x,y):
        px=self.find(x)
        py=self.find(y)
        if px==py:
            return
        if self.sz[px]>self.sz[py]:
            if self.parent[py]==-2:
                self.parent[px]=-2
            self.parent[py]=px
            self.sz[px]+=self.sz[py]

            return px
        else:
            if self.parent[px]==-2:
                self.parent[py]=-2            
            self.parent[px]=py
            self.sz[py]+=self.sz[px]

            return py
        
    def isReachable(self,x):
        return self.parent[self.find(x)]==-2
    
    def find(self,x):
        if self.parent[x]<0:
            return x
        self.parent[x]=self.find(self.parent[x])
        return self.parent[x]

def addEdge(u,v,arr):
    arr[u]=True
    arr[v]=True

def main():
    n,m,r,b,y=map(int,input().split())
    red=UnionFind(n,r-1)
    blue=UnionFind(n,b-1)
    yellow=UnionFind(n,y-1)
    specialEdges=set()
    o=[red, yellow]
    g=[yellow, blue]
    p=[red, blue]
    reds=[False]*n
    blues=[False]*n
    yellows=[False]*n

    def getArrays(color):
        if color=='O':
            return o
        elif color=='P':
            return p
        return g
    
    def canReach(node,color):
        arr=getArrays(color)
        return arr[0].isReachable(node) and arr[1].isReachable(node)
    
    for i in range(m):
        u,v,c=input().split()
        u,v=int(u)-1,int(v)-1
        if c=='X':
            red.unite(u,v)
            blue.unite(u,v)
            yellow.unite(u,v)
        elif c=='R':
            red.unite(u,v)
            addEdge(u,v,reds)
        elif c=='B':
            blue.unite(u,v)
            addEdge(u,v,blues)
            
        elif c=='Y':
            yellow.unite(u,v)
            addEdge(u,v,yellows)
        else:
            specialEdges.add((u,v,c))

    while len(specialEdges)>0:
        toRemove=[]
        for edge in specialEdges:
            u,v,c=edge
            if canReach(u,c):
                arr=getArrays(c)
                arr[0].unite(u,v)
                arr[1].unite(u,v)
                toRemove.append(edge)
            elif canReach(v,c):
                arr=getArrays(c)
                arr[0].unite(u,v)
                arr[1].unite(u,v)
                toRemove.append(edge)
        if len(toRemove)==0:
            break
        for edge in toRemove:
            specialEdges.remove(edge)

    if len(specialEdges)==0:
        for i in range(n):
            if reds[i] and not red.isReachable(i):
                print(0)
                exit()
            elif blues[i] and not blue.isReachable(i):
                print(0)
                exit()
            elif yellows[i] and not yellow.isReachable(i):
                print(0)
                exit()
        print(1)
    else:
        print(0)

if __name__=="__main__":
    main()