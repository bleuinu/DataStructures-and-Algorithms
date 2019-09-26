def partition(arr, low, high):
	pivot = arr[high]
	index = low-1

	for j in range(low, high):
		if arr[j] <= pivot:
			index += 1

			arr[index], arr[j] = arr[j], arr[index]

	arr[index+1], arr[high] = arr[high], arr[index+1]

	return index+1

def quicksort(arr, low, high):
	if(low < high):
		pi = partition(arr, low, high)

		quicksort(arr, low, pi-1)
		quicksort(arr, pi+1, high)

arr = [56, 24, 10, 35, 72, 13, 99, 100, 42, 56]
print(arr)

quicksort(arr, 0, len(arr)-1)

print(arr)
