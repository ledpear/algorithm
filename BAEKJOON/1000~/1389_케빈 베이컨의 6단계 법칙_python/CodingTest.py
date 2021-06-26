import string
import sys

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

INF = int(1e9)
node_size, edge_size = map(int, input().split())

#edges = [[] for _ in range(node_size + 1)]
matrix = [[INF] * (node_size) for _ in range(node_size)]
for _ in range(edge_size):
    nodeA, nodeB = map(int, input().split())
    #edges[nodeA].append(nodeB)
    #edges[nodeB].append(nodeA)

    nodeA -= 1
    nodeB -= 1

    matrix[nodeA][nodeB] = 1
    matrix[nodeB][nodeA] = 1



def floyd_warshall(matrix, size):
    for k in range(size):
        for i in range(size):
            for j in range(size):
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j])

floyd_warshall(matrix, node_size)

min_val = INF
min_node = 0

for node in range(node_size):
    sum_val = sum(matrix[node])
    if min_val > sum_val:
        min_val = sum_val
        min_node = node + 1

print(min_node)