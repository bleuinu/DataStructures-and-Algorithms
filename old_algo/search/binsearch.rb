def binarySearch arr, val, low, high
    mid = low + (high - low) / 2

    return -1 if low > high

    if arr[mid] == val
        return mid
    elsif arr[mid] < val
        binarySearch(arr, val, low + 1, high)
    else
        binarySearch(arr, val, low, mid - 1)
    end
end

def printTable arr
    0.upto(arr.size-1) do |i|
        printf "%3d ", arr[i]
        
        puts if (i+1) % 10 == 0
    end
    puts
end

def init
    size = 100
    arr = [0] * 100

    0.upto(size-1) do |i|
        arr[i] = rand(1 .. size * 2)
    end

    arr.sort!
    val = rand(size * 2) + 1

    return arr, val
end

arr, val = init

printTable arr
puts "#{val} found at index #{binarySearch(arr, val, 0, arr.size-1)}"
