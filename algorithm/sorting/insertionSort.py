def insertionSort(arr, n):
	for i in range(1, n):
		index = i
		key = arr[i]

		while index > 0 and key < arr[index-1]:
			arr[index] = arr[index-1]
			index = index - 1

		arr[index] = key

arr = [56, 24, 10, 35, 72]

print(arr)

insertionSort(arr, len(arr))

print(arr)
