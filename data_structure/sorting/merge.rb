def merge(arr, left, mid, right)
  sorted_arr = [0] * right;
  p = left
  q = mid+1
  k = left

  while p <= mid and q <= right
    if arr[p] < arr[q]
      sorted_arr[k] = arr[p]
      p += 1
    else
      sorted_arr[k] = arr[q]
      q += 1
    end
    k += 1
  end

  while p <= mid
    sorted_arr[k] = arr[p];
    p += 1
    k += 1
  end

  for i in (left...k) do 
    arr[i]  = sorted_arr[i] 
  end
end

def merge_sort (arr, left, right)
  mid = 0
  if left < right
    mid = left + (right - left) / 2;
    merge_sort(arr, left, mid)
    merge_sort(arr, mid+1, right)
    merge(arr, left, mid, right)
  end
end

size = 10
bound = 100

a = Array.new(size) { rand(bound) }
p a
merge_sort(a, 0, size-1)
p a
