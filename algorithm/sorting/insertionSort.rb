def insertion_sort(arr)
  n = arr.size

  for i in (1 ... n)
    index = i
    key = arr[i]

    while index > 0 and key < arr[index-1]
      arr[index] = arr[index - 1]
      index -= 1
    end

    arr[index] = key
  end
end

arr = [*1 ... 100].shuffle

print arr
puts

insertion_sort(arr)

print arr
puts
