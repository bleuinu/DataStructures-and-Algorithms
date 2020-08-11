def merge(arr, l, m, r)
  sorted_arr = [0]*r
  p = l
  q = m+1
  k = l

  while (p <= m and q <= r)
    if arr[p] < arr[q]
      sorted_arr[k] = arr[p];
      p += 1
    else
      sorted_arr[k] = arr[q]
      q += 1
    end
    k += 1
  end

  while p <= m
    sorted_arr[k] = arr[p];
    p += 1
    k += 1
  end

  for i in (l...k) do
    arr[i] = sorted_arr[i]
  end

  arr
end

def merge_sort(arr, l, r)
  mid = 0
  if(l < r)
    mid = l + (r-l)/2
    merge_sort(arr, l, mid)
    merge_sort(arr, mid+1, r)
    merge(arr, l, mid, r)
  end
end

arr = [1, 9, 7, 10, 8, 2, 51]
size = arr.size

p arr

 merge_sort(arr, 0, size-1)

p arr


