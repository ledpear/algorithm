from itertools import combinations

def solution(relation):
    columnSize = len(relation[0])
    CandidateKeys = []
    answer = 0
    columnIdx = [i for i in range(columnSize)]

    for size in range(1, columnSize + 1):
        columnCombis = combinations(columnIdx, size)
        nowSet = set()
        isCandidateKey = True

        for columnCombi in columnCombis:
            # 최소성 확인
            minimal = True
            for CandidateCol in CandidateKeys:
                including = True
                for col in CandidateCol:
                    if col not in columnCombi:
                        including = False
                        break

                if including:
                    minimal = False
                    break

            #최소성을 만족하지 못하면 건너 뛴다
            if not minimal:
                continue

            nowSet = set()
            isCandidateKey = True
            for row in relation:
                nowVal = ""
                for idx in columnCombi:
                    nowVal += ',' + row[idx]

                if nowVal in nowSet:
                    isCandidateKey = False
                    break
                else:
                    nowSet.add(nowVal)

            if isCandidateKey:
                answer += 1
                CandidateKeys.append(columnCombi)

    return answer

print(solution([["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]]))