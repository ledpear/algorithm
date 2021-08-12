import string
import sys

def solution(scores):
    answer = ''
    size = len(scores)
    
    for scoreIndex in range(size):
        nowStudentScore = scores[scoreIndex][scoreIndex]
        scoreSize = size
        isMax = True
        isMin = True
        isUnique = True
        
        sumScore = 0
        for studentIndex in range(size):
            sumScore += scores[studentIndex][scoreIndex]
            if isUnique:
                if nowStudentScore < scores[studentIndex][scoreIndex]:
                    isMax = False
                elif nowStudentScore > scores[studentIndex][scoreIndex]:
                    isMin = False
                elif scoreIndex != studentIndex and nowStudentScore == scores[studentIndex][scoreIndex]:
                    isUnique = False
        
        if (isMax and isUnique) or (isMin and isUnique):
            sumScore -= nowStudentScore
            scoreSize -= 1
            
        avgScore = sumScore / scoreSize
        
        if avgScore >= 90:
            answer += 'A'
        elif avgScore >= 80:
            answer += 'B'
        elif avgScore >= 70:
            answer += 'C'
        elif avgScore >= 50:
            answer += 'D'
        else:
            answer += 'F'
    
    return answer

print(solution([[100,90,98,88,65],[50,45,99,85,77],[47,88,95,80,67],[61,57,100,80,65],[24,90,94,75,65]]))