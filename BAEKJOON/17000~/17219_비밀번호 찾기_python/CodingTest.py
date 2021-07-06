import string
import sys

input = sys.stdin.readline

#n, m = map(int, input().split())
#k = input().rstrip()

password_size, answer_size = map(int, input().split())
passwords = {}
for _ in range(password_size):
    url, password = map(str, input().split())
    passwords[url] = password

for _ in range(answer_size):
    url = input().rstrip()
    print(passwords[url])