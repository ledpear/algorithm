import string
import sys

input = sys.stdin.readline

#사이트 주소와 비밀번호를 입력받아 dictionary에 저장
#질의하는 사이트주소에 맞는 비밀번호를 출력

password_size, answer_size = map(int, input().split())
passwords = {}
for _ in range(password_size):
    url, password = map(str, input().split())
    passwords[url] = password

for _ in range(answer_size):
    url = input().rstrip()
    print(passwords[url])