str = input()
str_list = list(str)
str_list.reverse()
arr = []

temp = ""
for i in str_list:
    temp = i + temp 
    arr.append(temp)

arr.sort()

for i in arr:
    print(i)