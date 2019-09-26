def selection_sort(arr)
    n = arr.size

    for i in (0 ... n - 1)
        min = i

        for j in (i+1 ... n)
            if arr[j] < arr[min]
                min = j
            end
        end

        arr[i], arr[min] = arr[min], arr[i]
    end
end

arr = [*1 ... 100].shuffle

print arr
puts

selection_sort(arr)

print arr
puts
