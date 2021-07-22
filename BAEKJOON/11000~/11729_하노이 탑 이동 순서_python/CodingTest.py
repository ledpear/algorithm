import string
import sys
from copy import deepcopy

input = sys.stdin.readline

size = int(input().rstrip())
rods = [[] for _ in range(3)]
rods[0] = list(range(1,size + 1))
rods[0].reverse()
rodSet = {}
routes = []
answerRoutes = []
minRoute = 0
bitmask = ['1'] * size
for _ in range(size * 2):
    bitmask += ['0']

rodSet[''.join(bitmask)] = 0

def BT():        
    global answerRoutes

    if len(rods[0]) == 0 and len(rods[1]) == 0:
        if answerRoutes:
            if len(answerRoutes) > len(routes):
                answerRoutes = deepcopy(routes)
        else:
            answerRoutes = deepcopy(routes)        
        return

    for index in range(3):
        if rods[index]:
            for target in range(3):
                if index == target:
                    continue
                
                if ((rods[target] and rods[target][-1] > rods[index][-1]) or not rods[target]):
                    #비트마스크 변환
                    bitmask[size*index + rods[index][-1]-1] = '0'
                    bitmask[size*target + rods[index][-1]-1] = '1'
                    if ''.join(bitmask) not in rodSet:
                        #비트마스크 dict 삽입
                        rodSet[''.join(bitmask)] = 0
                        #이동
                        rods[target].append(rods[index].pop())
                        routes.append(str(index + 1) + ' ' + str(target + 1))
                        BT()
                        #이동 복원
                        rods[index].append(rods[target].pop())
                        routes.pop()
                        #비트마스크 dict 제거
                        del(rodSet[''.join(bitmask)])
                    #비트마스크 복원
                    bitmask[size*index + rods[index][-1]-1] = '1'
                    bitmask[size*target + rods[index][-1]-1] = '0'
                    

BT()

for route in answerRoutes:
    print(route)