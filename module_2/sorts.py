# binary search
def binsearch(v, target):
    left, right = 0, len(v)
    while left <= right:
        middle = left + (right - left)//2
        if v[middle] == target:
            return middle
        if v[middle] > target:
            right = middle - 1
        else:
            left = middle + 1       


# сортировка выбором
def selectionSort(arr):
    len = len(arr)
    for i in range(len - 1):
        min = i
        j = i + 1
        for j in range (len):
            if arr[i]<arr[min]:
                min = j
        arr[i], arr[min] = arr[min], arr[i]
    return arr


# сортировка вставкой
def insertionSort(arr):
    for i in range(1, len(arr)):
        j = i
        while j > 0:
            if arr[j] < arr[j-1]:
                arr[j], arr[j-1] = arr[j-1], arr[j]
            j -= 1
    return arr


# сортировка пузырьком
def bubbleSort(arr):
    is_sorted = False
    while not(is_sorted):
        is_sorted = True
        for i in range(len(arr)-1):
            if arr[i] > arr[i+1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]
                is_sorted = False
