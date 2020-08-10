# https://mygumi.tistory.com/308

def partition(arr, left, right)
  mid = left + (right - left) / 2;
  pivot = arr[mid]
  i = left
  j = right

  while i<j
     while arr[j] > pivot
       j -= 1
     end

     while i<j and arr[i] <= pivot
       i += 1
     end

     arr[i], arr[j] = arr[j], arr[i]
  end

  arr[left] = arr[i]
  arr[j] = pivot
  i
end

def quicksort (arr, left, right)
  return if left >= right

  pivot = partition(arr, left, right)

  quicksort(arr, left, pivot - 1)
  quicksort(arr, pivot + 1, right)
end

size = 10
bound = 100

a = Array.new(size) { rand(bound) }
p a
quicksort(a, 0, size-1)
p a
