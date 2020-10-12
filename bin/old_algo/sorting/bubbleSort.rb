def bubble_sort(arr)
  n = arr.size
  for i in (0 ... n)
    isSwapped = false

    for j in (0 ... n - i - 1)
      if arr[j] > arr[j+1]
        isSwapped = true
        arr[j], arr[j+1] = arr[j+1], arr[j]
      end
    end
    if isSwapped == false
      break
    end
  end

  arr
end

arr = [*1 ... 100].shuffle

print arr
puts

bubble_sort(arr)

print arr
puts
