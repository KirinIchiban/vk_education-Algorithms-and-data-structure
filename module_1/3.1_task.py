arr = []
k = int(input())

for i in (l:= input().split()):
    arr.append(int(i))
x = 0
while x < k:
    if (arr[x] == 0):
        temp = x
        while(temp < k - 1):
            arr[temp], arr[temp+1] = arr[temp+1], arr[temp]
            temp += 1  
        k -= 1
    else:
        x += 1

print(*[p for p in arr])
