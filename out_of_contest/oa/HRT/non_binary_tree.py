"""
author : Jie Chen (4th Year CS)
school : Rochester Institute of Technology
created: 09.06.2024 19:41:57
"""
from collections import defaultdict

class Node:
    def __init__(self):
        self.key = -1
        self.val = -1
        self.children = []

def construct(args):
    argc = len(args)
    is_root = [True] * argc
    nodes = [Node() for _ in range(argc)]
    for i, arg in enumerate(args):
        nodes[i].key = arg[0]
        nodes[i].val = arg[1]
        children = arg[2:]
        for x in children:
            is_root[x] = False
            nodes[i].children.append(nodes[x])

    root = -1
    for i in range(argc):
        if is_root[i]:
            root = i
    return nodes[root]

def merge(curL, curR):
    node = Node()
    node.key = curL.key
    node.val = curR.val
    seen = dict()
    for i, child_node in enumerate(curL.children):
        seen[child_node.key] = i
        node.children.append(child_node)
    for child_node in curR.children:
        if child_node.key not in seen:
            node.children.append(child_node)
        else:
            pos = seen[child_node.key]
            merged_node = merge(node.children[pos], child_node)
            node.children[pos] = merged_node
    return node

def work(L, R):
    graphL = construct(L)
    graphR = construct(R)

    if graphL.key != graphR.key:
        return []
    
    merged_graph = merge(graphL, graphR)

    answer = []
    def traverse(cur):
        answer.append(cur.key)
        answer.append(cur.val)
        for child in cur.children:
            traverse(child)

    traverse(merged_graph)
    return answer

L = [
    [1, 15, 1, 2, 3],
    [6, 3],
    [1, 0, 4],
    [4, 3],
    [2, 3]
]

R = [
    [1, 16, 1, 2, 3, 4],
    [6, 3],
    [1, 0, 5, 6, 7],
    [4, 2],
    [0, 8, 8],
    [2, 5],
    [3, 6],
    [6, 7],
    [9, 1]
]
print(work(L, R))
