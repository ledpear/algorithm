import string
import sys

sys.setrecursionlimit(10**9)
input = sys.stdin.readline

def getSecond(time):
    return int(time[0:2]) * 60 + int(time[3:])

def getMelodyList(melodys):
    melody = melodys[0]
    melodylist = []

    for idx in range(1, len(melodys)):
        if melodys[idx] != '#':
            melodylist.append(melody)
            melody = melodys[idx]
        else:
            melody = melody.lower()

    melodylist.append(melody)

    return melodylist


def solution(m, musicinfos):
    #musicinfos 파싱
    musicInfoList = []
    for musicInfo in musicinfos:
        musicInfo = musicInfo.split(',')
        tempList = []
        #재생시간 추가
        startTime = getSecond(musicInfo[0])
        endTime = getSecond(musicInfo[1])
        runningTime = endTime - startTime
        tempList.append(runningTime)
        #노래 제목 추가
        tempList.append(musicInfo[2])
        #멜로디 리스트 추가
        tempList.append(getMelodyList(musicInfo[3]))
        musicInfoList.append(tempList)

    #일치하는 멜로디가 있는지 확인
    
    
    #확인할 때 노래의 멜로디가 끝나면 처음으로 돌아가 다시 비교한다
    #일치하는 노래가 여러개면 가장 킨 노래제목을 반환
    answer = '(None)'
    maxPlayTime = 0
    for playTime, name, musicMelody in musicInfoList:
        if maxPlayTime >= playTime:
            continue

        totalMusicMelody = []
        for idx in range(playTime):
            melodyIdx = idx % len(musicMelody)
            totalMusicMelody.append(musicMelody[melodyIdx])

        totalMusicMelodyStr = ''.join(totalMusicMelody)

        if ''.join(getMelodyList(m)) in totalMusicMelodyStr:
            maxPlayTime = playTime
            answer = name                

    return answer

print(solution("ABCDEFG", ["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
print(solution("CC#BCC#BCC#BCC#B", ["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]))
print(solution("ABC", ["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]))