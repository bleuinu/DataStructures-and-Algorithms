def merge(arr, left, mid, right):
	L = left
	R = mid+1
	K = left
	temp = [0]*(right+1)

	while L <= mid and R <= right:
		if arr[L] < arr[R]:
			temp[K] = arr[L]
			L += 1
		else:
			temp[K] = arr[R]
			R += 1
		K += 1

	while L <= mid:
		temp[K] = arr[L]
		L += 1
		K += 1

	for i in range (left, K):
		arr[i] = temp[i]

def mergeSort(arr, left, right):
	if left < right:
		mid = left + (right - left) / 2
		
		mergeSort(arr, left, mid)
		mergeSort(arr, mid+1, right)
		merge(arr, left, mid, right)

arr = [56, 24, 10, 35, 72, 0, 2, 29, 100]

print(arr)

mergeSort(arr, 0, len(arr)-1)

print(arr)
