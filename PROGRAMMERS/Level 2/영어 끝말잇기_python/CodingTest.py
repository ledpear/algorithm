def solution(n, words):
    answer = []

    s = set()
    player = [0] * n
    index = 0
    
    end_c = words[0][0]
    
    for word in words:
        player_num = index % n
        player[player_num] += 1
        
        if end_c == word[0]:
            if word not in s:
                s.add(word)
            else:
                return [player_num + 1, player[player_num]]
        else:
            return [player_num + 1, player[player_num]]

        end_c = word[-1]
        index += 1
        
    return [0,0]