import string
import sys

input = sys.stdin.readline

def getIndex(alphabet):
    return string.ascii_uppercase.index(alphabet)

def DFS(node, edges, discovered, finished, findCnt):

    findCnt += 1
    discovered[getIndex(node)] = findCnt

    if node in edges:
        for edge in edges[node]:
            if discovered[getIndex(edge)] == 0:
                DFS(edge, edges, discovered, finished, findCnt)
            elif discovered[getIndex(node)] >= discovered[getIndex(edge)] and not finished[getIndex(edge)]:
                print(node + edge)

    finished[getIndex(node)] = True    

def solution(s):
    edges = {}

    discovered = [0] * len(string.ascii_uppercase)
    finished = [False] * len(string.ascii_uppercase)
    findCnt = 0

    for iter in s:
        start, end = iter
        if start in edges:
            edges[start].append(end)
        else:
            edges[start] = [end]

    for node in edges:
        if not discovered[getIndex(node)]:
            DFS(node, edges, discovered, finished, findCnt)