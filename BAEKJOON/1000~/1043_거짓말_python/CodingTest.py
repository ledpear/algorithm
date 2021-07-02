import string
import sys
import collections

input = sys.stdin.readline

people_size, party_size = map(int, input().split())
know_people = list(map(int, input().split()))
answer = party_size

edges = [set() for _ in range(people_size + 1)]
party_history = []

for party in range(party_size):
    party_people = list(map(int, input().split()))

    party_people_size = party_people[0]
    if party_people_size == 0:
        continue
    else:
        party_people.pop(0)

    party_history.append(party_people)

    for i in range(party_people_size):
        for j in range(i + 1, party_people_size):
            if i == j:
                continue
            edges[party_people[i]].add(party_people[j])
            edges[party_people[j]].add(party_people[i])

peoples = [False] * (people_size + 1)

for know in know_people[1:]:
    if peoples[know]:
        continue

    queue = collections.deque()
    queue.append(know)
    peoples[know] = True
    while queue:
        now = queue.popleft()
        for edge in edges[now]:
            if not peoples[edge]:
                peoples[edge] = True
                queue.append(edge)

for party_member in party_history:
    for member in party_member:
        if peoples[member]:
            answer -= 1
            break

print(answer)