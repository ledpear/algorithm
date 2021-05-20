from collections import deque
from functools import lru_cache

class cache:
    size = 0
    cache_list = []

    def __init__(self, size):
        self.size = size

    def hit(self, target):
        find = False
        target = target.lower()

        if target in self.cache_list:
            self.cache_list.pop(self.cache_list.index(target))
            self.cache_list.append(target)
            find = True
        else:
            if len(self.cache_list) >= self.size:
                self.cache_list.pop(0)
                self.cache_list.append(target)
            else:
                self.cache_list.append(target)

        return find

def solution(cacheSize, cities):
    answer = 0

    cache_LRU = cache(cacheSize)

    for iter in cities:
        if cache_LRU.hit(iter):
            answer += 1
        else:
            answer += 5

    return answer

#print(solution(3, ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"]))
print(solution(3, 	["Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"]))