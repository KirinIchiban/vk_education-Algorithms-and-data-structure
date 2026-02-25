k = int(input())    
str = (input().split(' '))
elem = input()
arr = []

for i in str:
    if i != elem:
        arr.append(i)

print(*arr)